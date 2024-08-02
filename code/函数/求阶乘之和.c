#include <stdio.h>

// �����ü��仯�����������Ż���������ҪΪ����ϰ�ݹ�
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
    puts("������m,n,k");
    scanf("%d %d %d", &m, &n, &k);
    printf("%d\n", f(m) + f(n) + f(k));
    return 0;
}