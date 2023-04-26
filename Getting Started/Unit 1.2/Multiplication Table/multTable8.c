/*
0x8 = 0
1x8 = 8
...
10x8 = 80
*/
#include <stdio.h>

int main()
{
    int i;
    for(i = 0; i < 11; i++)
    {
        printf("%dx8 = %d\n", i, i*8);
    }
    return 0;
}