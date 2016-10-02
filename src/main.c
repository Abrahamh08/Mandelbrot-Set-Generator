#include <stdio.h>
#include <stdlib.h>
#include <complex.h>

int inSet(unsigned int max, double complex c, int startx, double endx, int starty, int endy) {
    int i;
    double complex z = 0;
    for (i = max; i > 0; i--) {
        z = z * z + c;
        if (creal(z) < startx || creal(z) > endx || cimag(z) < starty || cimag(z) > endy) {
            return i;
        }
    }
    return 0;
}

int main(int argc, char **argv) {
    unsigned int max = 1000;
    if (argc > 1) max = atoi(argv[1]);

    double startingPointX = -2,
           startingPointY = -1,
           endingPointY = 1,
           endingPointX = .8;
    double i, j;

    for (j = startingPointY; j < endingPointY; j += .006) {
        putchar('\n');
        for (i = startingPointX; i < endingPointX; i += .0018) {
            double complex c = i + j * I;
            int a = inSet(max, c, startingPointX, endingPointX, startingPointY, endingPointY);
            if (!a) {
                putchar(' ');
            } else {
                char c = '+';
                if (a > max * 0.9)    c = '#';
                if (a > max * 0.996)  c = '.';
                if (a > max * 0.998)  c = ':';
                if (a > max * 0.9992) c = ',';
                if (a > max * 0.9996) c = '@';
                if (a > max * 0.9999) c = '$';
                putchar(c);
            }
        }
    }

    return 0;
}
