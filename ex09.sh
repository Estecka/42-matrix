#!/bin/bash

   echo -e "\n\n		# EX09" \
&& echo -e "\n	## Matrix Transposition " \
&& echo && ./ft_matrix.out mx 3,3 trans "1,0,0;0,1,0;0,0,1" \
&& echo && ./ft_matrix.out mx 2,3 trans "1,2,3;4,5,6" \
&& echo && ./ft_matrix.out mx 4,3 trans "0,1,2;3,4,5;6,7,8;9,10,11" \
|| echo "Test Failed" \
;
