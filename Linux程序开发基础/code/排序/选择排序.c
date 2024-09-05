#include <stdio.h>

// ѡ��������
void selectionSort(int arr[], int n)
{
    int i, j, min_idx, temp;

    // һ��һ����ѡ����С��Ԫ��
    for (i = 0; i < n - 1; i++)
    {
        // �ҵ�δ���򲿷ֵ���СԪ�ص�����
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        // �����ҵ�����СԪ����δ���򲿷ֵĵ�һ��Ԫ��
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
    printf("����������: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}