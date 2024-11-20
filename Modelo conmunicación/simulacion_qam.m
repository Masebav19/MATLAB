a=importdata("texto.txt");
b=dec2bin(a{1}, 8);
[f,c]=size(b);
binary=zeros(f,c+1);
for i=1:f
    n=0;
   for j=1:c
      if b(i,j)== '1'
         n=n+1;
      end
    binary(i,j)=b(i,j);
   end
   if mod(n,2)== 0
      binary(i,end) = '0';
   else
      binary(i,end) = '1';
   end
end
binary=char(binary);
binary = reshape(binary.'-'0',1,[]);
switch distancia
    case 1
       Pd=30;
    case 2
       Pd=60;
    case 3
        Pd = 80;
    otherwise
       Pd = 40; 
end
sim('QAM_modelo')
salida = out.Data;
aux1=[];
for i=1:3:length(salida)
    aux1=[aux1,salida(i,:)];
end
aux1 = [0,aux1];
aux1 = dec2bin(aux1);
 aux2=[];
  for i=1:9:length(aux1)
      if i+8 < 207
          aux2=[aux2;aux1(i:i+8)'];
      else
          aux2=[aux2;[aux1(i:i+6)',aux1(end),aux1(end)]];
      end
  end
texto = char(bin2dec(aux2(1:23,1:8)));

b=dec2bin(texto, 8);
[f,c]=size(b);
binary2=zeros(f,c+1);
for i=1:f
    n=0;
   for j=1:c
      if b(i,j)== '1'
         n=n+1;
      end
    binary2(i,j)=b(i,j);
   end
   if mod(n,2)== 0
      binary2(i,end) = '0';
   else
      binary2(i,end) = '1';
   end
end
binary2=char(binary2);
paridad2=binary2(:,end);
error = paridad1-paridad2;
m=0;
for k=1:length(error)
    if error(k)==1
        m=m+1;
    end
end
if m > 0 
    s= sprintf("Se tiene %d errores de paridad",m);
    disp(s);
    s= sprintf("el error es en la letra o byte %d: %c",k,texto(k));
    disp(s);
end