% Valores en estado estable
n_10 = 1.9531e18; s_10 = 1.9221e13;
n_15 = 1.9571e18; s_15 = 1.7141e14;
% Constantes
q = 1.6e-19; Va = 9e-11;
tn = 3e-9; tp = 1e-12;
gamma = 0.44; beta = 4e-4;
N0 = 1.2e18; g0 = 3e-6;
eta = 0.1; h = 6.624e-34;
f = 1.997e14;
alpha=0.6;
n0=0.04;
v=3e14;
% Matriz de espacio de estado
A_10 = [-g0*s_10-1/tn -g0*(n_10 - N0) 0; gamma*g0*s_10+gamma*beta/tn gamma*g0*(n_10 -N0)-1/tp 0; 0.5*alpha*gamma*g0 0 0];
A_15 = [-g0*s_15-1/tn -g0*(n_15 - N0) 0; gamma*g0*s_15+gamma*beta/tn gamma*g0*(n_15 -N0)-1/tp 0;0.5*alpha*gamma*g0 0 0];
B = [(1/(q*Va)); 0;0];
C = [0 1 0];
D = 0;
% Eentrada
t = 0:0.0001:14;
t = t*1e-9;
u = 20/t(end).*t;
u = u*1e-3;

sys = ss(A_10,B,C,D); sys_15 = ss(A_15,B,C,D);

y = lsim(sys,u,t); y2 = lsim(sys_15,u,t);

y = s_10*ones(length(y),1) + y; y2 = s_15*ones(length(y2),1) + y2;

Ith=9.3e-3;
p=zeros(size(u));
for i=1:length(u)
    if u(i)<Ith
       p(i)=0; 
    else
       p(i)=n0*(u(i)-Ith);
    end
end