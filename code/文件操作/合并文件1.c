#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *fap, *fbp, *fcp;

    fap = fopen("A", "r");
    if (fap == NULL)
    {
        perror("A文件打开错误");
        exit(1);
    }

    fbp = fopen("B", "r");
    if (fbp == NULL)
    {
        perror("B文件打开错误");
        exit(1);
    }

    fcp = fopen("C", "w+");
    if (fcp == NULL)
    {
        perror("C文件打开错误");
        exit(1);
    }
    char ac[110], bc[110], cc[220];

    fgets(ac, sizeof ac, fap);
    fgets(bc, sizeof bc, fbp);

    strcpy(cc, ac);
    strcat(cc, bc);
    fclose(fap);
    fclose(fbp);
    // 排序
    int len = strlen(cc);
    for (int i = 0; i < len; i++)
        for (int j = i + 1; j < len; j++)
            if (cc[i] > cc[j])
            {
                char temp = cc[i];
                cc[i] = cc[j];
                cc[j] = temp;
            }
    // 打印
    puts(cc);
    // 保存
    fputs(cc, fcp);

    fclose(fcp);
    exit(0);
}