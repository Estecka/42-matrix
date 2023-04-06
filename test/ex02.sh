#!/bin/bash

   echo -e "\n\n		# EX02" \
&& echo -e "\n	## Number Linear Interpolation" \
&& echo && ./ft_matrix.out num 1 lerp "0" "1" "0" \
&& echo && ./ft_matrix.out num 1 lerp "0" "1" "1" \
&& echo && ./ft_matrix.out num 1 lerp "0" "1" "0.5" \
&& echo && ./ft_matrix.out num 1 lerp "21" "42" "0.3" \
&& echo -e "\n	## Vector Linear Interpolation" \
&& echo && ./ft_matrix.out vec 2 lerp "2,1" "4,2" "0.3" \
&& echo -e "\n	## Matrix Linear Interpolation" \
&& echo && ./ft_matrix.out mx 2,2 lerp "2,1;3,4" "20,10;30,40" "0.5" \
&& echo && ./ft_matrix.out mx 2,2 lerp "2,1;3,4" "20,10;30,40" "0" \
&& echo && ./ft_matrix.out mx 2,2 lerp "2,1;3,4" "20,10;30,40" "1" \
&& echo && ./ft_matrix.out mx 2,2 lerp "2,1;3,4" "20,10;30,40" "0.25" \
&& echo && ./ft_matrix.out mx 2,2 lerp "2,1;3,4" "20,10;30,40" "0.75" \
|| echo "Test Failed" \
;
