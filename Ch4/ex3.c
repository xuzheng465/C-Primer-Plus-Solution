#include <stdio.h>

int main(void)
{
    float num;
    printf("Enter a number: ");
    scanf("%f", &num);
    printf("The input is %.1f or %.01e\n", num, num);
    printf("The input is %+.3f or %.3E\n", num, num);
}