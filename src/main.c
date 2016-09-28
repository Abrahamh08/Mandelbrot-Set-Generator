#include <stdio.h>
#include <complex.h>

int inset(double complex c, int startx, int endx, int starty, int endy);
int main() {
    int startingPointX = -2,
        startingPointY = -2,
        endingPointY = 1;
    double endingPointX = .8;
    double i;
    double j;
    for (j = startingPointY; j < endingPointY; j += .01) {
        putchar('\n');
        for (i = startingPointX; i < endingPointX; i += .003) {
            double complex c = i + j * I;
            int a = inSet(c, startingPointX, endingPointX, startingPointY, endingPointY);
            if (!a) {
                putchar(' ');
            } else {
                char c = '+';
                if (a > 90000) c = '#';
                if (a > 99600) c = '.';
                if (a > 99800) c = ':';
                if (a > 99920) c = ',';
                if (a > 99960) c = '@';
                if (a > 99990) c = '$';
                putchar(c);
            }
        }
    }
    return 0;
}

int inSet(double complex c, int startx, double endx, int starty, int endy) {
    int i;
    double complex z = 0;
    for (i = 100000; i > 0; i--) {
        z = z * z + c;
        if (creal(z) < startx || creal(z) > endx || cimag(z) < starty || cimag(z) > endy) {
            return i;
        }
    }
    return 0;
}
