set term jpeg
set size 1,1

binwidth=5
bin(x,width)=width*floor(x/width)

set out 'plik1.jpg'
set title 'Generator liniowy '
set xlabel 'X[i]'
set ylabel 'X[i+1]'

plot  'plik1' u 1:2 w p pt 7 ps 0.7 title 'a=123 c=1 m=2^15'

set out 'plik2.jpg'

plot 'plik2' u 1:2 w p pt 7 ps 0.7

set out 'plik3.jpg'

plot 'plik3' u 1:2 w p pt 7 ps 0.7

