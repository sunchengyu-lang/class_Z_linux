#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void solve()
{
    char *str = (char *)malloc(101 * sizeof(char));
    if (str == NULL)
    {
        puts("内存分配失败");
        return;
    }
    puts("请输入字串个数：");
    scanf("%s", str);
    int len = strlen(str), c = len % 8 ? len / 8 + 1 : len / 8;

    char **ans = (char **)malloc(c * sizeof(char *));
    if (ans == NULL)
    {
        puts("内存分配失败");
        return;
    }
    for (int i = 0; i < c; i++)
    {
        ans[i] = (char *)malloc(sizeof(char) * 9);
        if (ans[i] == NULL)
        {
            puts("内存分配失败");
            return;
        }

        for (int j = 0; j < 8; j++)
            if (*str)
            {
                ans[i][j] = *str;
                str++;
            }
            else
                ans[i][j] = '0';

        ans[i][8] = '\0';
    }

    for (int i = 0; i < c; i++)
        printf("%s\n", ans[i]);

    // for (int i = 0; i < c; i++)
    //     free(ans[i]);
    // free(str);
    // free(ans);
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}