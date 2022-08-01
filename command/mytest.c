#include "stdio.h"

int main()
{
    char keys[128];

    int r = read(0, keys, 128);
    printf("%c%c%c",keys[0],keys[1],keys[2]);
}
