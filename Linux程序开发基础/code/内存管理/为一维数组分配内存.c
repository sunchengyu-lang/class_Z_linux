#include <stdio.h>
#include <stdlib.h>

int main()
{
    static const int n = 10;
    // ����Ϊ�ַ�����
    char *arr = (char *)malloc(n * sizeof(char) + 1 * sizeof(char));
    for (int i = 0; i < n; i++)
        arr[i] = 'a' + i;

    for (int i = 0; i < n; i++)
        printf("  %c  ", arr[i]);

    free(arr);
    return 0;
}