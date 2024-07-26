#include <stdio.h>
#include <string.h>

int find(int n, int m)
{
    int index = 1, cnt = 0;
    int st[n + 10];
    memset(st, 0, sizeof st);

    while (n - cnt > 1)
    {
        int t = 0;
        do
        {
            if (!st[index])
            {
                t++;
                if (t == m)
                {
                    st[index] = 1;
                    cnt++;
                    break;
                }
            }
            if (index < n)
                index++;
            else
                index = 1;
        } while (t < m);
    }

    for (int i = 1; i <= n; i++)
        if (st[i] == 0)
            return i;
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int ans = find(n, m);
    printf("剩下的最后一人编号是:%d\n", ans);
    return 0;
}