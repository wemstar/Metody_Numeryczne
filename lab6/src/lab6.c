#include <stdio.h>
#include "nr.h"
#include "../../numerical_recipes.c/nrutil.h"
#include "../../numerical_recipes.c/nrutil.c"
#include "../../numerical_recipes.c/ludcmp.c"
#include "../../numerical_recipes.c/lubksb.c"
#include "../../numerical_recipes.c/gaussj.c"
float funkcjaWymierna(float x)
{
    return 1/(1+x*x);
}

void printVector(float **v,int s,int n)
{
    for(int i=s;i<=n;i++)printf(" %d %f \n",i,v[i][1]);
}
float funkcjaTheta(float x,int i,float dx,float *xw,int n)
{
    float fi=0;
    if(x>xw[0]&& x<xw[n+1])
    {
        if(x>=xw[i-2]&& x<xw[i-1])return pow(x-xw[i-2],3)/pow(dx,3);;
        if(x>=xw[i-1]&& x<xw[i])
        {
            return (pow(dx,3)+3*pow(dx,2)*(x-xw[i-1])+3*dx*pow(x-xw[i-1],2)-3*pow(x-xw[i-1],3))/pow(dx,3);;
                
        }
        if(x>=xw[i]&& x<xw[i+1])
        {
            return (pow(dx,3)+3*pow(dx,2)*(xw[i+1]-x)+3*dx*pow(xw[i+1]-x,2)-3*pow(xw[i+1]-x,3))/pow(dx,3);;
        }
        if(x>=xw[i+1] && x< xw[i+2])return pow(xw[i+2]-x,3)/pow(dx,3);
    }
    return 0;
}





void interpoluj(const char * plik,const char* plikc,float (*function)(float ),int n,float xmax)
{
    
    float dx=2*xmax/(n-1);
    float *xw=vector(0,n+1);
    float *yw=vector(1,n);
    for(int i=0;i<=(n+1);i++)xw[i]=-xmax+dx*(i-1);
    for(int i=1;i<=n;i++)yw[i]=function(xw[i]);   
    float **a=matrix(1,n,1,n);
    float **b=matrix(1,n,1,1);
    for(int i=1;i<n;i++)
    {
        a[i][i]=4;
        a[i][i+1]=1;
        a[i+1][i]=1;
        b[i][1]=yw[i];
    }
    a[n][n]=4;
    b[n][1]=yw[n];
    b[n][1]-=dx/3*(function(xw[n]+0.01)-function(xw[n]-0.01))/0.02;
    b[1][1]+=dx/3*(function(xw[1]+0.01)-function(xw[1]-0.01))/0.02;
    a[1][2]=2;
    a[n][n-1]=2;
    gaussj(a,n,b,1);
    //printVector(b,1,n);
    float *c=vector(0,n+1);
    for(int i=1;i<=n;i++)c[i]=b[i][1];
    FILE *fp=fopen(plik,"w");
    int k=1000;
    c[0]=-dx/3*(function(xw[n]+0.01)-function(xw[n]-0.01))/0.02+c[2];
    c[n+1]=dx/3*(function(xw[n]+0.01)-function(xw[n]-0.01))/0.02+c[n-1];;
    for(int i=1;i<=k;i++)
    {
        float x=-xmax+2*i*xmax/k;
        float suma=0;
        for(int j=0;j<=n;j++)
        {
           suma+= c[j]*funkcjaTheta(x,j,dx,xw,n);
        }

        fprintf(fp, "%f %f %f\n",x,suma,function(x));
    }
    fclose(fp);
    FILE *fp1=fopen(plikc,"w");
    for(int i=0;i<=n+1;i++)
    {
        fprintf(fp1, "c[%d] %f\n",c[i]);
    }
    fclose(fp1);

   




}
float mcos(float x)
{
    return cos(x);
}


int main(int argc, const char* argv[]) {



  /*interpoluj("wymier_5.txt","wymier_5C.txt",funkcjaWymierna,5,5);
  interpoluj("wymier_6.txt","wymier_6C.txt",funkcjaWymierna,7,5);
  interpoluj("wymier_10.txt","wymier_10C.txt",funkcjaWymierna,10,5);
  interpoluj("wymier_20.txt","wymier_20C.txt",funkcjaWymierna,20,5);*/

  interpoluj("cos_5.txt","cos_5C.txt",mcos,6,5);
  interpoluj("cos_7.txt","cos_7C.txt",mcos,7,5);
  interpoluj("cos_14.txt","cos_14C.txt",mcos,14,5);

  return 0;
}