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
nodes={};
for i=1:nodos
    nodo=struct('N_nodo',0,'coord',[0,0],'carga',[0,0],'restriccion',["",""],'des_restr',[0,0],'desplazamiento',[0,0],'indice',[0,0],'condicion_borde',[0,0]);
    nodo.N_nodo=i;
    nodo.coord=cord(i,:);
    nodo.carga=f(i,:);
    nodo.restriccion=grados_lib(i,:);
    nodo.indice=[nDof_nudo*nodo.N_nodo-1,nDof_nudo*nodo.N_nodo];
    nodo.condicion_borde(nodo.restriccion~="r")=0;
    nodo.condicion_borde(nodo.restriccion=="r")=1;
    nodes=[nodes,nodo];
end
nodes=nodes';

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
elemento={};
for i=1:barra
   barra=struct('nodo_i',[],'nodo_f',[],'Sm',[],'Sj',[],'T',[],'L',0,'alpha',0,'Dj',[],'Aj',[],'Dm',[],'Am',[]);
   barra.nodo_i=nodes{cordn(i,1)}.coord;
   barra.nodo_f=nodes{cordn(i,2)}.coord;
   vector = barra.nodo_f-barra.nodo_i;
   barra.L=(vector(1,2)^2+vector(1,1)^2)^0.5;
   barra.alpha=atan2d(vector(1,2),vector(1,1));
   %barra.indice=[nodes{cordn(i,1)}.indice,nodes{cordn(i,2)}.indice];
   barra.Sm=E*A/barra.L*[1 -1;-1  1];
   c=cosd(barra.alpha);
   s=sind(barra.alpha);
   barra.Sj=E*A/barra.L*[c^2  c*s   -c^2 -c*s;c*s  s^2   -c*s -s^2; -c^2 -c*s    c^2  c*s;-c*s -s^2    c*s  s^2];
   barra.T=[c s 0 0;0 0 c s];
                             
elemento=[elemento,barra];
end
elemento=elemento';
%Calculo de la matriz de rigidez global 
[numero_nodos,~]=size(nodes);
[numero_barras,~]=size(elemento);
tamnio_matriz=numero_nodos*nDof_nudo;

M_rigidez_global=zeros(tamnio_matriz);

for i=1:numero_barras
    temp=elemento{i}.Sj;
    index=[nodes{cordn(i,1)}.indice,nodes{cordn(i,2)}.indice];
    M_rigidez_global(index,index)=M_rigidez_global(index,index)+temp;
end
% indices requeridos para identificar los grados de
% libertad libres y los grados de libertada restringidos
% vector de cargas 
% vector de desplazamiento de los apoyos para el calculo de
% los desplazamientos del sistema

indice_global=zeros(1,tamnio_matriz);
indice_restriccion=zeros(1,tamnio_matriz);
A_J_CARGA=zeros(tamnio_matriz,1);
Des_restrin=zeros(tamnio_matriz,1);

for i=1:numero_nodos
    indice_global(1,nDof_nudo*i-1:nDof_nudo*i)=[nDof_nudo*i-1,nDof_nudo*i];
    indice_restriccion(1,nDof_nudo*i-1:nDof_nudo*i)=nodes{i}.condicion_borde;
    A_J_CARGA(nDof_nudo*i-1:nDof_nudo*i,1)=nodes{i}.carga';
    Des_restrin(nDof_nudo*i-1:nDof_nudo*i,1)=nodes{i}.des_restr';
end

% indices correspondientes a los nudos libres
indice_free=[];
j=1;
for i=1:length(indice_restriccion)
   if indice_restriccion(i) == 0
       indice_free(j)=i;
       j=j+1;
   end
end
inidice_libre=indice_global(indice_free);

% indices correspondeinetes a los nudos restringidos
indice_nofree=[];
j=1;
for i=1:length(indice_restriccion)
   if indice_restriccion(i) == 1
       indice_nofree(j)=i;
       j=j+1;
   end
end
indice_restrin=indice_global(indice_nofree);
% matriz Sff
S_f_f=M_rigidez_global(inidice_libre,inidice_libre);
S_f_r=M_rigidez_global(inidice_libre,indice_restrin);

%vector de carga de los nudos libres
Af=A_J_CARGA(inidice_libre');

%vector de desplazamientos para los nudos restringidos
Dr=Des_restrin(indice_restrin');

%sistema de ecuaciones para los delsplazamientos
Df=S_f_f^-1*(Af-S_f_r*Dr);

%vector de desplazamiento de los nudos
Dj=zeros(tamnio_matriz,1);
Dj(inidice_libre')=Df;
Dj(indice_restrin')=Des_restrin(indice_restrin');

%acciones de nudos
reacciones=M_rigidez_global*Dj

%resultados a las barras
for i=1:numero_barras
    elemento{i}.Dj=Dj([nodes{cordn(i,1)}.indice,nodes{cordn(i,2)}.indice]);
    %desplazamientos locales
    elemento{i}.Dm=elemento{i}.T*elemento{i}.Dj;
    %fuerzas locales
    elemento{i}.Am=elemento{i}.Sm*elemento{i}.Dm;
    %fuerzas de nudos
    elemento{i}.Aj=elemento{i}.T'*elemento{i}.Am;
end
%desplazamientos de nudos
for i=1:numero_nodos
    nodes{i}.desplazamiento=Dj(nodes{i}.indice');
end


factor_escala=50; % Factor de escala para el dibujo
delta=1; % Offset para el dibujo
figure
hold on
for i=1:numero_barras
    plot([elemento{i}.nodo_i(1,1),elemento{i}.nodo_f(1,1)],[elemento{i}.nodo_i(1,2),elemento{i}.nodo_f(1,2)],'.r','MarkerSize',15,'Color','k','LineWidth',1,'LineStyle','--')
    plot([elemento{i}.nodo_i(1,1)+elemento{i}.Dj(1,1)*factor_escala,elemento{i}.nodo_f(1,1)+elemento{i}.Dj(3,1)*factor_escala],[elemento{i}.nodo_i(1,2)+elemento{i}.Dj(2,1)*factor_escala,elemento{i}.nodo_f(1,2)+elemento{i}.Dj(4,1)*factor_escala],'.r','MarkerSize',15,'Color','k','LineWidth',1.5,'LineStyle','-')
end

grid on

