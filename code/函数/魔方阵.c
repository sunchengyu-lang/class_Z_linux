#include <stdio.h>

// 5-魔方阵
const int n = 5, m = 25;

int map[6][6];

void solve(int x, int y, int val)
{
    if (val > m)
        return;

    map[x][y] = val;

    // 计算下一个点
    int tx = x - 1, ty = y + 1;
    if (tx < 1)
        tx = n;
    if (ty > n)
        ty = 1;
    if (val % n == 0 || map[tx][ty] || (x == 1 && y == n))
        solve(x + 1, y, val + 1);
    else
        solve(tx, ty, val + 1);
}

int main()
{

    solve(1, n / 2 + 1, 1);

    // 打印
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            printf("%2d ", map[i][j]);
        }
        puts("");
    }
    return 0;
}