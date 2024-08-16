#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    puts("请输入一个字符串:");
    char str[110];
    fgets(str, sizeof str, stdin);
    FILE *fp = fopen("test", "w");
    if (fp == NULL)
    {
        perror("打开文件test错误");
        exit(1);
    }
    // 小写转大写
    int len = strlen(str);
    for (int i = 0; i < len; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] += 'A' - 'a';
    }

    // 保存
    if (fputs(str, fp) < 0)
    {
        perror("test文件写入错误");
        exit(1);
    }

    fclose(fp);
    exit(0);
}