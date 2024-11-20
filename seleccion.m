function M_out = seleccion(M_in)
    [fl,cl]=size(M_in);
    M_out=zeros(size(M_in));
    for f=1:fl
       for c=1:cl
           cont = 0;
           for i=1:cl
               if M_in(f,c)<M_in(f,i)
                cont = cont+1;
               end
           end
           M_out(f,cl-cont)=M_in(f,c);
       end
    end
end