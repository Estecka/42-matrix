#!/bin/bash

make proj.out \
&& cd matrix_display \
&& echo \
&& ../proj.out $@ > proj \
&& cat -e proj \
&& ./display \
;
