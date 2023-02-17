#!/bin/bash

   echo -e "\n\n		# EX02" \
&& echo -e "\n	## Vector Linear Interpolation" \
&& echo && ./ft_matrix.out vec 1 lerp "0" "1" "0" \
&& echo && ./ft_matrix.out vec 1 lerp "0" "1" "1" \
&& echo && ./ft_matrix.out vec 1 lerp "0" "1" "0.5" \
&& echo && ./ft_matrix.out vec 1 lerp "21" "42" "0.3" \
&& echo && ./ft_matrix.out vec 2 lerp "2,1" "4,2" "0.3" \
|| echo "Test Failed" \
;
