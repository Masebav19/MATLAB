function [Aj]= carga_distri(L)
Aj=zeros(6,1);
%Aj 6x1
%primera fila Rnix(1)
%segunda fila Rniy(2)
%tercera fila Mni(3)
%cuarta fila Rnfx(4)
%quinta fila Rnfy(5)
%sexta fila Mnf(6)
    n=input("Ingrese el tipo de carga distribuido mediante un número del 1 al 8: ");
    switch n
        case 1
           [P,a,b]=input("Ingrese el valor de la carga y los valores de a y b entre corchetes y separados por comas: ");
           Aj(3,1)= P*a*b^2/L^2;
           Aj(2,1)=(P*b^2/L^3)*(3*a+b);
           Aj(6,1)= -P*a^2*b/L^2;
           Aj(5,1)=(P*a^2/L^3)*(a+3*b);
        case 2
           [P,a,b]=input("Ingrese el valor de la momento y los valores de a y b entre corchetes y separados por comas: ");
           Aj(2,1)= (P*b/L^2)*(2*a-b);
           Aj(3,1)=6*P*a*b/L^3;
           Aj(5,1)= (P*a/L^2)*(2*b-a);
           Aj(6,1)=-Aj(2,1);
        case 3
           [P,a,b]=input("Ingrese el valor de la carga y los valores de a y b entre corchetes y separados por comas: ");
           Aj(1,1)= -P*b/L;
           Aj(4,1)=-P*a/L;
        case 4
           [P,a,b]=input("Ingrese el valor de la carga y los valores de a y b entre corchetes y separados por comas: ");
           Aj(1,1)=-P*b/L;
           Aj(4,1)=-P*a/L;
        case 5
           [P,a]=input("Ingrese el valor de la carga y el valor de a entre corchetes y separados por comas: ");
           Aj(2,1)= P;
           Aj(3,1)=(P*a/L)*(L-a);
           Aj(5,1)= Aj(2,1);
           Aj(6,1)=-Aj(3,1); 
        case 6
           P=input("Ingrese el valor de la carga: ");
           Aj(2,1)= P*L/2;
           Aj(3,1)= P*L^2/12;
           Aj(5,1)= Aj(2,1);
           Aj(6,1)=-Aj(3,1); 
        case 7
           [P,a]=input("Ingrese el valor de la carga y el valor de a entre corchetes y separados por comas: ");
           Aj(2,1)= (P*a/(2*L^3))*(2*L^3-2*a^2*L+a^3);
           Aj(3,1)=(P*a^2/(12*L^2))*(6*L^2-8*a*L+3*a^2);
           Aj(5,1)= (P*a^3/(2*L^3))*(2*L-a);
           Aj(6,1)=-(P*a^3/(12*L^2))*(4*L-3*a);  
        case 8
           P=input("Ingrese el valor de la carga: ");
           Aj(2,1)= 3*P*L/20;
           Aj(3,1)= P*L^2/30;
           Aj(5,1)= 7*P*L/20;
           Aj(6,1)=-P*L^2/30; 
    end
end