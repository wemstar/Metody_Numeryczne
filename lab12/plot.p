set term jpeg
set size 1,1


set out 'funkjce8.jpg'
set xlabel 'x2'
set ylabel 'epsylon'

plot  'funkjce8.txt' u 1:2 w l,'' u 1:3 w l

set out 'funkjce10.jpg'
set xlabel 'x2'
set ylabel 'epsylon'

plot  'funkjce10.txt' u 1:2 w l,'' u 1:3 w l

set out 'funkjce12.jpg'
set xlabel 'x2'
set ylabel 'epsylon'

plot  'funkjce12.txt' u 1:2 w l,'' u 1:3 w l
