#!/bin/bash

   echo -e "\n\n		# EX06" \
&& echo -e "\n	## Vector3 Cross Product" \
&& echo && ./ft_matrix.out vec 3 cross "0,0,1" "1,0,0" \
&& echo && ./ft_matrix.out vec 3 cross "1,0,0" "0,0,1" \
&& echo && ./ft_matrix.out vec 3 cross "1,2,3" "4,5,6" \
&& echo && ./ft_matrix.out vec 3 cross "4,5,6" "1,2,3" \
&& echo && ./ft_matrix.out vec 3 cross "4,2,-3" "-2,-5,16" \
&& echo && ./ft_matrix.out vec 3 cross "-2,-5,16" "4,2,-3" \
|| echo "Test Failed" \
;
