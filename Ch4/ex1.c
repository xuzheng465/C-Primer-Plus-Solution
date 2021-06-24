#include <stdio.h>
#include <string.h>

#define MAX 256

int main(void)
{
    char firstName[MAX];
    char lastName[MAX];
    char *pos;

    printf("What is your first name? ");
    fgets(firstName, sizeof(firstName), stdin);
    if ((pos = strchr(firstName, '\n')) != NULL)
        *pos = '\0';
    printf("What is your last name? ");
    fgets(lastName, sizeof(lastName), stdin);
    if ((pos = strchr(lastName, '\n')) != NULL)
        *pos = '\0';
    printf("%s, %s\n", lastName, firstName);
    return 0;
}