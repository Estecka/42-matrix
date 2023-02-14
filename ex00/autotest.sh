#!/bin/bash

make \
&& echo -e "\n\n		# EX00" \
&& echo "	## Vector Addition" \
&& echo && ./ex00.out vec 2 add "1,2" "3,4" \
&& echo && ./ex00.out vec 2 add "4.5,6e2" "-50.6,600e-1" \
&& echo && ./ex00.out vec 3 add "1,2,3" "4,5,6" \
|| echo "Test Failed" \
;
