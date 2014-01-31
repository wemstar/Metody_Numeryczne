clc;
clear;
fid = fopen('plik3', 'r');
[C D]=fscanf(fid,'%f %*f');
hist(C,12);
fclose(fid);
