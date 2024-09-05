#include <stdio.h>
#include <stdlib.h>

int main()
{
    char str[] = "好好学习,天天向上#";
    FILE *fp = fopen("study", "w+");
    if (fp == NULL)
    {
        perror("我文件打开错误");
        exit(1);
    }
    fputs(str, fp);
    fclose(fp);
    exit(0);
}