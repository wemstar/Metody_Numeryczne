#include <stdio.h>
#include <math.h>
#include "newton.h"
#include "funkcje.h"

int main(int argc, const char* argv[]) {

  printf("newton \n funkcja lograrytmicza \n");
  double x0=newton(f1,3.0,20,1.0);
  printf("%f\n",x0);
  printf("wielomian \n");
  double x1=newton(f2,-20.0,20,-3.284277537306950);
  printf("%f\n",x1);

  printf("sieczne \n funkcja lograrytmicza \n");
  double x2=sieczne(f1,3.01,3.0,20,1.0);
  printf("%f\n",x2);
  printf("wielomian \n");
  double x3=sieczne(f2,-20.1,-20.0,20,-3.284277537306950);
  printf("%f\n",x3);




  return 0;
}