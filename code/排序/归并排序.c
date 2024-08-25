#include <stdio.h>

// 合并两个子数组
void merge(int arr[], int left, int mid, int right)
{
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // 创建临时数组
    int L[n1], R[n2];

    // 复制数据到临时数组 L[] 和 R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // 合并临时数组回到原数组 arr[]
    i = 0;    // 初始索引第一个子数组
    j = 0;    // 初始索引第二个子数组
    k = left; // 初始索引合并的子数组
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // 复制 L[] 的剩余元素
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    // 复制 R[] 的剩余元素
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// 递归地把数组分成两半来排序
void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        // m 是左右两边的中间点
        int m = left + (right - left) / 2;

        // 分别对左右两半进行排序
        mergeSort(arr, left, m);
        mergeSort(arr, m + 1, right);

        // 合并两个已排序的部分
        merge(arr, left, m, right);
    }
}

int main()
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, 0, n - 1);
    printf("排序后的数组: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}