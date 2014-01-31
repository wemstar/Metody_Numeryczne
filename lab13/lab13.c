#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "nr.h"
#include "/home/labs/komputerowe_symulacje_numeryczne/numerical_recipes.c/nrutil.h"
#include "/home/labs/komputerowe_symulacje_numeryczne/numerical_recipes.c/nrutil.c"
#include "/home/labs/komputerowe_symulacje_numeryczne/numerical_recipes.c/tred2.c"
#include "/home/labs/komputerowe_symulacje_numeryczne/numerical_recipes.c/pythag.c"
#include "/home/labs/komputerowe_symulacje_numeryczne/numerical_recipes.c/tqli.c"
float wartosc(float i,float j)
{
	return sqrt(i+j);
}
float* matrixXVector(float **A,float *b,int n)
{
	float* wynik=vector(1,n);
	for(int i=1;i<n;++i)
	for(int j=1;j<=n;j++)wynik[i]+=A[i][j]*b[j];
	return b;
}
void diagol(int n)
{
	FILE* fp=fopen("plik.txt","w");
	float **A=matrix(1,n,1,n);
	float **A0=matrix(1,n,1,n);
	float **Y=matrix(1,n,1,n);
	float *d=vector(1,n);
	float *e=vector(1,n);

	for(int i=1;i<=n;i++)
	{			
			for(int j=1;j<=n;j++)
			{
				if(i==j)Y[i][j]=1.0;
				else Y[i][j]=0;
			}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			A[i][j]=wartosc(i,j);

	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			A0[i][j]=wartosc(i,j);
	tred2(A,n,d,e);
	tqli(d,e,n,Y);
	fprintf(fp, "Macierz P\n");
	for(int i=1;i<=n;i++)
	{		
		for(int j=1;j<=n;j++)
			fprintf(fp, "%f ",A[i][j]);
		fprintf(fp, "\n");
	}
	fprintf(fp, "Macierz Y\n");
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			fprintf(fp, "%f ",Y[i][j]);
		fprintf(fp, "\n");
	}
	fprintf(fp, "Wrtości własne \n");
	for(int i=1;i<=n;i++)fprintf(fp, "%f \n",d[i]);
	fprintf(fp, "Wrtości własne Bk\n");	
	for(int k=1;k<=n;k++)
	{
		float *xk=vector(1,n);
		for(int i=1;i<=n;++i)
		{
			xk[i]=0;
			for(int j=1;j<=n;j++)
			xk[i]+=A[i][j]*Y[j][k];
		}

		float *xxk=vector(1,n);
		for(int i=1;i<=n;++i)
		{
			xxk[i]=0;
			for(int j=1;j<=n;j++)
				xxk[i]+=A0[i][j]*xk[j];
		}
		float L=0,M=0;
		for(int i=1;i<=n;i++)L+=xk[i]*xxk[i];
		for(int i=1;i<=n;i++)M+=xk[i]*xk[i];
		float Bk=L/M;
		fprintf(fp,"%f %f %f\n",Bk,L,M );
		free_vector(xk,1,n);
		free_vector(xxk,1,n);


	}
	fclose(fp);
	free_vector(d,1,n);
	free_vector(e,1,n);
	free_matrix(A,1,n,1,n);
	free_matrix(A0,1,n,1,n);
	free_matrix(Y,1,n,1,n);
	

}
int main(int argc, char const *argv[])
{
	diagol(5);
	return 0;
}