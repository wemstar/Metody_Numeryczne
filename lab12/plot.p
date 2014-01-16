set term jpeg
set size 1,1


set out 'n5.jpg'
set xlabel 'x2'
set ylabel 'epsylon'

plot  'fourier1.txt' u 1:2 w l,'' u 1:3 w l
set out 'four.jpg'
set xlabel 'x2'
set ylabel 'epsylon'

plot 'transformataf.txt' u 1:2 w l