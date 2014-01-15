#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define frand() ((double)rand())/(RAND_MAX+1.0)
#define fabs()


void montecarlo(const char* plik,double x0,double y0,double z0,double a,double R,int n,double d)
{
	double vk=0.0;
	double I0=0.0;
	double vs=pow(a,3);
	
	double Id=0;
	double Vdok=4.0/3.0*atan(1)*4.0;
	double Idok=2.0/5.0*Vdok;
	double IDDok=Idok+pow(d,2);
	double vk2=0.0;
	double I02=0.0;
	double Id2=0.0;
	FILE* fp=fopen(plik,"w");
	FILE* fp1=fopen("plik2","w");
	FILE* fp2=fopen("plik3","w");

	for(int i=1;i<=n;i++)
	{
		double tetha=0.0;
		double dI=0;
		double x=a*frand();
		double y=a*frand();
		double z=a*frand();
		double x1=x0+d;
		if((pow(x-x0,2)+pow(y-y0,2)+pow(z-z0,2)) <= pow(R,2))tetha=1.0;

		vk=vk+vs*tetha;
		vk2=vk2+pow(vs*tetha,2);

		I0=I0+vs*tetha*(pow(x-x0,2)+pow(y-y0,2));
		I02=I02+pow(vs*tetha*(pow(x-x0,2)+pow(y-y0,2)),2);

		dI=vs*tetha*(pow(x-x1,2)+pow(y-y0,2));
		Id=Id+dI;
		Id2+=pow(vs*tetha*(pow(x-x1,2)+pow(y-y0,2)),2);
		if(i%100==0)
		{

				fprintf(fp, "%d  %f %f %f\n",i,vk/i,Vdok,sqrt((vk2-pow(vk/i,2)))/i);
				fprintf(fp1, "%d %f %f %f\n",i,I0/i,Idok,sqrt((I02-pow(Id/i,2)))/i);
				fprintf(fp2, "%d %f %f %f\n",i,Id/i,IDDok,sqrt((Id2-pow(Id/i,2)))/i);
						
		}
		
	}
	fclose(fp);
	fclose(fp1);
	fclose(fp2);

}


int main(int argc, char const *argv[])
{
	montecarlo("plik1",1.2,1.2,1.2,2.4,1.0,100000,0.1);
	return 0;
}