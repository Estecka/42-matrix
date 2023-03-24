#!/bin/bash

make proj.out \
&& ./proj.out $1 $2 $3 $4 > proj \
&& cat -e proj \
&& ./matrix_display/display;
