#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "nr.h"
#include "/home/labs/komputerowe_symulacje_numeryczne/numerical_recipes.c/nrutil.h"
#include "/home/labs/komputerowe_symulacje_numeryczne/numerical_recipes.c/nrutil.c"
#include "/home/labs/komputerowe_symulacje_numeryczne/numerical_recipes.c/four1.c"
#define frand() ((double)rand())/(RAND_MAX+1.0)



float signal(float t,float T)
{
	float omega=atan(1)*8.0/T;
	return sin(omega*t)+sin(2*omega*t)+sin(3*omega*t);
}
float szum(float t,float T){return signal(t,T)+frand()-0.5;}
float wagi(float t,float T)
{
	float sigma=T/20.0;
	float wynik=exp(-pow(t,2.0)/(2.0*pow(sigma,2)))/(sigma*sqrt(atan(1.0)*8.0));
	return wynik;
}
void fourier(int k, float T,float tmax)
{
	float Nk=pow(2,k);
	float dt=tmax/Nk;
	float *f0=vector(1,2*Nk);
	float *f=vector(1,2*Nk);
	float *g1=vector(1,2*Nk);
	float *g2=vector(1,2*Nk);

	FILE* fp;


	if(k==8){fp=fopen("funkjce8.txt","w");}
	if(k==10){fp=fopen("funkjce10.txt","w");}
	if(k==12){fp=fopen("funkjce12.txt","w");}
	
	for(int i=1;i<=Nk;i++)
	{
		float t=(i-1)*dt;
		f0[2*i-1]=signal(t,T);
		f0[2*i]=0.0;

		f[2*i-1]=szum(t,T);
		f[2*i]=0.0;

		g1[2*i-1]=wagi(t,T);
				
		g1[2*i]=0;

		g2[2*i-1]=g1[2*i-1];
		g2[2*i]=g1[2*i];

	}
	four1(f,Nk,1);
	four1(g1,Nk,1);
	four1(g2,Nk,-1);
	for(int i=1;i<=2*Nk;++i){g1[i]=g1[i]+g2[i];	}

	for(int i=1;i<=Nk;++i)
	{
		float a1=f[2*i-1];
		float b1=f[2*i];
		float a2=g1[2*i-1];
		float b2=g1[2*i];
		f[2*i-1]=a1*a2-b1*b2;
		f[2*i]=a1*b2+a2*b1;
	}

	four1(f,Nk,-1);

	float f_max=0;
	for(int i=1;i<=Nk;++i)if(fabs(f[2*i-1])>f_max)f_max=fabs(f[2*i-1]);
	for(int i=1;i<=Nk;++i)fprintf(fp, "%d %f %f\n",i,f0[2*i-1],f[2*i-1]*2.5/f_max );

	fclose(fp);
	free_vector(f0,1,2*Nk);
	free_vector(f,1,2*Nk);
	free_vector(g1,1,2*Nk);
	free_vector(g2,1,2*Nk);
}
int main(int argc, char const *argv[])
{
	fourier(8, 1.0,3.0);
	fourier(10, 1.0,3.0);
	fourier(12, 1.0,3.0);
	return 0;
}