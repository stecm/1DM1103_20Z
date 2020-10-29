#include <stdio.h>

int dlugosc(char *napis[])
{
    int i = 0;
    while(napis[i] != 0)
    {
        i++;
    }
    return i;
}
int main(int argc, char *argv[])
{
    char napis[255];
    printf("%c (%d)", argv[1], dlugosc(argv[1]));
    return 0;
}