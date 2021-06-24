#include <stdio.h>

int main(void)
{
    float speed, size, time;

    printf("Enter the download speed (megabits): ");
    scanf("%f", &speed);
    printf("Enter file size (megabytes): ");
    scanf("%f", &size);
    printf("At %.2f megabits per second, a file of %.2f megabytes\ndownloads in %.2f second.\n", speed, size, size * 8 / speed);
    return 0;
}