#!/bin/bash

   echo -e "\n\n		# EX07" \
           "\n	The \033[1;33minput\033[0m is displayed as transposed." \
&& echo -e "\n	## Matrix X Vector multiplication " \
&& echo -e "\n	Natural order" \
&& ./ft_matrix.out nmp 2,2,1 mxm "2,-2;-2,2" "4;2" \
&& echo -e "\n	Reversed order" \
&& ./ft_matrix.out nmp 2,1,2 mxm "4,2" "2,-2;-2,2" \
&& echo -e "\n	## Matrix X Matrix multiplication " \
&& echo -e "\n	Natural" \
&& ./ft_matrix.out nmp 2,2,2 mxm "3,-5;6,8" "2,1;4,2" \
&& echo -e "\n	Transposed matrices" \
&& ./ft_matrix.out nmp 2,2,2 mxm "3,6;-5,8" "2,4;1,2" \
&& echo -e "\n	Reversed order" \
&& ./ft_matrix.out nmp 2,2,2 mxm "2,1;4,2" "3,-5;6,8" \
&& echo -e "\n	Reversed order + Transposed matrices" \
&& ./ft_matrix.out nmp 2,2,2 mxm "2,4;1,2" "3,6;-5,8" \
|| echo "Test Failed" \
;
