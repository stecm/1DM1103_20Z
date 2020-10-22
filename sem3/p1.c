#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    float x;
    x = atof(argv[1]);
    printf("Wartosc %f do kwadratu to %f\n", x, x*x);
}