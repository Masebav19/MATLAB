classdef Node2D
    %UNTITLED Summary of this class goes here
    %   numero - Se refiere al codigo individual de cada nudo, los nudos
    %   debes ser enteros, positivos, y tener un valor propio que no se
    %   repita
    %   coordenada - son las coordenadas cartesianas definidas como un vector [i j k]
    %   restrain - corresponde a un vector que indica los grados de
    %   libertad libre y los restringidos [f/r f/r f/r] - f es libres - r
    %   es restringidos
    %   desplazamiento - corresponde a los desplazamientos del nudo

    properties
        node_number
        coordenada
        load
        restrain
        restrain_displacement=[0,0];
        desplazamiento
    end

    properties
        nDof=2;
        index
        boundary_condition;
    end

    methods
        % Funcion para instanciar el objeto
        function obj = Node2D(numero,coordenada,load,restrain)
            % Instanciamos las propiedades del objeto
            %   Detailed explanation goes here
            if nargin>0
                obj.node_number = numero;
                obj.coordenada=coordenada;
                obj.load=load;
                obj.restrain=restrain;
                % Creamos el vector del nudo con los indices
                obj.index=[obj.nDof*obj.node_number-1,obj.nDof*obj.node_number];
                % Creamos el vector del nudo con los indices que relacionan
                % los nudos libres - 1=restringido - 0=libre
                obj.boundary_condition=obj.restrain;
                obj.boundary_condition(obj.boundary_condition~="r")=0;
                obj.boundary_condition(obj.boundary_condition=="r")=1;
                obj.boundary_condition=str2double(obj.boundary_condition);
            end 
        end
    end

end