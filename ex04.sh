#!/bin/bash

   echo -e "\n\n		# EX04" \
&& echo -e "\n	## Vector Norm" \
&& echo && ./ft_matrix.out vec 3 norm "0,0,0" \
&& echo && ./ft_matrix.out vec 3 norm "1,2,3" \
&& echo && ./ft_matrix.out vec 2 norm "-1,-2" \
&& echo && ./ft_matrix.out vec 4 norm "0,0,0,0" \
&& echo && ./ft_matrix.out vec 4 norm "1,2,3,4" \
&& echo && ./ft_matrix.out vec 4 norm "-1,-2,-3,-4" \
|| echo "Test Failed" \
;
