#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *source, *dest;
    source = fopen("source", "r");
    if (source == NULL)
    {
        perror("source文件打开错误");
        exit(1);
    }

    dest = fopen("dest", "w");
    if (dest == NULL)
    {
        perror("dest文件打开错误");
        exit(1);
    }
    char str[110];
    fgets(str, sizeof str, source);
    fputs(str, dest);
    fclose(source);
    fclose(dest);
    exit(0);
}