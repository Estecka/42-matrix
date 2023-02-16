#!/bin/bash

   echo -e "\n\n		# EX01" \
&& echo -e "\n	## Linear Combination" \
&& echo && ./ft_matrix.out vec 2 fma "1,2;3,4;5,6" "7;8;9" \
&& echo && ./ft_matrix.out vec 3 fma "1,2,3;4,5,6" "7;8" \
&& echo && ./ft_matrix.out vec 3 fma "1,2,3;4,5,6;7,8,9" "10;11;12" \
|| echo "Test Failed" \
;
