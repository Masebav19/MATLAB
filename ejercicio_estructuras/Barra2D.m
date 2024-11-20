classdef Barra2D
    % Clase creadas para barras 2D
    %   Detailed explanation goes here

    properties
        Name
        E
        A
        node_j
        node_k
    end

    properties
        Sm
        Sj
        T
    end
    
    properties (Hidden)
        vector % Para calcular longitud y angulo
        nDof=2;
    end

    properties
        L
        alpha
        index
    end

    properties
        Dj
        Aj
        Dm
        Am
    end

    methods
        % Funcion para instanciar las propiedades de las barras (Geometria y rigidez)
        function obj=Barra2D(Name,E,A,node_j,node_k)
            if nargin>0
                obj.Name=Name;
                obj.E=E;
                obj.A=A;
                obj.node_j=node_j;
                obj.node_k=node_k;
                [obj.L,obj.alpha,obj.index]=obj.Geometria;
                [obj.Sm,obj.Sj,obj.T]=obj.Propiedades;
            end
        end
    end

    methods
        % Funciones de apoyo para el calculo de la geometria de la barra
        function [L,alpha,index]=Geometria(obj)
            % Calculamos los datos geometricos de los elementos
            n_j=obj.node_j;
            n_k=obj.node_k;
            obj.vector=n_k.coordenada-n_j.coordenada;
            alpha=atan2d(obj.vector(1,2),obj.vector(1,1));
            L=(obj.vector(1,2)^2+obj.vector(1,1)^2)^0.5;

            % Realizamos un algoritmo para definir los indices de la barra
            i_j=n_j.index;
            i_k=n_k.index;
            index=[i_j,i_k];
        end

        %Funciones de apoyo para el calculo de la rigidez de la barra
        function [Sm,Sj,T] = Propiedades(obj)
            % Calculamos la matriz de rigidez local y global del elemento 
            Sm=obj.E*obj.A/obj.L*[1 -1
                                 -1  1];
            c=cosd(obj.alpha);
            s=sind(obj.alpha);
            Sj=obj.E*obj.A/obj.L*[c^2  c*s   -c^2 -c*s
                                  c*s  s^2   -c*s -s^2
                                 -c^2 -c*s    c^2  c*s
                                 -c*s -s^2    c*s  s^2];
            T=[c s 0 0
               0 0 c s];
        end
 
        function [Dj,Dm,Aj,Am] = Calculos_locales(Dj)
            Dj=Dj(obj.index);
            % Calculo de desplazamientos locales
            Dm=obj.T*obj.Dj;
            % Calculo de fuerzas locales
            Am=obj.Sm*obj.Dm;
            % Calculo de fuerzas de nudos
            Aj=obj.T'*obj.Am;
        end
    end

end