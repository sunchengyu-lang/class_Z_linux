#include <stdio.h>

// ����ʹ�ü��仯�������Ż�������Ϊ��ѵ���ݹ�
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
    printf("m,n,k�Ľ׳�֮��Ϊ��%d\n", f(m) + f(n) + f(k));
    return 0;
}