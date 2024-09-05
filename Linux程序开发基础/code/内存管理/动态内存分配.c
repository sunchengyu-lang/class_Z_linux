#include <stdio.h>
#include <stdlib.h>

void sort(int a[], int n)
{
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (a[i] > a[j])
            {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
}

int main()
{
    int n;
    puts("请输入数组大小");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    puts("\n请依次输入数组元素:");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    sort(arr, n);
    puts("排序后的结果为：");
    for (int i = 0; i < n; i++)
        printf("%4d", arr[i]);
    free(arr);
    return 0;
}