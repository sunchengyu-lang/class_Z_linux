#include <stdio.h>
#include <stdlib.h>

int main()
{
    char str[110], filename[20];
    FILE *fp;
    puts("please input string!");
    fgets(str, sizeof str, stdin);
    puts("please input filename:");
    scanf("%s", filename);
    fp = fopen(filename, "w+");
    if (fp == NULL)
    {
        perror("Error opening file");
        exit(1);
    }
    fputs(str, fp);
    char pstr[110];
    fgets(pstr, sizeof pstr, fp);
    puts(pstr);
    fclose(fp);
    exit(0);
}