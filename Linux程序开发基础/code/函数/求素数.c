#include <stdio.h>
#include <math.h>

int isPrime(int x)
{
    int t = sqrt(x);
    for (int i = 2; i <= t; i++)
        if (x % i == 0)
            return 0;
    return 1;
}

int main()
{
    puts("100以内的素数:");
    for (int i = 2; i < 101; i++)
        if (isPrime(i))
            printf("%d\n", i);

    return 0;
}
