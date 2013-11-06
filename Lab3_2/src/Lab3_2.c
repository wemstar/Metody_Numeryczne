#include <stdio.h>
#include <math.h>
#include "newton.h"
#include "funkcje.h"

int main(int argc, const char* argv[]) {

  double x0=newton(f1,3.0,20,1.0);
  printf("%f",x0);;
  return 0;
}