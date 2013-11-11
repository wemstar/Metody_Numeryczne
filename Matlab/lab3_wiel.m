clear
clc

syms x;
y=x^3+2*x^2-3*x+4
dy=diff(y);
hold on

po=ezplot(y);
set(po,'Color',[1 0 0]);
ezplot(dy);

legend('funkcja','pochodna')
