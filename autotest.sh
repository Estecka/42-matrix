#!/bin/bash

make \
&& ./ft_matrix.out \
&& ./ex00.sh \
&& ./ex01.sh \
&& ./ex02.sh \
&& ./ex03.sh \
&& ./ex04.sh \
&& ./ex05.sh \
&& ./ex06.sh \
&& ./ex07.sh \
&& ./ex08.sh \
&& ./ex09.sh \
&& ./ex10.sh \
&& ./ex11.sh \
&& ./ex12.sh \
&& ./ex13.sh \
&& ./ex14.sh \
&& echo -e "\n\t\t# EX-15\n" \
&& ./proj.out 1 1 2 20 -t -ndc="-1,-1,0;1,1,1" \
;
