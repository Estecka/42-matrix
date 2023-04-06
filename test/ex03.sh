#!/bin/bash

   echo -e "\n\n		# EX03" \
&& echo -e "\n	## Vector Dot Product" \
&& echo && ./ft_matrix.out vec 2 dot "0,0" "1,1" \
&& echo && ./ft_matrix.out vec 2 dot "1,1" "1,1" \
&& echo && ./ft_matrix.out vec 2 dot "-1,6" "3,2" \
|| echo "Test Failed" \
;
