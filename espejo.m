function out = espejo(imagen)
    [f,c,p]=size(imagen);
    out=zeros(f,c,p);
for i=1:p
   for k=1:c
      out(:,k,i)=imagen(:,end-k+1,i); 
   end
end
out = uint8(out);
end