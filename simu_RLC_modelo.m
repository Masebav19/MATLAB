R=100;
L=100e-3;
C=20e-6;
E=12;
sim('circuito_RLC_modelo');
subplot(2,1,1);
plot(out.Time,1000*out.Data(:,1));
title('Respuesta de la corriente');
xlabel('tiempo [s]');
ylabel('Corriente [mA]')

subplot(2,1,2);
plot(out.Time,1e6*out.Data(:,2));
title('Respuesta de la carga');
xlabel('tiempo [s]');
ylabel('Carga [uC]')