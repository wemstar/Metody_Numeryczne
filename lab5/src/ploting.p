set term jpeg
set size 0.7,1.0
set out 'n5.jpg'
plot  'inter5.txt' u 1:2 w l, '' u 1:3 w l
set out 'n10.jpg'
plot  'inter10.txt' u 1:2 w l, '' u 1:3 w l
set out 'n15.jpg'
plot  'inter15.txt' u 1:2 w l, '' u 1:3 w l
set out 'n20.jpg'
plot  'inter20.txt' u 1:2 w l, '' u 1:3 w l
