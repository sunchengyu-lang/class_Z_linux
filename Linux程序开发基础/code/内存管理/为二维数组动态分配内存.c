#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n = 0, m = 0;
    puts("�������ά���������:");
    scanf("%d", &n);

    puts("\n�������ά���������:");
    scanf("%d", &m);

    // ����һ��ָ�����飬ÿ��ָ��ָ��һ����������
    int **arr = (int **)malloc(n * sizeof(int *));
    if (arr == NULL)
    {
        puts("�����ڴ�ʧ��");
        return 1;
    }

    // Ϊÿ��������������ڴ�
    for (int i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(m * sizeof(int));
        if (arr[i] == NULL)
        {
            puts("�����ڴ�ʧ��");
            return 1;
        }
    }

    // ��ʼ������
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            arr[i][j] = i + j;

    // ��ӡ����
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            printf("%d    ", arr[i][j]);

        puts("");
    }

    // �ͷ��ڴ�
    for (int i = 0; i < n; i++)
        free(arr[i]);

    free(arr);

    return 0;
}