#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int main(void)
{
    long long int number,l;
    char string[20];
    
    printf("Enter a number: ");
    scanf("%d", &number);
    
    itoa(number,string,100000000);
    
    printf("String value = %s\n", string);
    
    return 0;
}