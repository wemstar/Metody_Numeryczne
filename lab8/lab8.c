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
		double F1=(funkcja(x2)-funkcja(x1))/(x2-x1);
		double F2=((funkcja(x3)-funkcja(x2))/(x3-x2) - (funkcja(x2)-funkcja(x1))/(x2-x1))/(x3-x1);
		double xm=(x1+x2)/2-F1/(2*F2);
		fprintf(fp,"%d %f %f %f %f %f %f\n",i,x1,x2,x3,xm,F1,F2 );
		double dx1=fabs(x1-xm);
		double dx3=fabs(x3-xm);

		if(dx1>dx3)
		{
			x1=x2;
			x2=x3;
			x3=xm;			
		}
		else
		{
			x3=x2;
			x2=x1;
			x1=xm;

		}

		

		
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
	


	powell("logarytm_1",logarytm,10,-0.5,0.01);
	printf("\n");
	powell("logarytm_2",logarytm,10,-0.9,0.01);
	printf("\n");
	powell("potega",potega,100,1.5,0.01);
	//plotting("log_plot",logarytm,100,-1.5,1);
	return 0;
}