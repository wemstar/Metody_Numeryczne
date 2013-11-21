#include <stdio.h>
#include "../../numerical_recipes.c/nr.h"
#include "../../numerical_recipes.c/nrutil.h"
#include "../../numerical_recipes.c/nrutil.c"
float funkcjaWymierna(float x)
{
    return 1/(1+x*x);
}

void printVector(float *v,int s,int n)
{
    for(int i=s;i<=n;i++)printf("%f ",v[i]);
}
float drugaPochodna(float (*function)(float ),float x,float h)
{
      float licznik=function(x-h)-2*function(x)+function(x+h);
      float mianownik=h*h;
      return licznik/mianownik;
}
float* valueAtRange(float (*function)(float),float *xw,int n)
{
    float *yw=vector(1,n);
    for(int i=1;i<=n;i++) yw[i]=function(xw[i]);
    return yw;
}
void wyzM(float *xw,float *yw,float *w,int n,float alfa,float beta)
{

    float **a=matrix(1,n,1,n);
    float **d=matrix(1,n,1,1);
    for(int i=2;i<n;i++)
    {
        float hi =xw[i]-xw[i-1];
        float hi1=(xw[i+1]-xw[i]);
        a[i][i+1]= hi1/(hi1+hi) ;
        a[i][i-1]=1-a[i][i+1];
        d[i][1]= 6/(hi+hi1)*( (yw[i+1]-yw[i])/hi1 -(yw[i]-yw[i-1])/hi );
    }
}

float * getRange(float a,float b,int n)
{
    float *wektor=vector(1,n);
    float dx= (b-a)/n;
    for(int i=1;i<=n;i++)wektor[i]=a+i*dx;
    return wektor;
}


void interpoluj(const char * plik,float (*function)(float ),int n)
{
    float a=-5;
    float b=5;
    float *xw=getRange(a,b,n);
    float *yw=valueAtRange(function,xw,n);
    float *w=vector(1,n);
    wyzM(xw,yw,w,n,0,0);
    printVector(yw,1,n);


}
int main(int argc, const char* argv[]) {



  interpoluj("Cos.txt",funkcjaWymierna,10);
  return 0;
}