#include <stdio.h>
#include <stdlib.h>

int main()
{
    char str[] = "�ú�ѧϰ,��������#";
    FILE *fp = fopen("study", "w+");
    if (fp == NULL)
    {
        perror("���ļ��򿪴���");
        exit(1);
    }
    fputs(str, fp);
    fclose(fp);
    exit(0);
}