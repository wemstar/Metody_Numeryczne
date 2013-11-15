#include <stdio.h>
#include "../../numerical_recipes.c/nr.h"
#include "../../numerical_recipes.c/nrutil.h"
#include "../../numerical_recipes.c/nrutil.c"
#include "../../numerical_recipes.c/gaussj.c"
#include <math.h>
float funkcja( float x){
	return exp(-pow(x,2));
}
float interpoluj(float *xw,float *yw, int n, float x){
int i,j;
float licz,mian, Wn=0.0;
for(j=0;j<=n;j++){
	licz=1.0;
	mian=1.0;
	for(i=0;i<=n;i++){
		if(i==j) continue;
		licz*=x-xw[i];
		mian*=xw[j]-xw[i];

	}
	Wn+=yw[j]*licz/mian;

}
return Wn;
}
void inter(int n,const char *plik)
{
	float *xw, *yw, dx, xm=5, h, k=100,x;
	FILE *fp;
	fp=fopen(plik,"w");

	xw=vector(1,n);
	yw=vector(1,n);

	dx=2*xm/n;
	for(int i=0;i<=n;i++)
	{
			xw[i]=-xm+dx*i;
			yw[i]=funkcja(xw[i]);
	}

	h=2*xm/k;
	for(int i=0;i<=k;i++)
	{
		x=-xm+h*i;
		x=(10*cos(3.14*(2*i+1)/(2*k+2)))/2;
		printf(" %f",x);
		fprintf(fp,"%f %f %f\n", x, funkcja(x), interpoluj(xw,yw,n,x));
	}
}
int main(){

inter(5,"inter5.txt");
inter(10,"inter10.txt");
inter(15,"inter15.txt");
inter(20,"inter20.txt");
return 0;
}