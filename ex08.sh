#!/bin/bash

   echo -e "\n\n		# EX08" \
&& echo -e "\n	## Matrix Trace " \
&& echo && ./ft_matrix.out mx 2,2 trace "1,0;0,1" \
&& echo && ./ft_matrix.out mx 3,3 trace "2,-5,0;4,3,7;-2,3,4" \
&& echo && ./ft_matrix.out mx 3,3 trace "-2,-8,4;1,-23,4;0,6,4" \
|| echo "Test Failed" \
;
