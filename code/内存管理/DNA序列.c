#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ��������
int main()
{
    char str[1010];
    int n;
    puts("������������к��Ӵ�����");

    scanf("%s %d", str, &n);
    int len = strlen(str);
    int l = 0, r = n - 1, tmp = 0, dis = 0;
    for (int i = l; i <= r; i++)
        if (str[i] == 'C' || str[i] == 'G')
            tmp++;
    int maxn = tmp;
    while (r + 1 < len)
    {

        if (r == len)
            break;
        if (str[l] == 'C' || str[l] == 'G')
            tmp--;
        l++;
        r++;
        if (str[r] == 'G' || str[r] == 'C')
            tmp++;
        if (maxn < tmp)
        {
            dis = l;
            maxn = tmp;
        }
    }
    for (int i = 0; i < n; i++)
        printf("%c", str[dis + i]);
    puts("");
    return 0;
}