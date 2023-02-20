#!/bin/bash

   echo -e "\n\n		# EX04" \
&& echo -e "\n	## Vector Angle Cosine" \
&& echo && ./ft_matrix.out vec 2 cos "1,0", "1,0" \
&& echo && ./ft_matrix.out vec 2 cos "0,1", "0,1" \
&& echo && ./ft_matrix.out vec 2 cos "1,0", "0,1" \
&& echo && ./ft_matrix.out vec 2 cos "0,1", "1,0" \
&& echo && ./ft_matrix.out vec 2 cos "-1,1", "1,-1" \
&& echo && ./ft_matrix.out vec 2 cos "1,-1", "-1,1" \
&& echo && ./ft_matrix.out vec 2 cos "2,1", "4,2" \
&& echo && ./ft_matrix.out vec 2 cos "4,2", "2,1" \
&& echo && ./ft_matrix.out vec 3 cos "1,2,3" "4,5,6" \
&& echo && ./ft_matrix.out vec 3 cos "4,5,6" "1,2,3" \
|| echo "Test Failed" \
;
