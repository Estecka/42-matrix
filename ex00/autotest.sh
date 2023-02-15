#!/bin/bash

make \
&& echo -e "\n\n		# EX00" \
&& echo -e "\n	## Vector Addition" \
&& echo && ./ex00.out vec 2 add "1,2" "3,4" \
&& echo && ./ex00.out vec 2 add "4.5,6e2" "-50.6,600e-1" \
&& echo && ./ex00.out vec 3 add "1,2,3" "4,5,6" \
&& echo -e "\n	## Vector Substraction" \
&& echo && ./ex00.out vec 2 sub "1,2" "4,3" \
&& echo && ./ex00.out vec 2 sub "4.5,6e2" "-50.6,600e-1" \
&& echo && ./ex00.out vec 3 sub "1,2,3" "6,5,4" \
&& echo -e "\n	## Vector Scaling" \
&& echo && ./ex00.out vec 2 scl "1,2" "3" \
&& echo && ./ex00.out vec 2 scl "4.5,6e2" "-50.6" \
&& echo && ./ex00.out vec 3 scl "1,2,3" "4" \
&& echo && ./ex00.out vec 3 scl "4.5,6e2,-50.6" "3.5e-1" \
|| echo "Test Failed" \
;
