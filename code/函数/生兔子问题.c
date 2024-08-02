#include <stdio.h>
#include <string.h>

int a[110];

int f(int x)
{
    if (a[x])
        return a[x];

    if (x == 1 || x == 2)
        a[x] = 1;
    else
        a[x] = f(x - 1) + f(x - 2);

    return a[x];
}
int main()
{
    memset(a, 0, sizeof(a));
    int n;
    puts("请输入预测到第几月，兔子的数量（< 110）");
    scanf("%d", &n);

    int t = f(n);

    for (int i = 1; i <= n; i++)
        printf("第%d个月，兔子的数量：%d\n", i, a[i]);

    return 0;
}
