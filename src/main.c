#include <stdio.h>
#include <complex.h>

int inset(double complex c, int startx, int endx, int starty, int endy);
int main() {
  int startingPointX = -4,
      endingPointX = 6,
      startingPointY = -2,
      endingPointY = 3;
  double i;
  double j;
  for (j = startingPointY; j < endingPointY; j += .1) {
    printf("\n");
    for (i = startingPointX; i < endingPointX; i += .05) {
      double complex c = i + j * I;
      int a = inSet(c, startingPointX, endingPointX, startingPointY, endingPointY);
      if (!a) {
        putchar('/');
      } else {
        char c = '+';
        if (a > 30) c = '.';
        if (a > 85) c = ' ';
        putchar(c);
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
      return i;
    }
  }
  return 0;
}
