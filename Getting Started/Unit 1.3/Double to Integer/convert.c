/*
The population of a city has risen sharply over the past few years, 
thanks to a high birth rate. However, this poses a number of problems, 
including a housing shortage. The mayor has decided to deal with the problem 
and would like to estimate the future growth of the population, and he has called you in to help!

Please write a C-program that first reads an integer representing the 
current population of the city, and that next reads a decimal number for 
the projected population growth as a percentage (either positive or negative). 
The program should then display the expected population of the city in a year as a whole number. 
By convention we will only consider "whole" people. So a population of 31.8 
inhabitants will be considered as having 31 inhabitants. 

Example
Input:
123
7.0
*/
#include <stdio.h>
int main()
{
    printf("Current population: ");
    int current;
    scanf("%d", &current);

    printf("projected population: ");
    double proj;
    scanf("%lf", &proj);

    printf("Expected population: %d", (int) (current + proj));
    return 0;
}