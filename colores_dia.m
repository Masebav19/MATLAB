clear
clc
r=[255 0 204 255 163];
g=[255 0 255 127 73];
b=[255 255 0 0  164];
r=4095.*r./255;
g=4095.*g./255;
b=4095.*b./255;
p1=polyfit(linspace(1,3600,5),r,4);
figure
plot(linspace(1,3600,5),r);
hold on
plot(linspace(1,3600,200),polyval(p1,linspace(1,3600,200)));
hold off

p2=polyfit(linspace(1,3600,5),g,4);
figure
plot(linspace(1,3600,5),g);
hold on
plot(linspace(1,3600,200),polyval(p2,linspace(1,3600,200)));
hold off

p3=polyfit(linspace(1,3600,5),b,4);
figure
plot(linspace(1,3600,5),b);
hold on
plot(linspace(1,3600,200),polyval(p3,linspace(1,3600,200)));
hold off