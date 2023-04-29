/*
Petra, Rémi and their families went hiking in the mountains together 
and realized that distances are measured 
in different units in France and the United States. To help them convert between units, 
please write a program that reads a decimal number representing a 
distance in kilometers and that prints out the corresponding distance 
in miles with 6 decimal places. 

You may use the fact that one kilometer equals 0.621371 miles. 

Example
Input:
4.8
Output: 
2.982581
*/

#include <stdio.h>

int main()
{
    printf("Enter the distance(km): ");
    double dis_km;
    scanf("%lf", &dis_km);

    printf("%.6f", dis_km * 0.621371);
    return 0;
}