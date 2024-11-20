function M_out = burbuja(M_in)
    [fl,cl]=size(M_in);
    n=0;
    for i=1:cl
    n=n+i;
    end
    for f=1:fl
       for j=1:n
           for c=1:cl-1
              if M_in(f,c) > M_in(f,c+1)
                 aux = M_in(f,c);
                 M_in(f,c) = M_in(f,c+1);
                 M_in(f,c+1) = aux;
              end
           end
       end
    end
    M_out = M_in;
end