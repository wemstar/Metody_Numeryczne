fid = fopen('plik3', 'r');
[C D]=fscanf(fid,'%f %*f');
[f,x]=hist(C,12);
z=min(x):0.01:max(x);
g=1/(0.5*sqrt(2*pi))*exp(-((z-0.2).^2)/(2*0.5^2));


dx = diff(x(1:2))
bar(x,f/sum(f*dx));hold on
plot(z,g,'r');hold off