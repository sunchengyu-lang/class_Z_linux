#include <stdio.h>

// �ϲ�����������
void merge(int arr[], int left, int mid, int right)
{
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // ������ʱ����
    int L[n1], R[n2];

    // �������ݵ���ʱ���� L[] �� R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // �ϲ���ʱ����ص�ԭ���� arr[]
    i = 0;    // ��ʼ������һ��������
    j = 0;    // ��ʼ�����ڶ���������
    k = left; // ��ʼ�����ϲ���������
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

    // ���� L[] ��ʣ��Ԫ��
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    // ���� R[] ��ʣ��Ԫ��
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// �ݹ�ذ�����ֳ�����������
void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        // m ���������ߵ��м��
        int m = left + (right - left) / 2;

        // �ֱ�����������������
        mergeSort(arr, left, m);
        mergeSort(arr, m + 1, right);

        // �ϲ�����������Ĳ���
        merge(arr, left, m, right);
    }
}

int main()
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, 0, n - 1);
    printf("����������: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}