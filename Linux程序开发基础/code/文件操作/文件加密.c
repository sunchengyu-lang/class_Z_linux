#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char filename[30], password[30], newFilename[30];
    puts("please input encode file name:");
    scanf("%s", filename);
    puts("\nplease input Password:");
    scanf("%s", password);
    puts("\nplease input saved file name:");
    scanf("%s", newFilename);

    FILE *input, *output;
    input = fopen(filename, "r");
    if (input == NULL)
    {
        perror("加密文件打开失败");
        exit(1);
    }
    output = fopen(newFilename, "w");
    if (output == NULL)
    {
        perror("解密文件创建失败");
        exit(1);
    }
    char ch;
    int cnt = 0, len = strlen(password);
    while ((ch = fgetc(input)) != EOF)
    {
        ch ^= password[cnt % len]; // XOR操作符加密
        cnt++;
        fputc(ch, output);
    }

    fclose(input);
    fclose(output);
    exit(0);
}