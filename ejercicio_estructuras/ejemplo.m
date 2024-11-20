% Calculo general de celocias
clc
clear variables

% Determinamos datos generales del modelo
E=200*10^9; %[Pa] - Acero
A=(8/100*8/100); %[m^2]
nDof_nudo=2; % Numero de grados de libertad por nudo

% Deteminamos los nudos
% Node2D(numero,coordenada,load,restrain)

% Pido ingresar el numero de nodos 
nodos = input('Ingrese el numero de nodos: ');
% creo una matriz de coordenadas de dos dimensiones para los nodos
cord = zeros(nodos,2);% eje X y Y
% Pido las coordenadas de cada nodo
for i=1:nodos
    msg=sprintf("Ingrese la coordenada del nodo %d: ",i);
    cord(i,:)=input(msg);
end
% creo una matriz de fuerzas de dos dimensiones para los nodos
f = zeros(nodos,2);
% Pido las coordenadas de cada nodo
for i=1:nodos
    msg=sprintf("Ingrese las fuerzas del nodo %d: ",i);
    f(i,:)=input(msg);
end

% creo una matriz de fuerzas de dos dimensiones para los nodos
grados_lib = string(zeros(nodos,2));
% Pido las coordenadas de cada nodo
for i=1:nodos
    msg=sprintf("Ingrese las restricciones del nodo %d: ",i);
    grados_lib(i,:)=input(msg);
end

%creo la variable nodes 
nodes=[];
for i=1:nodos
nodes=[nodes,Node2D(i,cord(i,:),f(i,:),grados_lib(i,:))];
end
nodes=nodes';
% Determinamos los elementos
% Barra2D(Name,E,A,node_j,node_k)

% Pido ingresar el numero de Barras 
barra = input('Ingrese el numero de barras: ');
%creo la variable cordn que es la direción de las barras de nodo inicial a
%final
cordn = zeros(barra,2);%nodo inicial y nodo final [i,f]
% Pido las dirección de cada barra
for i = 1:barra
   msg = sprintf("Ingrese el nodo inicial y final del la barra %d: ",i);
   cordn(i,:)=input(msg);
    
end
% creo la variable elements
elements=[];
for i=1:barra
    msg=sprintf("Barra %d",i);
elements=[elements,Barra2D(msg,E,A,nodes(cordn(i,1),1),nodes(cordn(i,2),1))];
end
elements=elements';
factor_escala=50; % Factor de escala para el dibujo
delta=1; % Offset para el dibujo

clear E A


%Calculos automaticos
% Determinamos parametros globales del analisis
numero_nudos=height(nodes);
numero_barras=height(elements);
nDof_sistema=numero_nudos*nDof_nudo;

% Ensamblamos la matriz de rigidez global de la estructra
Sj_sistema=zeros(nDof_sistema);

for i=1:numero_barras
    Sj_temp=elements(i,1).Sj;
    index=elements(i,1).index;
    Sj_sistema(index,index)=Sj_sistema(index,index)+Sj_temp;
end

clear i index Sj_temp

% Determinamos los indices requeridos para identificar los grados de
% libertad libres y los grados de libertada restringidos
% Adicionalmente ensamblamos el vector de cargas para la solucion de los
% desplazamientos
% Ensamblamos el vector de desplazamiento de los apoyos para el calculo de
% los desplazamientos del sistema

index_global=zeros(1,nDof_sistema);
index_restrain=zeros(1,nDof_sistema);
A_join_load=zeros(1,nDof_sistema);
D_restrain=zeros(1,nDof_sistema);

for i=1:numero_nudos
    index=nodes(i,1).index;
    boundary_condition=nodes(i,1).boundary_condition;
    index_global(index)=index;
    index_restrain(index)=boundary_condition;
    A_join_load(index)=nodes(i,1).load;
    D_restrain(index)=nodes(i,1).restrain_displacement;
end

A_join_load=A_join_load';
D_restrain=D_restrain';

clear node_temp index boundary_condition i

% Extraemos los indices correspondientes a los nudos libres
[~,idx]=find(index_restrain==0);
index_f=index_global(idx);

% Extraemos los indices correspondeinetes a los nudos restringidos
[~,idx]=find(index_restrain==1);
index_r=index_global(idx);

