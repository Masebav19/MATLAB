function out = gray_image(imagen)
    imagen = double(imagen);
    out = 0.299.*imagen(:,:,1)+0.587.*imagen(:,:,2)+0.114.*imagen(:,:,3);
    out = uint8(out);
end