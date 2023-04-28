#include <stdio.h>

int main()
 {
    int botNum, i, power;
    power = 0;
    scanf("%d", &botNum);
    
    for(i = 0; i < botNum; i++)
    {
        int height, weight, enginePower, resistance;
        scanf("%d %d %d %d", &height, &weight, &enginePower, &resistance);
        power += ((enginePower + resistance) * (weight - height));
    }
    printf("%d", power);
    return 0;
 }