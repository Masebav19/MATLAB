clear
clc
menu = input('Selecciones el tipo de modulación [1. ASK, 2. FSK, 3. QAM]: ');
distancia= input('Agrega la distancia en que se encuentran los equipos [1. 1m, 2. 10m, 3. 100m]: ');

switch menu
    case 1
      tipo = 'modelo'; % ask 
      simulacioon;
      id=fopen('resultado.txt','w');
      fprintf(id,texto');
      fclose(id);
      disp(texto');
      disp('Texto guardado en resultado');
    case 2
      tipo = 'FSK_modelo'; % Fask 
      simulacioon;
      id=fopen('resultado.txt','w');
      fprintf(id,texto'); 
      fclose(id);
      disp(texto');
      disp('Texto guardado en resultado');
    case 3
      tipo = 'QAM_modelo'; % QAM 
      simulacion_qam;
      id=fopen('resultado.txt','w');
      fprintf(id,texto');
      fclose(id);
      disp(texto');
      disp('Texto guardado en resultado');
    otherwise
     disp ('opcion incorrecta')   
end