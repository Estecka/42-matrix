#!/bin/bash

   echo -e "\n\n		# EX12" \
&& echo -e "\n	## Inverse" \
&& echo && ./ft_matrix.out mx 3,3 inv "1,0,0;0,1,0;0,0,1" \
&& echo && ./ft_matrix.out mx 3,3 inv "2,0,0;0,2,0;0,0,2" \
&& echo && ./ft_matrix.out mx 3,3 inv "8,5,-2;4,7,20;7,6,1" \
&& echo && ./ft_matrix.out mx 3,3 inv "1,0,0;0,1,0;0,0,0" \
&& echo && ./ft_matrix.out mx 3,3 inv "1,0,0;0,1,1;1,1,1" \
&& echo && ./ft_matrix.out mx 3,2 inv "1,0,0;0,1,1" \
|| echo "Test Failed" \
;
