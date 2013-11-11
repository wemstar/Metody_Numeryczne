clear
clc

syms x;
y=(log(x)-x)^6;
dy=diff(y);
hold on

po=ezplot(y);
set(po,'Color',[1 0 0]);
ezplot(dy);

legend('funkcja','pochodna')
