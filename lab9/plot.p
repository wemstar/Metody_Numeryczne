set term jpeg
set size 1,1



set out 'R1.jpg'
set xlabel 'iteracja'
set ylabel 'wartośc całki'
set title 'wartośc całki dla funkcji sin(x)/x '
plot  'funkcja1.txt' u 1:2 w l title 'D(n,0)','' u 1:3 w l title 'D(n,n)'

set out 'R2.jpg'
set xlabel 'iteracja'
set ylabel 'wartośc całki'
set title 'wartośc całki dla funkcji (cos(x)-exp(x))/sin(x)'
plot  'funkcja2.txt' u 1:2 w l title 'D(n,0)','' u 1:3 w l title 'D(n,n)'

set out 'R3.jpg'
set xlabel 'iteracja'
set ylabel 'wartośc całki'
set title 'wartośc całki dla funkcji 1/(exp(x)*x) '
plot  'funkcja3.txt' u 1:2 w l title 'D(n,0)','' u 1:3 w l title 'D(n,n)'