#!/bin/bash

   echo -e "\n\n		# EX09" \
&& echo -e "\n	## Reduced Row-Echelon " \
&& echo && ./ft_matrix.out mx 3,3 rowech "1,0,0;0,1,0;0,0,1" \
&& echo && ./ft_matrix.out mx 2,2 rowech "1,2;3,4" \
&& echo && ./ft_matrix.out mx 2,2 rowech "1,2;2,4" \
&& echo && ./ft_matrix.out mx 5,3 rowech "8,5,-2,4,28;4,2.5,20,4,-4;8,5,1,4,17" \
|| echo "Test Failed" \
;
