#include <stdio.h>

// �������ڵ����ѵĽṹ��ȷ���������ѵ�����
void heapify(int arr[], int n, int i)
{
    int largest = i;       // ��ʼ������Ϊ���ڵ�
    int left = 2 * i + 1;  // ���ӽڵ��λ��
    int right = 2 * i + 2; // ���ӽڵ��λ��

    // ������ӽڵ���ڸ��ڵ㣬���������ֵ
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // ������ӽڵ����Ŀǰ����ֵ�����������ֵ
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // ������Ĳ��Ǹ��ڵ㣬�򽻻����ǣ����ݹ�ص�����Ӱ�������
    if (largest != i)
    {
        int swap = arr[i];
        arr[i] = arr[largest];
        arr[largest] = swap;

        heapify(arr, n, largest);
    }
}

// ��������
void heapSort(int arr[], int n)
{
    // ������ʼ������
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // һ�����شӶ���ȡ��Ԫ��
    for (int i = n - 1; i > 0; i--)
    {
        // ����ǰ���ڵ��ƶ�������ĩβ
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // ����ʣ�ಿ����ά�����ѵ�����
        heapify(arr, i, 0);
    }
}

int main()
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    heapSort(arr, n);
    printf("����������: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}