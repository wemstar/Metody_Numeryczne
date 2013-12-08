set term jpeg
set size 1,1


set size 0.7,1.0
set out 'logarytm_1f(i).jpg'
set xlabel 'iteracja'
set ylabel 'przybliżenie'
set title 'Położenie przybliżenia od iteracji '
plot  'logarytm_1' u 1:5 w l   title 'xm=f(i)'

set out 'logarytm_2f(i).jpg'
set xlabel 'iteracja'
set ylabel 'przybliżenie'
set title 'Położenie przybliżenia od iteracji '
plot  'logarytm_2' u 1:5 w l  title 'xm=f(i)'

set out 'potegaf(i).jpg'
set xlabel 'iteracja'
set ylabel 'przybliżenie'
set title 'Położenie przybliżenia od iteracji '
plot  'potega' u 1:5 w l title 'xm=f(i)'








set size 0.7,1.0
set out 'logarytm_1F1(i).jpg'
set xlabel 'iteracja'
set ylabel 'Iloraz różnicowy'
set title 'Iloraz różnicowy od iteracji '
plot  'logarytm_1' u 1:6 w l title 'pierwszego rzędu',''u 1:7 w l title 'drugiego rzędu'

set out 'logarytm_2F1(i).jpg'
set xlabel 'iteracja'
set ylabel 'Iloraz różnicowy'
set title 'Iloraz różnicowy od iteracji '
plot  'logarytm_2' u 1:6 w l title 'pierwszego rzędu',''u 1:7 w l title 'drugiego rzędu'

set out 'potegaF1(i).jpg'
set xlabel 'iteracja'
set ylabel 'Iloraz różnicowy'
set title 'Iloraz różnicowy od iteracji '
plot  'potega' u 1:6 w l title 'pierwszego rzędu',''u 1:7 w l title 'drugiego rzędu'