#!/bin/bash

   echo -e "\n\n		# EX00" \
&& echo -e "\n	## Vector Addition" \
&& echo && ./ft_matrix.out vec 2 add "2,3" "5,7" \
&& echo && ./ft_matrix.out vec 2 add "4.5,6e2" "-50.6,600e-1" \
&& echo && ./ft_matrix.out vec 3 add "1,2,3" "4,5,6" \
&& echo -e "\n	## Vector Substraction" \
&& echo && ./ft_matrix.out vec 2 sub "2,3" "5,7" \
&& echo && ./ft_matrix.out vec 2 sub "4.5,6e2" "-50.6,600e-1" \
&& echo && ./ft_matrix.out vec 3 sub "1,2,3" "6,5,4" \
&& echo -e "\n	## Vector Scaling" \
&& echo && ./ft_matrix.out vec 2 scl "2,3" "2" \
&& echo && ./ft_matrix.out vec 2 scl "4.5,6e2" "-50.6" \
&& echo && ./ft_matrix.out vec 3 scl "1,2,3" "4" \
&& echo && ./ft_matrix.out vec 3 scl "4.5,6e2,-50.6" "3.5e-1" \
&& echo -e "\n	## Matrix Addition" \
&& echo && ./ft_matrix.out mx 2,2 add "1,2;3,4" "7,4;-2,2" \
&& echo && ./ft_matrix.out mx 3,2 add "1,2;3,4;5,6" "7,8;9,10;11,12" \
&& echo && ./ft_matrix.out mx 3,3 add "1,2,3;4,5,6;7,8,9" "10,11,12;13,14,15;16,17,18" \
&& echo -e "\n	## Matrix Substraction" \
&& echo && ./ft_matrix.out mx 2,2 sub "1,2;3,4" "7,4;-2,2" \
&& echo && ./ft_matrix.out mx 3,2 sub "1,2;3,4;5,6" "12,11;10,9;8,7" \
&& echo && ./ft_matrix.out mx 3,3 sub "1,2,3;4,5,6;7,8,9" "18,17,16;15,14,13;12,11,10" \
&& echo -e "\n	## Matrix Scaling" \
&& echo && ./ft_matrix.out mx 2,2 scl "1,2;3,4" "2" \
&& echo && ./ft_matrix.out mx 3,2 scl "1,2;3,4;5,6" "-10" \
&& echo && ./ft_matrix.out mx 3,3 scl "1,2,3;4,5,6;7,8,9" "2e-1" \
|| echo "Test Failed" \
;
