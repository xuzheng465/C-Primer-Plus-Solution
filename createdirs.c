#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <errno.h>

int main(int argc, char *argv[])
{
    char *name = "Ch";
    int num;
    if (argc < 3)
    {
        printf("Usage: createdir from to\n");
        exit(EXIT_FAILURE);
    }
    if (sscanf(argv[1], "%d", &num) != 1)
    {
        sprintf(stderr, "the input %s is not correct", argv[1]);
    }
    char *n;
    char bufferName[10];

    int to;
    if (sscanf(argv[2], "%d", &to) != 1)
    {
        sprintf(stderr, "the input %s is not correct", argv[2]);
    }
    while (num < to)
    {
        if (asprintf(&n, "%d", num) == -1)
        {
            perror("asprintf");
        }
        else
        {
            strcat(strcpy(bufferName, name), n);

            int ret = mkdir(bufferName, S_IRWXU);
            if (ret == -1)
            {
                switch (errno)
                {
                case EACCES:
                    printf("the parent directory does not allow write");
                    exit(EXIT_FAILURE);
                case EEXIST:
                    printf("%s already exists\n", bufferName);
                    break;
                case ENAMETOOLONG:
                    printf("pathname is too long\n");
                    exit(EXIT_FAILURE);
                default:
                    perror("mkdir");
                    break;
                }
            }
            else
            {
                printf("Create directory %s\n", bufferName);
            }
        }
        num++;
    }

    free(n);
    exit(EXIT_SUCCESS);
}