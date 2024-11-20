function out = color_rgb_im(imagen,rgb)
    switch rgb
        case 'R'
          out(:,:,1)=imagen(:,:,1);
          out(:,:,2)=zeros(size(imagen(:,:,1)));
          out(:,:,3)=zeros(size(imagen(:,:,1)));
        case 'G'
          out(:,:,2)=imagen(:,:,2);
          out(:,:,1)=zeros(size(imagen(:,:,2)));
          out(:,:,3)=zeros(size(imagen(:,:,2)));  
        case 'B'
          out(:,:,3)=imagen(:,:,3);
          out(:,:,1)=zeros(size(imagen(:,:,1)));
          out(:,:,2)=zeros(size(imagen(:,:,1))); 
        otherwise
          errordlg('Debe enviar una letra R, G o B');
          out = NaN;
    end
end