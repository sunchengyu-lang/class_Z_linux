#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("���������ݵĸ�����");
    scanf("%d", &n);
    puts("");
    printf("Ϊ%d�����ݷ����ڴ�ռ�\n", n);
    int *arr = (int *)calloc(n, sizeof(int));
    if (arr == NULL)
    {
        puts("�ڴ����ʧ�ܣ�");
        return 1;
    }
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    for (int i = 0; i < n; i++)
        printf("%5d", arr[i]);

    free(arr);
    return 0;
}