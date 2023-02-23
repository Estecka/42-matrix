#!/bin/bash

   echo -e "\n\n		# EX07" \
&& echo -e "\n	## Matrix X Vector multiplication " \
&& echo && ./ft_matrix.out mx 2,2 mxv "1,0;0,1" "4,2" \
&& echo && ./ft_matrix.out mx 2,2 mxv "2,0;0,2" "4,2" \
&& echo && ./ft_matrix.out mx 2,2 mxv "2,-2;-2,2" "4,2" \
&& echo && ./ft_matrix.out mx 3,2 mxv "1,1;-1,1;-1,-1" "1,0,0" \
&& echo && ./ft_matrix.out mx 3,2 mxv "1,1;-1,1;-1,-1" "0,1,0" \
&& echo && ./ft_matrix.out mx 3,2 mxv "1,1;-1,1;-1,-1" "1,0,1" \
&& echo && ./ft_matrix.out mx 3,2 mxv "1,1;-1,1;-1,-1" "0,1,1" \
&& echo -e "\n	## Matrix X Matrix multiplication " \
&& echo && ./ft_matrix.out nmp 2,2,2 mxm "1,0;0,1" "1,0;0,1" \
&& echo && ./ft_matrix.out nmp 2,2,2 mxm "2,1;4,2" "1,0;0,1" \
&& echo && ./ft_matrix.out nmp 2,2,2 mxm "1,0;0,1" "2,1;4,2" \
&& echo && ./ft_matrix.out nmp 2,2,2 mxm "3,-5;6,8" "2,1;4,2" \
&& echo && ./ft_matrix.out nmp 2,2,2 mxm "2,1;4,2" "3,-5;6,8" \
&& echo && ./ft_matrix.out nmp 2,2,2 mxm "1,1;-1,1" "1,-1;1,1" \
&& echo && ./ft_matrix.out nmp 4,3,2 mxm "1,0,0;0,2,0;0,0,3;1,1,1" "0,1,2,3;4,5,6,7" \
|| echo "Test Failed" \
;
