#include <stdio.h>
#include <stdlib.h>

void sort(int a[], int n)
{
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (a[i] > a[j])
            {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
}

int main()
{
    int n;
    puts("�����������С");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    puts("\n��������������Ԫ��:");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    sort(arr, n);
    puts("�����Ľ��Ϊ��");
    for (int i = 0; i < n; i++)
        printf("%4d", arr[i]);
    free(arr);
    return 0;
}