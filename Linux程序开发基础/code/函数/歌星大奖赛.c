#include <stdio.h>

int scores[10];

double compute()
{
    int max = -1, min = 110, sum = 0;
    for (int i = 0; i < 10; i++)
    {
        sum += scores[i];
        max = max > scores[i] ? max : scores[i];
        min = min < scores[i] ? min : scores[i];
    }
    return (sum - min - max) * 1.0 / 8;
}

int main()
{
    puts("请依次输入10个分数");
    for (int i = 0; i < 10; i++)
        scanf("%d", &scores[i]);

    printf("最后得分为:%.2f", compute());
    return 0;
}