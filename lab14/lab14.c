
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "nr.h"
#include "../../numerical_recipes.c/nrutil.h"
#include "../../numerical_recipes.c/nrutil.c"
#include "../../numerical_recipes.c/erff.c"
#include "../../numerical_recipes.c/gammp.c"
#include "../../numerical_recipes.c/gcf.c"
#include "../../numerical_recipes.c/gser.c"
#include "../../numerical_recipes.c/gammln.c"


float * rozkladJenorodny(const char * plik,long a,long c,long m,int n)
{
	long xn=(a*10+c)%m;
	float *x=malloc(sizeof(float)*n);
	x[0]=xn/(m+1.0);
	FILE* fp=fopen(plik,"w");
	for(int i=1;i<n;i++)
	{
		xn=(a*xn+c)%m;
		x[i]=xn/(m+1.0);
		fprintf(fp, "%f %f\n",x[i],x[i-1]);
	}
	fclose(fp);
	return x;
}
float funkcja(float x,float sigma,float mi)
{
	return exp(-pow(x-mi,2)/(2*sigma*sigma))/(sigma*sqrt(atan(1)*8));
}

float * rozkladNormalny(const char * plik,long a,long c,long m,int n,float sigma,float mi)
{
	int i=0;
	long xn=(a*10+c)%m;
	float *x=malloc(sizeof(float)*n);
	float xx,yy;
	FILE *fp=fopen(plik,"w");
	while(i<n)
	{
		xn=(a*xn+c)%m;
		xx=xn/(m+1.0);
		xx=xx*6*sigma-3*sigma+mi;

		xn=(a*xn+c)%m;
		yy=xn/(m+1.0);
		yy=yy/(sigma*sqrt(atan(1)*8.0));
		if(yy<=funkcja(xx,sigma,mi))
		{
			x[i]=xx;
			i++;
			fprintf(fp, "%f %f\n",xx,yy);
		}
	}
	fclose(fp);
	return x;
}

float srednia(float *x,int n)
{
	float suma=0;
	for(int i=0;i<n;i++)
	{
		suma+=x[i];
	}
	return suma/n;
}
float wariancja(float *x,float srednia,int n)
{
	float suma=0;
	for(int i=0;i<n;i++)
	{
		suma+=pow(x[i]-srednia,2);
	}
	return suma/n;
}
float F(float x,float mi,float sigma)
{
	x=(x-mi)/(sqrt(2)*sigma);
	return (1+erf(x))/2.0;
}
float test(const char * plik,float *x,int n,float mi,float sigma,int tryb)
{
	int* nk=ivector(1,12);
	float* pk=vector(1,12);
	float dx=6*sigma/12;
	for(int i=0;i<n-1;i++)
	{
		
		float a=x[i]-(mi-3*sigma);
		
		a=a/dx;
		int l=(int)a+1;
		//printf("%i\n",l );
		nk[l]++;

	}

	for(int i=1;i<=12;i++)
	{
		float xa=mi-3*sigma+dx*(i-1);
		float xb=xa+dx;


		pk[i]=F(xb,mi,sigma)-F(xa,mi,sigma);
	}
	float hi=0;
	for(int i=1;i<=12;i++)
	{
		hi+=(pow(nk[i]-n*pk[i],2))/(n*pk[i]);

	}
	FILE *fp=fopen(plik,"w");
	float sum=0;
	for(int i=1;i<=12;i++)
	{
		fprintf(fp, "%i %i\n",i,nk[i] );
		sum+=pk[i];
	}
	//fprintf(fp, " suma %f\n",sum );
	//fprintf(fp, " hi %f\n",hi);
	fclose(fp);
	free_vector(pk,1,12);
	free_ivector(nk,1,12);
	return hi;
}


int main(int argc, char const *argv[])
{
	
	float * f1=rozkladJenorodny("plik1",123,1,pow(2,15),10000);
	float*  f2=rozkladJenorodny("plik2",69069,1,pow(2,32),10000);
	float * f3=rozkladNormalny("plik3",69069,1,pow(2,32),10000,0.5,0.2);

	float mi1=srednia(f1,10000);
	float mi2=srednia(f2,10000);
	float mi3=srednia(f3,10000);

	float sigma1=wariancja(f1,mi1,10000);
	float sigma2=wariancja(f2,mi2,10000);
	float sigma3=wariancja(f3,mi3,10000);
	printf("%f %f\n",mi1,sigma1 );
	printf("%f %f\n",mi2,sigma2 );
	printf("%f %f\n",mi3,sigma3 );
	float hi3=test("plik3_2",f3,10000,0.2,0.5,0);

	





	free(f3);
	free(f1);
	free(f2);
	return 0;
}