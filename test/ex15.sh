#!/bin/bash

loop_display(){
	read -p "continue";
	./display;
	while read -p "Show again? [y/N]" -r y && [ "$y" = "y" ];
	do
		./display;
	done;
}

   echo -e "\n\n		# EX15" \
&& echo -e "\n	## Projection" \
&& cd ./matrix_display/ \
&& ../proj.out 1 1 7.2 12 $@ >proj \
&& echo "
The frustrum dimensions should be barely longer than the model.
The model should be visible immediately without moving; take note of its size for futur references.
The model should disappear if you take only a few steps forward or backward.
" \
&& loop_display \
&& ../proj.out 1 1 7.2 2000 $@ >proj \
&& echo -e "
The fov and aspect ratio are the same as the first time, but the far plane is very generous.
The model should still be immediately visible, and have the same size and proportions as the first time.
The model should disappear if you take a few steps forward.
The model should remain visible much longer if you walk backward.
" \
&& loop_display \
&& echo \
&& ../proj.out 1 1 1 12 $@ >proj \
&& echo "
The fov and aspect are the same as the first time, but the near plane is very generous.
The model should still be immediately visible, and have the same size and proportions as the first time.
The model should remain visible much longer if you walk forward.
The model should disappear if you take a few steps back.
" \
&& loop_display \
|| echo "Test Failed" \
;
