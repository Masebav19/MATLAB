%% Obtención de las corrientes mediante matrices
clear
clc
R1=250;
xl=i*2*pi*60*160e-3;
xc=-i/(2*pi*60*22e-6);
R2=320;
R3=330;
A=[R1+xl -R2-xc 0;0 R2+xc -R3;1 1 1]
B=[215*exp(i*30*pi/180);215*exp(i*-90*pi/180);0]
I=A^-1*B
fprintf("IA=%.2f|%.2f° [A]\nIB=%.2f|%.2f° [A]\nIC=%.2f|%.2f° [A]\n",abs(I(1)),angle(I(1))*180/pi...
    ,abs(I(2)),angle(I(2))*180/pi,abs(I(3)),angle(I(3))*180/pi);
%% Resolución por variables simbólicas
clear
R1=250;
xl=i*2*pi*60*160e-3;
xc=-i/(2*pi*60*22e-6);
R2=320;
R3=330;
VAB=215*exp(i*30*pi/180);
VBC=215*exp(i*-90*pi/180);
VCA=215*exp(i*150*pi/180);
syms IA IB IC;

eq1=IA*(R1+xl)-IB*(R2+xc)==VAB
eq2=IB*(R2+xc)-IC*R3==VBC
eq3=IA+IB+IC==0

I_sym=solve([eq1,eq2,eq3]);
I=[double(I_sym.IA),double(I_sym.IB),double(I_sym.IC)]
fprintf("IA=%.2f|%.2f° [A]\nIB=%.2f|%.2f° [A]\nIC=%.2f|%.2f° [A]\n\n",abs(I(1)),angle(I(1))*180/pi...
    ,abs(I(2)),angle(I(2))*180/pi,abs(I(3)),angle(I(3))*180/pi);

%% Obtención del resto de parámetros

VAB = I(1)*(R1+xl)-I(2)*(R2+xc);
fprintf("Voltaje de línea AB (Num complejo): %.2f %.2f j[V]\nVoltaje de línea AB (Phasor): %.2f|%.2f° [V]\n\n",...
    real(VAB),imag(VAB),abs(VAB),angle(VAB)*180/pi)
VBC = I(2)*(R2+xc)-I(3)*R3;
fprintf("Voltaje de línea BC (Num complejo): %.2f %.2f j[V]\nVoltaje de línea BC (Phasor): %.2f|%.2f° [V]\n\n",...
    real(VBC),imag(VBC),abs(VBC),angle(VBC)*180/pi)
VCA = I(3)*R3-I(1)*(R1+xl);
fprintf("Voltaje de línea CA (Num complejo): %.2f %.2f j[V]\nVoltaje de línea BC (Phasor): %.2f|%.2f° [V]\n\n",...
    real(VCA),imag(VCA),abs(VCA),angle(VCA)*180/pi)
%% Simulink
clear 
clc
out=sim("parte2.slx");

% Primer método
%Valores en tiempo
t=out.Vabc_1.Time;
Vabc=out.Vabc_1.Data;
Iabc=out.Iabc_1.Data;
%Valores en Fasor
Vabc_pha=out.Vabc_1_ph.data(end,1:3)./sqrt(2); %Valor RMS
angle_Vabc=out.Vabc_1_ph.data(end,4:6);
Iabc_pha=out.Iabc_1_ph.data(end,1:3)./sqrt(2); %Valor RMS
angle_Iabc=out.Iabc_1_ph.data(end,4:6);
%Impresión de los datos

fprintf("IA=%.2f|%.2f° [A]\nIB=%.2f|%.2f° [A]\nIC=%.2f|%.2f° [A]\n\n",abs(Iabc_pha(1)),angle_Iabc(1)...
    ,abs(Iabc_pha(2)),angle_Iabc(2),abs(Iabc_pha(3)),angle_Iabc(3));

fprintf("Voltaje de línea AB (Num complejo): %.2f %.2f j[V]\nVoltaje de línea AB (Phasor): %.2f|%.2f° [V]\n\n",...
    real(Vabc_pha(1)*exp(i*angle_Vabc(1)*pi/180)),imag(Vabc_pha(1)*exp(i*angle_Vabc(1)*pi/180)),abs(Vabc_pha(1)),angle_Vabc(1))

fprintf("Voltaje de línea BC (Num complejo): %.2f %.2f j[V]\nVoltaje de línea BC (Phasor): %.2f|%.2f° [V]\n\n",...
    real(Vabc_pha(2)*exp(i*angle_Vabc(2)*pi/180)),imag(Vabc_pha(2)*exp(i*angle_Vabc(2)*pi/180)),abs(Vabc_pha(2)),angle_Vabc(2))

fprintf("Voltaje de línea CA (Num complejo): %.2f %.2f j[V]\nVoltaje de línea CA (Phasor): %.2f|%.2f° [V]\n\n",...
    real(Vabc_pha(3)*exp(i*angle_Vabc(3)*pi/180)),imag(Vabc_pha(3)*exp(i*angle_Vabc(3)*pi/180)),abs(Vabc_pha(3)),angle_Vabc(3))

subplot(1,2,1)
plot(t,Vabc)
title("Gráfica de voltaje de línea")
xlabel("Tiempo [s]")
ylabel("Voltaje [V]")
grid on
legend("VAB","VBC","VCA")
xlim([0.1 0.16])
subplot(1,2,2)
plot(t,Iabc)
title("Gráfica de Corriente de línea")
xlabel("Tiempo [s]")
ylabel("Corriente [I]")
grid on
xlim([0.1 0.16])
legend("IAB","IBC","ICA")

clear
clc