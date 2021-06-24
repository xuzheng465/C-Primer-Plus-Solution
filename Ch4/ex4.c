#include <stdio.h>

int main(void)
{
    char *name;
    float height;

    printf("Enter your name: ");
    scanf("%s", name);
    printf("Enter your height in centimeters: ");
    scanf("%f", &height);
    printf("%s, you are %.2f meter tall\n", name, height / 100);
    return 0;
}