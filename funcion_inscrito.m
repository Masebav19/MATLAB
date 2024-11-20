function [x,y]=funcion_inscrito(radio,n)
    x = zeros(1,n);
    y=zeros(1,n);
    l= radio;
    i=1;
    while(i<n)
       xi = 10*randn(1);
       yi= 10*randn(1);
       if sqrt(xi^2+yi^2) >= radio && abs(xi) <= l && abs(yi)<= l
           x(i)=xi;
           y(i)=yi;
           i=i+1;
       end
    end
end