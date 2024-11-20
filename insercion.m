function M_out = insercion(M_in)
    [fl,cl]=size(M_in);
    for f=1:fl
       for c=1:cl-1
           cont = 0;
           while cont < c
               if M_in(f,c-cont+1) < M_in(f,c-cont)
                aux = M_in(f,c-cont);
                M_in(f,c-cont)= M_in(f,c-cont+1);
                M_in(f,c-cont+1)= aux;
                cont = cont + 1;
               else
                break;   
               end
           end
       end
    end
    M_out = M_in;
end