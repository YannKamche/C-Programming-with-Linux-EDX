/*
You want to determine the number of cities in a given region that have a population strictly greater than 10,000. To do this, you write a program that first reads the number of cities in a region as an integer, and then the populations for each city one by one (also integers).

Example
Input
6
1000
5000
15000
4780
0
23590
Output
2*/
#include<stdio.h>
int main(){
    int n;
    int i,j;
    scanf("%d",&n);
    for(i=0 ; i<n ; i++){
        for(j=0 ; j<n ; j++){
            printf("*");
        }
        printf("\n");
    }
    return 0;
}