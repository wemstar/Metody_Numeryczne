#include <stdio.h>


#include <math.h>
#include "nr.h"
#include "../../numerical_recipes.c/nrutil.h"
#include "../../numerical_recipes.c/nrutil.c"

#include "../../numerical_recipes.c/gaussj.c"

float gaus(float x)
{
    float y=-pow(x-2,2)/(2*8);
    return exp(y);
}
float* interpoluj(const char * plik,float (*function)(float ),int n,float x0,float xmax)
{

    float dx=x0+2*xmax/(n-1);
    float *xw=vector(0,n+1);
    float *yw=vector(1,n);
    for(int i=0;i<=(n+1);i++)xw[i]=-xmax+dx*(i-1)+x0;;
    for(int i=1;i<=n;i++)yw[i]=function(xw[i]);

    float** g=matrix(1,n,1,n);
    float** b=matrix(1,n,1,1);
    for(int i=1;i<=n;i++)
    {
        for(int k=1;k<=n;k++)
        {
            float sum=0;
            for(int j=1;j<=n;++j)
            {
                sum+=pow(xw[j],i+k-2);
            }
            g[i][k]=sum;
        }
    }
    for(int k=1;k<=n;k++)
    {
        for(int j=1;j<=n;j++)
        {
            b[k][1]+=yw[j]*pow(xw[j],k-1);
        }
    }
    gaussj(g,n,b,1);
    float *a=vector(1,n);
    for(int i=1;i<=n;i++)a[i]=b[i][1];

    return a;







}
int main(int argc, const char* argv[]) {
  float* a=interpoluj("cos",gaus,11,2,12);
  for(int i=1;i<=11;i++)printf("%f \n",a[i]);
  return 0;
}