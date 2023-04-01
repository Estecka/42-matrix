#!/bin/bash

make proj.out \
&& cd matrix_display \
&& ../proj.out $@ > proj \
&& cat -e proj \
&& ./display \
;
