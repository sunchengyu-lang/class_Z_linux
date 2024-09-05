#include <stdio.h>
#include <stdlib.h>

// ��������������ִ�м�������
void countingSort(int arr[], int n, int exp)
{
    int output[n]; // �������
    int i, count[10] = {0};

    // �洢ÿ���������ֵĴ���
    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    // �ı�count[i]ʹ��count[i]������ÿ�����ֵ�����λ��
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // �����������
    for (i = n - 1; i >= 0; i--)
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // ��output���鸴�ƻ�arr����
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}

// ����������
void radixsort(int arr[], int n)
{
    // Ѱ�������е��������ȷ��λ��
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];

    // ��ÿһλִ�м�������
    for (int exp = 1; max / exp > 0; exp *= 10)
        countingSort(arr, n, exp);
}

int main()
{
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr) / sizeof(arr[0]);

    radixsort(arr, n);

    printf("����������: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}