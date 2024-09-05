#include <stdio.h>

int holes[11];

void solve()
{
    int t = 0, cnt = 0;
    while (cnt < 1000)
    {
        cnt++;
        t += cnt;
        int temp = t % 10;
        if (!temp)
            temp = 10;
        holes[temp] = 0;
    }
}

int main()
{
    // 初始化
    for (int i = 1; i < 11; i++)
        holes[i] = 1;
    solve();
    puts("兔子可能在的洞为:");
    for (int i = 1; i <= 10; i++)
        if (holes[i])
            printf("%d ", i);

    return 0;
}