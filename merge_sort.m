function M_out = merge_sort(M_in)
    n = length(M_in);
    if n <= 1
       M_out = M_in; 
    else
        M_out=ordenar(merge_sort(M_in(1:floor(n/2))),merge_sort(M_in(floor(n/2)+1:n)));
    end
end