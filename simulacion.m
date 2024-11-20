%% Ejercicio 1
    %literal 1
s=tf('s');
H=(2*s+1)/(s^2+3*s+2);%Función de tranferencia

w=logspace(-1,2,10000);
magH=10*log10(1+4.*w.^2)-10*log10((2-w.^2).^2+9.*w.^2);%función de magnitud
Hw=(2*i.*w+1)./(-w.^2+3*i.*w+2);
figure
subplot(2,1,1)
semilogx(w,magH);
title('Respuesta en frecuencia literal 1')
xlabel('Frecencia [rad/s]')
ylabel('Magnitud [dB]')
subplot(2,1,2)
semilogx(w,180*angle(Hw)/pi);
xlabel('Frecencia [rad/s]')
ylabel('Angulo [°]')

    %literal 2
s=tf('s');
H2=(2*s+1)/(s^2+4*s+4);%Función de tranferencia

w=logspace(-1,2,10000);
magH2=10*log10(1+4.*w.^2)-10*log10((4-w.^2).^2+16.*w.^2);%función de magnitud
Hw2=(2*i.*w+1)./(-w.^2+4*i.*w+4);
figure
subplot(2,1,1)
semilogx(w,magH2);
title('Respuesta en frecuencia literal 2')
xlabel('Frecencia [rad/s]')
ylabel('Magnitud [dB]')
subplot(2,1,2)
semilogx(w,180*angle(Hw2)/pi);
xlabel('Frecencia [rad/s]')
ylabel('Angulo [°]')
