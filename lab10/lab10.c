#include <stdio.h>
#include <math.h>
#include "nr.h"
#include "../../numerical_recipes.c/nrutil.h"
#include "../../numerical_recipes.c/nrutil.c"
#include "../../numerical_recipes.c/bessi0.c"
#include "../../numerical_recipes.c/gauher.c"


int main(int argc, char const *argv[])
{
	for(int n=5;n<=35;n+=5)
	{
		FILE *fp;
		if(n==5)fp=fopen("n5.dat","w");
		if(n==10)fp=fopen("n10.dat","w");
		if(n==15)fp=fopen("n15.dat","w");
		if(n==20)fp=fopen("n20.dat","w");
		if(n==25)fp=fopen("n25.dat","w");
		if(n==30)fp=fopen("n30.dat","w");
		if(n==35)fp=fopen("n35.dat","w");

		int m=n+1;

		float* x1=vector(1,n);
		float* w1=vector(1,n);		
		float* x2=vector(1,m);
		float* w2=vector(1,m);  

		gauher(x1,w1,n);
		gauher(x2,w2,m);

		for(float x20=0.0;x20<=6.0;x20+=0.1)
		{
			
			float sigma=1/sqrt(2);
			float iloczyn=pow(x20,2)/(8*pow(sigma,2));
			float Vdok=pow(2*atan(1)*4,2)*pow(sigma,4)*sqrt(atan(1)*4)/(2*sigma)*exp(-iloczyn)*bessi0(iloczyn);

			float Vnum=0;
			for(int k1=1;k1<=n;++k1)
			for(int m1=1;m1<=n;++m1)
			for(int k2=1;k2<=m;++k2)
			for(int m2=1;m2<=m;++m2)
			{
				float mianownik=(sqrt(pow(x1[k1]-x2[k2]-x20,2)+pow(x1[m1]-x2[m2],2)));
				Vnum+=(w1[k1]*w1[m1]*w2[k2]*w2[m2])/mianownik;

			};
			fprintf(fp, "%10.8f %10.8f %10.8f %10.8f\n",x20,Vdok,Vnum,fabs((Vdok-Vnum)/Vdok) );
			printf("%10.8f %10.8f %10.8f %10.8f\n",x20,Vdok,Vnum,fabs((Vdok-Vnum)/Vdok)) ;

			
		}

		free_vector(x1,1,n);
		free_vector(w1,1,n);
		free_vector(x2,1,m);
		free_vector(w2,1,m);


		fclose(fp);
	}
	return 0;
}