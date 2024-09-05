#include <stdio.h>

// 函数用于调整堆的结构，确保满足最大堆的性质
void heapify(int arr[], int n, int i)
{
    int largest = i;       // 初始化最大的为根节点
    int left = 2 * i + 1;  // 左子节点的位置
    int right = 2 * i + 2; // 右子节点的位置

    // 如果左子节点大于根节点，则更新最大的值
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // 如果右子节点大于目前最大的值，则更新最大的值
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // 如果最大的不是根节点，则交换它们，并递归地调整受影响的子树
    if (largest != i)
    {
        int swap = arr[i];
        arr[i] = arr[largest];
        arr[largest] = swap;

        heapify(arr, n, largest);
    }
}

// 堆排序函数
void heapSort(int arr[], int n)
{
    // 构建初始的最大堆
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // 一个个地从堆中取出元素
    for (int i = n - 1; i > 0; i--)
    {
        // 将当前根节点移动到数组末尾
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // 调整剩余部分以维持最大堆的性质
        heapify(arr, i, 0);
    }
}

int main()
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    heapSort(arr, n);
    printf("排序后的数组: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}