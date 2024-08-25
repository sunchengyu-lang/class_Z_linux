#include <stdio.h>

// 用于交换数组中的两个元素
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

// 分区函数，返回分区后基准元素的正确位置
int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; // 选择最后一个元素作为基准
    int i = (low - 1);     // 最小元素索引

    for (int j = low; j <= high - 1; j++)
    {
        // 如果当前元素小于或等于基准
        if (arr[j] <= pivot)
        {
            i++; // 增加较小元素的索引
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// 快速排序函数
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        // pi 是分区后的基准元素索引，arr[pi] 现在位于正确的位置
        int pi = partition(arr, low, high);

        // 递归地对分区前和分区后的子数组进行排序
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main()
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, n - 1);
    printf("排序后的数组: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}