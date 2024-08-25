#include <stdio.h>

// 选择排序函数
void selectionSort(int arr[], int n)
{
    int i, j, min_idx, temp;

    // 一个一个地选择最小的元素
    for (i = 0; i < n - 1; i++)
    {
        // 找到未排序部分的最小元素的索引
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        // 交换找到的最小元素与未排序部分的第一个元素
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

int main()
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    selectionSort(arr, n);
    printf("排序后的数组: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}