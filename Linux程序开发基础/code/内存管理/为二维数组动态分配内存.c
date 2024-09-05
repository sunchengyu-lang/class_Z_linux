#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n = 0, m = 0;
    puts("请输入二维数组的行数:");
    scanf("%d", &n);

    puts("\n请输入二维数组的列数:");
    scanf("%d", &m);

    // 分配一个指针数组，每个指针指向一个整数数组
    int **arr = (int **)malloc(n * sizeof(int *));
    if (arr == NULL)
    {
        puts("分配内存失败");
        return 1;
    }

    // 为每个整数数组分配内存
    for (int i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(m * sizeof(int));
        if (arr[i] == NULL)
        {
            puts("分配内存失败");
            return 1;
        }
    }

    // 初始化数组
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            arr[i][j] = i + j;

    // 打印数组
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            printf("%d    ", arr[i][j]);

        puts("");
    }

    // 释放内存
    for (int i = 0; i < n; i++)
        free(arr[i]);

    free(arr);

    return 0;
}