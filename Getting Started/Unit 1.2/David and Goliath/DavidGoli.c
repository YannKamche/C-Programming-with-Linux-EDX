#include <stdio.h>

int main()
 {
    int botNum, i, power;
    power = 0;
    printf("Number of robots: ");
    scanf("%d", &botNum);
    
    for(i = 0; i < botNum; i++)
    {
        int height, weight, enginePower, resistance;
        printf("Enter the height, weight, power and resistance of robot %d: ", ++i);
        
        scanf("%d %d %d %d", &height, &weight, &enginePower, &resistance);
        power += ((enginePower + resistance) * (weight - height));
    }
    printf("The power is : %d", power);
    return 0;
 }