#!/bin/bash

   echo -e "\n\n		# EX13" \
&& echo -e "\n	## Rank" \
&& echo && ./ft_matrix.out mx 3,3 rank "1,0,0;0,1,0;0,0,1" \
&& echo && ./ft_matrix.out mx 4,3 rank "1,2,0,0;2,4,0,0;-1,2,1,1" \
&& echo && ./ft_matrix.out mx 3,4 rank "8,5,-2;4,7,20;7,6,1;21,18,7" \
|| echo "Test Failed" \
;
