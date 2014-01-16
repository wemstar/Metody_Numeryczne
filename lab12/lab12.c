#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "../nr.h"
#include "../nrutil.h"
#include "../nrutil.c"
#include "../../numerical_recipes.c/four1.c"
#define frand() ((double)rand())/(RAND_MAX+1.0)



float signal(float t,float T)
{
	float omega=atan(1)*8.0/T;
	return sin(omega*t)+sin(2*omega*t)+sin(3*omega*t);
}
float szum(float t,float T)
{
	return signal(t,T)+frand()-0.5;
}
float wagi(float t,float T)
{
	float sigma=t/20.0;
	return 1/(sigma*sqrt(2*atan(1)*4))*exp(-pow(t,2.0)/(2*pow(sigma,2)));

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
	FILE* fp2;

	if(k==8){fp=fopen("funkjce8.txt","w");fp2=fopen("transformata8.txt","w");}
	if(k==10){fp=fopen("funkjce10.txt","w");fp2=fopen("transformata10.txt","w");}
	if(k==12){fp=fopen("funkjce12.txt","w");fp2=fopen("transformata12.txt","w");}
	
	for(int i=1;i<=Nk;i++)
	{
		float t=i*dt;
		f0[2*i-1]=signal(t,T);
		f0[2*i]=0.0;

		f[2*i-1]=szum(t,T);
		f[2*i]=0.0;

		g1[2*i]=wagi(t,T);				
		g1[2*i-2]=wagi(t,T);

		g2[2*i]=g1[2*i];
		g2[2*i-2]=g1[2*i-2];

		fprintf(fp, "%d %f %f\n",i,f0[2*i-1],f[2*i-1]);

	}
	four1(f,Nk,1);
	for(int i=1;i<=2*Nk;++i)
	{
		fprintf(fp2, "%d %f\n",i,f[i]);
	}
	fclose(fp);
	fclose(fp2);
	free_vector(f0,1,2*Nk);
	free_vector(f,1,2*Nk);
	free_vector(g1,1,2*Nk);
	free_vector(g2,1,2*Nk);
}
int main(int argc, char const *argv[])
{
	fourier(8, 1.0,3.0);
	return 0;
}