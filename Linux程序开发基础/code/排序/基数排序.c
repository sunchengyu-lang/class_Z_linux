#include <stdio.h>
#include <stdlib.h>

// 辅助函数，用于执行计数排序
void countingSort(int arr[], int n, int exp)
{
    int output[n]; // 输出数组
    int i, count[10] = {0};

    // 存储每个基数出现的次数
    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    // 改变count[i]使得count[i]现在是每个数字的真正位置
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // 建立输出数组
    for (i = n - 1; i >= 0; i--)
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // 把output数组复制回arr数组
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}

// 基数排序函数
void radixsort(int arr[], int n)
{
    // 寻找数组中的最大数来确定位数
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];

    // 对每一位执行计数排序
    for (int exp = 1; max / exp > 0; exp *= 10)
        countingSort(arr, n, exp);
}

int main()
{
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr) / sizeof(arr[0]);

    radixsort(arr, n);

    printf("排序后的数组: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}