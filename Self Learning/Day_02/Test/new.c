#include <stdio.h>
#include <string.h>

int main()
{
    char filename[30] = "_program.cpp";
    char fileno[100];

    for (int i = 45; i < 90; i++)
    {

        sprintf(fileno, "%d", i);
        strcat(fileno, filename);
        printf("%s\n", fileno);
        FILE *fptr = fopen(fileno, "w");
    }

    return 0;
}