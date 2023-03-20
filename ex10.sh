#!/bin/bash

   echo -e "\n\n		# EX10" \
&& echo -e "\n	## Reduced Row-Echelon" \
&& echo && ./ft_matrix.out mx 3,3 rowech "1,0,0;0,1,0;0,0,1" \
&& echo && ./ft_matrix.out mx 2,2 rowech "1,2;3,4" \
&& echo && ./ft_matrix.out mx 2,2 rowech "1,2;2,4" \
&& echo && ./ft_matrix.out mx 5,3 rowech "8,5,-2,4,28;4,2.5,20,4,-4;8,5,1,4,17" \
&& echo && ./ft_matrix.out mx 4,4 rowech "1,2,1.5,4.5;6,12,13,39;2,4,3,9;2,4,4,12" \
|| echo "Test Failed" \
;
