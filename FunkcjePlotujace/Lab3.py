__author__ = 'wemstar'
from pylab import *

def czytaj(plik):
    i=[]
    fx=[]
    x0=[]
    e=[]
    p=[]
    for line in open(plik,'r'):
        sline=line.split()
        i.append(int(sline[0]))
        fx.append(float(sline[1]))
        x0.append(float(sline[2]))
        e.append(float(sline[3]))
        p.append(float(sline[4]))



    return i,fx,x0,e,p

def wykres(file):

    [i,fx,x0,e,p]=czytaj(file+".txt")
    figure()

    plt.plot(i,p);
    ylim([0,2])
    savefig(file+'.png')
    show()
wykres("sieczne_log")
wykres("sieczne_wile")
