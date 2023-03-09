#!/bin/bash

   echo -e "\n\n		# EX14-00" \
&& echo -e "\n	## Vector Arithmetic" \
&& echo && ./ft_matrix.out i vec 2 add "1,i" "3i,4" \
&& echo && ./ft_matrix.out i vec 2 sub "1+2i,i" "3i,0" \
&& echo && ./ft_matrix.out i vec 3 scl "+4i,+5,6+4i" "0" \
&& echo && ./ft_matrix.out i vec 3 scl "+4i,+5,6+4i" "2" \
&& echo && ./ft_matrix.out i vec 3 scl "+4i,+5,6+4i" "3i" \
&& echo && ./ft_matrix.out i vec 3 scl "+4i,+5,6+4i" "2+3i" \
&& echo -e "\n	## Matrix Arithmetic" \
&& echo && ./ft_matrix.out i mx 2,2 add "1,i;3i,4-5i" "6.7i,8+i;9+11i,0" \
&& echo && ./ft_matrix.out i mx 2,2 sub "1,i;3i,4-5i" "6.7i,8+i;9+11i,0" \
&& echo && ./ft_matrix.out i mx 2,2 scl "1,i;3i,4-5i" "0" \
&& echo && ./ft_matrix.out i mx 2,2 scl "1,i;3i,4-5i" "2" \
&& echo && ./ft_matrix.out i mx 2,2 scl "1,i;3i,4-5i" "3i" \
&& echo && ./ft_matrix.out i mx 2,2 scl "1,i;3i,4-5i" "2+3i" \
&& echo -e "\n\n		# EX14-01" \
&& echo -e "\n	## Linear Combination" \
&& echo && ./ft_matrix.out i vec 2 fma "1,-i;-3i,4-i;5-9i,6;7,-8" "0;i;2;2+3i" \
|| echo "Test Failed" \
;
