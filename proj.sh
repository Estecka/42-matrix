#!/bin/bash

make proj.out \
&& cd matrix_display \
&& ../proj.out $1 $2 $3 $4 > proj \
&& cat -e proj \
&& ./display \
;
