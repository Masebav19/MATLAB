clear
clc
R=100;%ohm
Vagua=1000/100^3;%m3
Sagua=1000;%Kg/m3
m=Sagua*Vagua;
c=1000;%cal/CKg
Kp=90;
Ki=2;
Kd=80;
A=[0 1 0;0 0 1;-20*Ki/(0.35*R*m*c) -20*Kp/(0.35*R*m*c) -(1/0.35)*(1+20*Kp/(R*m*c))];
B=[0;0;1];
C=[(57.1429*Ki/(R*m*c))*(1-20*Kp/(R*m*c)),(57.1429/(R*m*c))*(Kd+0.35*Ki-20*Kd*Kp/(R*m*c)) ...
   ,(57.1429/(R*m*c))*(0.35*Kp-20*Kp*Kd/(R*m*c))];
D=20*Kd/(R*m*c);
sys_1=ss(A,B,C,D);
[y,t,x]=step(30*sys_1);
figure
plot(t,y);
title('Respuesta del lazo realimentado');
xlabel('Tiempo [seg]')
ylabel('Temperatura [°C]')

figure
plot(t,x(:,2));
title('Gráfica del voltaje de entrada');
xlabel('Tiempo [seg]')
ylabel('Voltaje RMS [V]')