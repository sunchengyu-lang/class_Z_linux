#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    puts("������һ���ַ���:");
    char str[110];
    fgets(str, sizeof str, stdin);
    FILE *fp = fopen("test", "w");
    if (fp == NULL)
    {
        perror("���ļ�test����");
        exit(1);
    }
    // Сдת��д
    int len = strlen(str);
    for (int i = 0; i < len; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] += 'A' - 'a';
    }

    // ����
    if (fputs(str, fp) < 0)
    {
        perror("test�ļ�д�����");
        exit(1);
    }

    fclose(fp);
    exit(0);
}