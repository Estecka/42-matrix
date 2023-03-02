#!/bin/bash

   echo -e "\n\n		# EX11" \
&& echo -e "\n	## Determinant" \
&& echo && ./ft_matrix.out mx 2,2 det "1,-1;-1,1" \
&& echo && ./ft_matrix.out mx 2,2 det "1,0;0,1" \
&& echo && ./ft_matrix.out mx 3,3 det "2,0,0;0,2,0;0,0,2" \
&& echo && ./ft_matrix.out mx 3,3 det "1,0,0;0,1,0;0,0,1" \
&& echo && ./ft_matrix.out mx 3,3 det "8,5,-2;4,7,20;7,6,1" \
&& echo && ./ft_matrix.out mx 4,4 det "8,5,-2,4;4,2.5,20,4;8,5,1,4;28,-4,17,1" \
|| echo "Test Failed" \
;
