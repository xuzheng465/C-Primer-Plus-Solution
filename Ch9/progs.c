#include <stdio.h>
#include "ch9pro.h"

void printchars(char, int, int);
void larger_of(double *, double *);
void threeorder(double *, double *, double *);
int checkchar(char);
void checkchars();
void to_base_n(unsigned long n, int base);

int main(void)
{
    double x = 9.0;
    double y = 10.0;
    printf("the min between x and y is %.2f\n", min(x, y));
    printf("\nProg 3\n");
    printchars('a', 3, 5);
    printf("\nProg 5\n");
    printf("Original x is %.2f and y is %.2f\n", x, y);
    larger_of(&x, &y);
    printf("New x is %.2f and y is %.2f\n", x, y);

    double a = 1.0, b = 2.0, c = 3.0;
    // ex6
    threeorder(&a, &b, &c);
    printf("a is %.2f, b is %.2f, c is %.2f\n", a, b, c);
    printf("a is %d\n", 'a');
    printf("z is %d\n", 'z');
    printf("A is %d\n", 'A');
    printf("Z is %d\n", 'Z');
    printf("Location of a is %d\n", 'a' - 96);
    // if 97<=char<=122 -96
    // if 65<=char<=90 -64
    // ex7
    //checkchars();
    to_base_n(27, 8);
    putchar('\n');
}

void printchars(char c, int reps, int lines)
{
    for (int i = 0; i < lines; i++)
    {
        for (int j = 0; j < reps; j++)
        {
            putchar(c);
        }
        putchar('\n');
    }
}

void larger_of(double *x, double *y)
{
    if (*x > *y)
        *y = *x;
    else
        *x = *y;
}

void threeorder(double *first, double *second, double *third)
{
    int big = 0;
    int middle = 0;
    int small = 0;
    if (*first > *second)
    {
        if (*first > *third)
        {
            big = *first;
            if (*second > *third)
            {
                middle = *second;
                small = *third;
            }
            else
            {
                middle = *third;
                small = *second;
            }
        }
        else // first < third
        {
            big = *third;
            middle = *first;
            small = *second;
        }
    }
    else // first < second
    {
        if (*first < *third)
        {
            small = *first;
            if (*second < *third)
            {
                middle = *second;
                big = *third;
            }
            else
            {
                middle = *third;
                big = *second;
            }
        }
        else // first > third
        {
            big = *second;
            middle = *first;
            small = *third;
        }
    }
    *first = big;
    *second = middle;
    *third = small;
    return;
}

void checkchars()
{
    char c = getchar();
    while (c != EOF || c != '\n')
    {
        if ((c >= 97 && c <= 122) || (c >= 65 && c <= 90))
        {
            printf("It is a letter. At %d\n", checkchar(c));
        }
        c = getchar();
    }
}

int checkchar(char c)
{
    if (c >= 97 && c <= 122)
    {
        return c - 96;
    }
    else if (c >= 65 && c <= 90)
    {
        return c - 64;
    }
    else
    {
        return -1;
    }
}

void to_binary(unsigned long n)
{

    int r;
    r = n % 2;
    if (n >= 2)
        to_binary(n / 2);
    putchar(r == 0 ? '0' : '1');
    return;
}

void to_base_n(unsigned long n, int base)
{
    int r;
    r = n % base;
    if (n >= base)
        to_base_n(n / base, base);
    if (r >= 10)
    {
        switch (r)
        {
        case 10:
            putchar('A');
            break;
        case 11:
            putchar('B');
            break;
        case 12:
            putchar('C');
            break;
        case 13:
            putchar('D');
            break;
        case 14:
            putchar('E');
            break;
        case 15:
            putchar('F');
            break;
        default:
            break;
        }
    }
    else
        putchar(r == 0 ? '0' : r + '0');
}

void to_base_16(unsigned long n)
{
}