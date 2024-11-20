d=2;%km
dr=1.5;%km
v=60;%km/h
fs=900e6;%MHz
c=3e8*3.6;%km/h
alpha =1;
Ds=2*fs*v/c;
t=linspace(0,2/Ds,200);
E=2*alpha.*sin(2*pi*fs.*(v.*t./c+(d-dr)/c)).*sin(2*pi*fs.*(t-d/c));
figure
subplot(1,2,1)
plot(t,E)
title('Forma de onda en el tiempo');
subplot(1,2,2)
n = 2^nextpow2(length(t));
f = Ds*(0:(n/2))/n;
y=fft(E,n);
P = abs(y/n).^2;
plot(f,P(1:n/2+1))
title('Magnitudes para n ancho de banda de 50Hz')

t=linspace(0,2/Ds,300);
E=2*alpha.*sin(2*pi*fs.*(v.*t./c+(d-dr)/c)).*sin(2*pi*fs.*(t-d/c));
figure
subplot(1,2,1)
plot(t,E)
title('Forma de onda en el tiempo');
subplot(1,2,2)
n = 2^nextpow2(length(t));
f = fs*(0:(n/2))/n;
y=fft(E,n);
P = abs(y/n).^2;
plot(f,P(1:n/2+1))
title('Magnitudes para n ancho de banda de 450MHz')

