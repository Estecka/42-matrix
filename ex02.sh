#!/bin/bash

   echo -e "\n\n		# EX02" \
&& echo -e "\n	## Vector Linear Interpolation" \
&& echo && ./ft_matrix.out vec 2 lerp "1,2" "3,4" "0.5" \
&& echo && ./ft_matrix.out vec 2 lerp "1,2" "3,4" "0.75" \
&& echo && ./ft_matrix.out vec 3 lerp "1,2,3" "4,5,6" "0" \
&& echo && ./ft_matrix.out vec 3 lerp "1,2,3" "4,5,6" "1" \
&& echo && ./ft_matrix.out vec 4 lerp "1,2,3,4" "5,6,7,8" "-1" \
&& echo && ./ft_matrix.out vec 4 lerp "1,2,3,4" "5,6,7,8" "3" \
|| echo "Test Failed" \
;
