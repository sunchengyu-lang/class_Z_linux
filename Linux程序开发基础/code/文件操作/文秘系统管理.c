#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void divideFile()
{
    char filename[30];
    int chunk_num = 0;
    FILE *fp;

    printf("please input divide file's postion:");
    scanf("%s", filename);
    printf("\nhow many do you want to divide the file:");
    scanf("%d", &chunk_num);

    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        perror("无法打开文件");
        exit(1);
    }

    // 找到文件总的字节数
    fseek(fp, 0, SEEK_END);
    int file_size = ftell(fp);
    rewind(fp); // 回到开头
    int chunk_size = file_size / chunk_num + 1;
    printf("\nthe size:%d bites,when dividing every file about:%d bites\n", file_size, chunk_size);
    for (int i = 0; i < chunk_num; i++)
    {
        char newFilename[30], buffer[chunk_size];
        FILE *tfp;
        printf("\nplease input you want to dividing %dth new file's postion:", i + 1);
        scanf("%s", newFilename);
        tfp = fopen(newFilename, "w");
        if (tfp == NULL)
        {
            perror("无法打开文件");
            exit(1);
        }
        int read_size = fread(buffer, 1, chunk_size, fp);
        fwrite(buffer, 1, read_size, tfp);
        fclose(tfp);
    }
    fclose(fp);
    printf("divide successful,whether or not continue to divide(Y/n)");
    getchar();
    char ch;
    scanf("%c", &ch);
    if (ch == 'Y')
        divideFile();
}

void uniteFile()
{
    printf("please input unite file's postion:");
    char filename[30], dest[30];
    scanf("%s", dest);
    FILE *dfp;
    dfp = fopen(dest, "a");
    if (dfp == NULL)
    {
        perror("无法打开文件");
        exit(1);
    }
    while ((scanf("%s", filename)) != EOF)
    {
        FILE *fp = fopen(filename, "r");
        if (fp == NULL)
        {
            perror("无法打开文件");
            exit(1);
        }
        char ch;
        while ((ch = fgetc(fp)) != EOF)
            fputc(ch, dfp);

        fclose(fp);
    }
    fclose(dfp);
    printf("whether or not continue to unite(Y/press any key)");
    getchar();
    char ch;
    scanf("%c", &ch);
    if (ch == 'Y')
        uniteFile();
}

int main()
{
    int choose = -1;
    while (1)
    {
        puts("please choose you needful file:1.divide file 2.unite file 3.exit:");
        scanf("%d", &choose);
        switch (choose)
        {
        case 1:
            divideFile();
            break;
        case 2:
            uniteFile();
            break;
        default:
            exit(0);
            break;
        }
    }
    exit(0);
}