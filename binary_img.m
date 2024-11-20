function out = binary_img(imagen,level)
    [f,c,p]=size(imagen);
    imagen = double(imagen)/255;
    for k = 1:f
       for l=1:c
           if (imagen(k,l,1)+imagen(k,l,2)+imagen(k,l,3)) >= 1-level
            out(k,l) = logical(0);
           else
            out(k,l) = logical(1);   
           end
       end
    end
end
