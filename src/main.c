#include <stdio.h>
#include <complex.h>

int main() {
  int startingPointX = -3,
      endingPointX = 9,
      startingPointY = -2,
      endingPointY = 3;
  double i;
  double j;
  for (j = startingPointY; j < endingPointY; j += .1) {
    printf("\n");
    for (i = startingPointX; i < endingPointX; i += .05) {
      double complex c = i + j * I;
      if (!inSet(c, startingPointX, endingPointX, startingPointY, endingPointY)) {
        printf("+");
      } else {
        printf(" ");
      }
    }
  }
  return 0;
}

int inSet(double complex c, int startx, int endx, int starty, int endy) {
  int i;
  double complex z = 0;
  for (i = 100; i > 0; i--) {
    z = z * z + c;
    if (creal(z) < startx || creal(z) > endx || cimag(z) < starty || cimag(z) > endy) {
      return 1;
    }
  }
  return 0;
}
