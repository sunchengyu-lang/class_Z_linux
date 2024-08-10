#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("请输入数据的个数：");
    scanf("%d", &n);
    puts("");
    printf("为%d个数据分配内存空间\n", n);
    int *arr = (int *)calloc(n, sizeof(int));
    if (arr == NULL)
    {
        puts("内存分配失败！");
        return 1;
    }
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    for (int i = 0; i < n; i++)
        printf("%5d", arr[i]);

    free(arr);
    return 0;
}