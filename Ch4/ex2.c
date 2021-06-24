#include <stdio.h>
#include <string.h>

int main(void)
{
    char *name;
    int nameLength;
    printf("What is your first name? ");
    scanf("%s", name);
    printf("%d\n", strlen(name));
    nameLength = strlen(name);
    printf("\"%s\"\n", name);
    printf("\"%20s\"\n", name);
    printf("\"%-20s\"\n", name);
    printf("\"%*s\"\n", nameLength + 3, name);
    return 0;
}