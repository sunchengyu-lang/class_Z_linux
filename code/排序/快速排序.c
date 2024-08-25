#include <stdio.h>

// ���ڽ��������е�����Ԫ��
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

// �������������ط������׼Ԫ�ص���ȷλ��
int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; // ѡ�����һ��Ԫ����Ϊ��׼
    int i = (low - 1);     // ��СԪ������

    for (int j = low; j <= high - 1; j++)
    {
        // �����ǰԪ��С�ڻ���ڻ�׼
        if (arr[j] <= pivot)
        {
            i++; // ���ӽ�СԪ�ص�����
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// ����������
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        // pi �Ƿ�����Ļ�׼Ԫ��������arr[pi] ����λ����ȷ��λ��
        int pi = partition(arr, low, high);

        // �ݹ�ضԷ���ǰ�ͷ�������������������
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main()
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, n - 1);
    printf("����������: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}