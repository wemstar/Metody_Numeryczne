set term jpeg
set size 1,1


set out 'n5.jpg'
set xlabel 'x2'
set ylabel 'epsylon'

plot  'n5.dat' u 1:4 w l,'n10.dat' u 1:4 w l,'n15.dat' u 1:4 w l,'n20.dat' u 1:4 w l,'n25.dat' u 1:4 w l,'n30.dat' u 1:4 w l,'n35.dat' u 1:4 w l