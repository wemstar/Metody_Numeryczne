set term jpeg
set size 1,1


set size 0.7,1.0
set out 'cos_14.jpg'
set xlabel 'x'
set ylabel 'y'
set title 'Funkcja cos(2x) sklejanie w bazie n=14 '
plot  'log_plot' u 1:2 w l