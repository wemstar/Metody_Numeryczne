set term jpeg
set size 1,1



set out 'obj.jpg'
set title 'Objętośc kuli'
set xlabel 'ilość iteracji'
set ylabel 'Objętośc kuli'
plot  'plik1' u 1:2 w l,'plik1' u 1:3 w l

set out 'moment1.jpg'
set title 'Moment bezwładności kuli'
set xlabel 'ilość iteracji'
set ylabel 'Moment bezwładności'
plot  'plik2' u 1:2 w l,'plik2' u 1:3 w l

set out 'moment2.jpg'
set title 'Moment bezwładności Tw. Steinera kuli'
set xlabel 'ilość iteracji'
set ylabel 'Moment bezwładności '
plot  'plik3' u 1:2 w l,'plik2' u 1:3 w l

set out 'objerror.jpg'
set title 'odchylenie statndarowe objętośći'
set xlabel 'ilość iteracji'
set ylabel 'odchylenie standardowe'
plot  'plik1' u 1:4 w l

set out 'moment1erro.jpg'
set title 'momentu bezwładności'
set xlabel 'ilość iteracji'
set ylabel 'odchylenie standardowe'
plot  'plik2' u 1:4 w l

set out 'moment2erro.jpg'
set title 'Tw Steinera'
set xlabel 'ilość iteracji'
set ylabel 'odchylenie standardowe'
plot  'plik3' u 1:4 w l


 