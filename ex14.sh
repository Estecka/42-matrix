#!/bin/bash

   echo -e "\n\n		# EX14-00" \
&& echo -e "\n	## Vector Arithmetic" \
&& echo && ./ft_matrix.out i vec 2 add "1,i" "3i,4" \
&& echo && ./ft_matrix.out i vec 2 sub "1+2i,i" "3i,0" \
&& echo && ./ft_matrix.out i vec 2 scl "+4i,+5" "0" \
&& echo && ./ft_matrix.out i vec 2 scl "+4i,+5" "2" \
&& echo && ./ft_matrix.out i vec 2 scl "+4i,+5" "3i" \
&& echo -e "\n	## Vector Arithmetic" \
|| echo "Test Failed" \
;
