
double pochodna(double(*funkcja)(double x),double x0,double h)
 {
     return (funkcja(x0+h)-funkcja(x0))/h;
 }

double obliczP(double e2,double e1,double e0)
{
    double licznik = log(e1/e2);
    double mianownik=log(e0/e1);

    return licznik / mianownik;

}

double newton(double (*funkcja)(double x),double startx,int n,double x0 )
{

     double e2=1;
     double e1=1.25;
     double e0=1;
     for(int i=0;i<n;i++)
     {

         startx=startx-funkcja(startx)/pochodna(funkcja,startx,0.0001);
         e0=e1;
         e1=e2;
         e2=startx-x0;
         double p=1;
         if(i>2)p=obliczP(e2,e1,e0);


         printf("%25.15f %25.15f %25.15f %f\n",funkcja(startx),startx,e2,p);

     }
     return startx;
}



