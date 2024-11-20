function y = Quick_Sort(x)

n=length(x);

if n<2
y = x;
return;
end

x1 = [];
x2 = [];

for i = 1:n-1

if x(i)<x(n)
x1 = [x1 x(i)];
else
x2 = [x2 x(i)];
end
end

y = [Quick_Sort(x1) x(n) Quick_Sort(x2)];

end