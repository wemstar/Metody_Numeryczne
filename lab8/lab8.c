#include <stdio.h>
#include <math.h>



double logarytm(double x)
{
	return log(pow(x,5.0)+3.0*pow(x,2.0)+x+9.0);
}

double potega(double x)
{
	return pow(x,6.0);
}


void powell(const char* plik,double(*funkcja)(double),int n,double startx,double h)
{
	double x1,x2,x3;
	x1=startx;
	x2=x1+h;
	x3=x2+h;
	FILE *fp=fopen(plik,"w");
	for(int i=1;i<=n;i++)
	{
		
		

		
	}
	fclose(fp);
}
void plotting(const char *plik,double(*funkcja)(double),int n,double start,double end)
{
	double dx=(end-start)/(double)n;
	FILE *fp=fopen(plik,"w");
	for(int i=0;i<=n;i++)
	{
		double x=start+i*dx;
		double y=funkcja(x);
		fprintf(fp, "%f %f\n",x,y );
	}
	fclose(fp);
}

int main(int argc, char const *argv[])
{
	


	powell("logarytm",logarytm,10,-0.5,0.01);
	powell("logarytm",logarytm,10,-0.9,0.01);
	plotting("log_plot",logarytm,100,-1.5,1);
	return 0;
}