clear idx index_global

% Particionamos la matriz de rigidez del sistema
% Determinamos la matriz Sff
Sff=Sj_sistema(index_f,index_f);
Sfr=Sj_sistema(index_f,index_r);
Srf=Sj_sistema(index_r,index_f);
Srr=Sj_sistema(index_r,index_r);

% Determinamos el vector de carga de los nudos libres
Af=A_join_load(index_f');

% Determinamos el vector de desplazamientos para los nudos restringidos
Dr=D_restrain(index_r');

% Resolvemos el sistema de ecuaciones para los delsplazamientos
Df=Sff^-1*(Af-Sfr*Dr);

% Ensamblamos el vector de desplazamiento de los nudos
Dj=zeros(nDof_sistema,1);
Dj(index_f')=Df;
Dj(index_r')=D_restrain(index_r');

% Calculamos las acciones de nudos
Aj=Sj_sistema*Dj

%Rutina para almacenar los resultados a las barras
% Grabamos los resultados obtenidos en el objeto
for i=1:numero_barras
    elements(i,1).Dj=Dj(elements(i,1).index);
    % Calculo de desplazamientos locales
    elements(i,1).Dm=elements(i,1).T*elements(i,1).Dj;
    % Calculo de fuerzas locales
    elements(i,1).Am=elements(i,1).Sm*elements(i,1).Dm;
    % Calculo de fuerzas de nudos
    elements(i,1).Aj=elements(i,1).T'*elements(i,1).Am;
end


%Rutina para almacenar los desplazamientos de nudos
% Grabamos los deplazamientos de los nudos en el objeto
for i=1:numero_nudos
    nodes(i,1).desplazamiento=Dj(nodes(i,1).index');
end


%Rutina para graficar
% Ensamblamos un vector de coordenadas X y Y para dibujar

j=1;
X=zeros(1,numero_barras*2);
X_deformada=zeros(1,numero_barras*2);
Y=zeros(1,numero_barras*2);
Y_deformada=zeros(1,numero_barras*2);

figure
hold on
for i=1:numero_barras
    plot([elements(i,1).node_j.coordenada(1,1),elements(i,1).node_k.coordenada(1,1)],[elements(i,1).node_j.coordenada(1,2),elements(i,1).node_k.coordenada(1,2)],'.r','MarkerSize',15,'Color','k','LineWidth',1,'LineStyle','--')
    plot([elements(i,1).node_j.coordenada(1,1)+elements(i,1).Dj(1,1)*factor_escala,elements(i,1).node_k.coordenada(1,1)+elements(i,1).Dj(3,1)*factor_escala],[elements(i,1).node_j.coordenada(1,2)++elements(i,1).Dj(2,1)*factor_escala,elements(i,1).node_k.coordenada(1,2)+elements(i,1).Dj(4,1)*factor_escala],'.r','MarkerSize',15,'Color','k','LineWidth',1.5,'LineStyle','-')
    % Grabamos las coordenadas en una lista para obtener los maximos y
    % minimos para el dibujo
    X(1,j)=elements(i,1).node_j.coordenada(1,1);
    Y(1,j)=elements(i,1).node_j.coordenada(1,2);
    X_deformada(1,j)=elements(i,1).node_j.coordenada(1,1)+elements(i,1).Dj(1,1)*factor_escala;
    Y_deformada(1,j)=elements(i,1).node_j.coordenada(1,2)+elements(i,1).Dj(2,1)*factor_escala;
    j=j+1;
    X(1,j)=elements(i,1).node_k.coordenada(1,1);
    Y(1,j)=elements(i,1).node_k.coordenada(1,2);
    X_deformada(1,j)=elements(i,1).node_k.coordenada(1,1)+elements(i,1).Dj(3,1)*factor_escala;
    Y_deformada(1,j)=elements(i,1).node_k.coordenada(1,2)+elements(i,1).Dj(4,1)*factor_escala;
    j=j+1;
end

clear j i

grid on
axis([min(X)-delta,max(X)+delta,min(Y)-delta,max(Y)+delta])
title("Estructura")
daspect([1 1 1]) 
set(gcf,'Visible','on','position',[0 0 1920 1080])

clear X Y X_deformada Y_deformada