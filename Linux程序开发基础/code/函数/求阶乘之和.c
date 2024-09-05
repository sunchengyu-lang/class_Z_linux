#include <stdio.h>

// 可以使用记忆化或数组优化，这里为了训练递归
int f(int x)
{
    if (x == 1)
        return 1;
    else
        return f(x - 1) * x;
}

int main()
{
    int m, n, k;
    puts("请输入m,n,k");
    scanf("%d %d %d", &m, &n, &k);
    printf("m,n,k的阶乘之和为：%d\n", f(m) + f(n) + f(k));
    return 0;
}