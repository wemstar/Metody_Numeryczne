#include <stdio.h>
#include <math.h>
#include "nr.h"
#include "../../numerical_recipes.c/nrutil.h"
#include "../../numerical_recipes.c/nrutil.c"

float funkcja1(float x)
{
	return sin(x)/x;
}
float funkcja2(float x)
{
	return (cos(x)-exp(x))/sin(x);
}
float funkcja3(float x)
{
	return 1.0/x*exp(-1/x);
}
void drkujMatrix(FILE* fp,float **a,int n)
{
	for(int i=0;i<=n;i++)
	{
		for (int j = 0; j <= n; ++j)
		{
			fprintf(fp,"%10.8f ",a[i][j] );
		}
		fprintf(fp,"\n");
	}
}


float calkuj(const char* plik,float( *funkcja)(float),int n,float a,float b)
{

	float **d=matrix(0,n,0,n);
	d[0][0]=funkcja(a)/2.0+funkcja(b)/2.0;

	for(int m=1;m<=n;m++)
	{
		float h=(b-a)/pow(2.0,m);
		float suma=0;
		for(int i=1;i<=pow(2,m-1);i++)
		{
			suma+=funkcja(a+(2*i-1)*h+0.000001);
		}
		d[m][0]=d[m-1][0]/2.0+h*suma;
	}

	for(int k=1;k<=n;k++)
	{
		for(int m=k;m<=n;m++)
		{
			float k4=pow(4.0,k);
			d[m][k]=( k4*d[m][k-1]-d[m-1][k-1] )/(k4-1);
		}
	}

	FILE* fp=fopen(plik,"w");
	for(int i=0;i<=n;i++)
	{
		fprintf(fp, "%d %10.8f %10.8f \n",i,d[i][0],d[i][i] );
	}
	float wynik=d[n][n];
	free_matrix(d,0,n,0,n);
	fclose(fp);

	return wynik;

}



int main(int argc, char const *argv[])
{
	float wynik1=calkuj("funkcja1.txt",funkcja1,7,0.000001,1);
	float wynik2=calkuj("funkcja2.txt",funkcja2,15,-1,1);
	float wynik3=calkuj("funkcja3.txt",funkcja3,7,0.0000001,1);
	printf("%f\n",wynik1 );
	printf("%f\n",wynik2 );
	printf("%f\n",wynik3 );
	return 0;
}