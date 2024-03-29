#!/bin/bash

   echo -e "\n\n		# EX14-00" \
&& echo -e "\n	## Vector Arithmetic" \
&& echo && ./ft_matrix.out i vec 2 add "1,i" "3i,4" \
&& echo && ./ft_matrix.out i vec 2 sub "1+2i,i" "3i,0" \
&& echo && ./ft_matrix.out i vec 3 scl "+4i,+5,6+4i" "2+3i" \
&& echo -e "\n	## Matrix Arithmetic" \
&& echo && ./ft_matrix.out i mx 2,2 add "1,i;3i,4-5i" "6.7i,8+i;9+11i,0" \
&& echo && ./ft_matrix.out i mx 2,2 sub "1,i;3i,4-5i" "6.7i,8+i;9+11i,0" \
&& echo && ./ft_matrix.out i mx 2,2 scl "1,i;3i,4-5i" "2+3i" \
&& echo -e "\n\n		# EX14-01" \
&& echo -e "\n	## Linear Combination" \
&& echo && ./ft_matrix.out i vec 2 fma "1,-i;-3i,4-i;5-9i,6;7,-8" "0;i;2;2+3i" \
&& echo -e "\n\n		# EX14-02" \
&& echo -e "\n	## Linear interpolation" \
&& echo && ./ft_matrix.out i num 1 lerp "0" "1+i" "0" \
&& echo && ./ft_matrix.out i num 1 lerp "0" "1+i" "0.5" \
&& echo && ./ft_matrix.out i num 1 lerp "0" "1+i" "1" \
&& echo && ./ft_matrix.out i vec 2 lerp "2+i,1-3i" "0,-2" "0.7" \
&& echo -e "\n\n		# EX14-03" \
&& echo -e "\n	## Dot Product" \
&& echo && ./ft_matrix.out i vec 2 dot "-1,6i" "3+i,2-5i" \
&& echo -e "\n\n		# EX14-04" \
&& echo -e "\n	## Vector Norm" \
&& echo && ./ft_matrix.out i vec 2 norm "0,0" \
&& echo && ./ft_matrix.out i vec 3 norm "i,2i,3i" \
&& echo && ./ft_matrix.out i vec 2 norm "-1i,-2i" \
&& echo && ./ft_matrix.out i vec 2 norm "2-3i,4+5i" \
&& echo -e "\n\n		# EX14-05" \
&& echo -e "\n	## Vector Angle Cosine" \
&& echo && ./ft_matrix.out i vec 2 cos "1,1", "-i,i" \
&& echo && ./ft_matrix.out i vec 2 cos "1,1", "1-i,i" \
&& echo && ./ft_matrix.out i vec 2 cos "1,1", "1-i,100i" \
&& echo && ./ft_matrix.out i vec 2 cos "1,1", "1-i,1e-15i" \
&& echo && ./ft_matrix.out i vec 2 cos "-1,6i", "3+i,2-5i" \
&& echo -e "\n\n		# EX14-06" \
&& echo -e "\n	## Vector3 Cross Product" \
&& echo && ./ft_matrix.out i vec 3 cross "0,0,i" "i,0,0" \
&& echo && ./ft_matrix.out i vec 3 cross "0,0,i" "i,0,0" \
&& echo && ./ft_matrix.out i vec 3 cross "2i,0,0" "0,0,2i" \
&& echo && ./ft_matrix.out i vec 3 cross "3+2i,0,0" "0,0,3+2i" \
&& echo && ./ft_matrix.out i vec 3 cross "i,2,3+4i" "4+i,5-i,-6i" \
&& echo && ./ft_matrix.out i vec 3 cross "i,2,3+4i" "4+i,5-i,-6i" \
&& echo -e "\n\n		# EX14-07" \
&& echo -e "\n	## Matrix multiplication " \
&& echo && ./ft_matrix.out i mx 2,2 mxv "i,0;0,i" "4,2" \
&& echo && ./ft_matrix.out i mx 2,2 mxv "2+i,0;0,2+i" "4,2" \
&& echo && ./ft_matrix.out i mx 2,2 mxv "2,3-2i;-6i,7+5i" "4,2" \
&& echo && ./ft_matrix.out i nmp 2,2,2 mxm "i,0;0,i" "1,0;0,1" \
&& echo && ./ft_matrix.out i nmp 2,2,2 mxm "2,1;4,2" "i,0;0,i" \
&& echo && ./ft_matrix.out i nmp 4,3,2 mxm "1,0,0,1;0,2i,0,1;0,0,3+4i,1" "0,i;2i,3-8i;-4i,5;6,7i" \
&& echo && ./ft_matrix.out i nmp 4,3,2 mxm "1,0,0,1;0,2i,0,1;0,0,3+4i,1" "0,i;2i,3-8i;-4i,5;6,7i" \
&& echo -e "\n\n		# EX14-08" \
&& echo -e "\n	## Matrix Trace " \
&& echo && ./ft_matrix.out i mx 2,2 trace "1,0;0,i" \
&& echo && ./ft_matrix.out i mx 3,3 trace "2,-5i,0+i;4,3i,7+8i;-2,3,4+5i" \
&& echo -e "\n\n		# EX14-09" \
&& echo -e "\n	## Matrix Transposition " \
&& echo && ./ft_matrix.out i mx 2,3 trans "0,i;2i,3+i;4-5i,-6i" \
&& echo -e "\n\n		# EX14-10" \
&& echo -e "\n	## Reduced Row-Echelon" \
&& echo && ./ft_matrix.out i mx 3,3 rowech "i,0,0;0,i,0;0,0,i" \
&& echo && ./ft_matrix.out i mx 2,2 rowech "1,2i;3+i,4" \
&& echo && ./ft_matrix.out i mx 2,2 rowech "1,2i;4,2+i" \
&& echo && ./ft_matrix.out i mx 4,3 rowech "0,1,1.5,6.5-6.5i;0,2,6,22-28i;0,3i,6.5i,29.5+25.5i" \
&& echo -e "\n\n		# EX14-11" \
&& echo -e "\n	## Determinant" \
&& echo && ./ft_matrix.out i mx 1,1 det "i" \
&& echo && ./ft_matrix.out i mx 1,1 det "1.2-3.4i" \
&& echo && ./ft_matrix.out i mx 2,2 det "i,0;0,i" \
&& echo && ./ft_matrix.out i mx 3,3 det "8,5i,i-2;4+5i,7,20-8i;7,6,1" \
&& echo && ./ft_matrix.out i mx 5,5 det "1,0,0,0,0;0,2i,0,0,0;0,0,3i,0,0;0,0,0,4i,0;0,0,0,0,5" \
&& echo -e "\n\n		# EX14-12" \
&& echo -e "\n	## Inverse" \
&& echo && ./ft_matrix.out i mx 3,3 inv "i,0,0;0,i,0;0,0,i" \
&& echo && ./ft_matrix.out i mx 3,3 inv "2i,0,0;0,2i,0;0,0,2i" \
&& echo && ./ft_matrix.out i mx 3,3 inv "8i,5i,-2;4,7i,20i;7i,6,1i" \
&& echo && ./ft_matrix.out i mx 3,3 inv "1,0,0;0,i,0;0,0,0" \
&& echo -e "\n\n		# EX14-13" \
&& echo -e "\n	## Rank" \
&& echo && ./ft_matrix.out i mx 3,3 rank "i,0,0;0,i,0;0,0,i" \
&& echo && ./ft_matrix.out i mx 2,2 rank "1,2i;3+i,4" \
&& echo && ./ft_matrix.out i mx 2,2 rank "1,2i;4,2+i" \
&& echo && ./ft_matrix.out i mx 4,3 rank "0,1,1.5,6.5-6.5i;0,2,6,22-28i;0,3i,6.5i,29.5+25.5i" \
|| echo "Test Failed" \
;
