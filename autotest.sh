#!/bin/bash

make \
&& ./ft_matrix.out \
&& ./test/ex00.sh \
&& ./test/ex01.sh \
&& ./test/ex02.sh \
&& ./test/ex03.sh \
&& ./test/ex04.sh \
&& ./test/ex05.sh \
&& ./test/ex06.sh \
&& ./test/ex07.sh \
&& ./test/ex08.sh \
&& ./test/ex09.sh \
&& ./test/ex10.sh \
&& ./test/ex11.sh \
&& ./test/ex12.sh \
&& ./test/ex13.sh \
&& ./test/ex14.sh \
&& echo -e "\n\t\t# EX-15\n" \
&& ./proj.out 1 1 2 20 -t -ndc="-1,-1,0;1,1,1" \
;
