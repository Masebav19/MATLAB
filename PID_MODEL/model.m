clear
clc
G = tf(10,[10 1]);
x0=20;
client = modbus("tcpip","192.168.10.7",502);
x = [];
y = [];
figure
n0=100*read(client,'inputregs',2,1)/10e3;
t0=0;
t_sim = [];
for i=1:10e3
    niq = 100*double(read(client,'inputregs',2,1))/10e3;
    X=lsim(G,[n0 niq],[t0 100e-3+t0],20);
    data = 10000*X(2)/200;
    write(client,"holdingregs",3,round(data))
    t_sim(i)=t0;
    t0=t0+100e-3;
    n0=niq;
    x(i) = double(read(client,'inputregs',1,1));
    y(i) = data;
    plot(t_sim,x,t_sim,y)
    drawnow
    pause(0.4)
end