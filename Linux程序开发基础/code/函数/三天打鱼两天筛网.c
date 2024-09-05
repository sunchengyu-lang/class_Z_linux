#include <stdio.h>

int months[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int is_RN(int yy)
{
    if ((yy % 4 == 0 && yy % 100 != 0) || yy % 400 == 0)
        return 1;

    return 0;
}

int year_dis(int yy)
{
    int sum = 0;
    for (int i = 1990; i <= yy; i++)
        if (is_RN(i))
            sum += 366;
        else
            sum += 365;

    return sum;
}

int day_dis(int yy, int mm, int dd)
{

    int sum = 0;
    for (int i = 1; i < mm; i++)
    {
        if (mm == 2 && is_RN(yy))
            sum++;
        sum += months[i];
    }
    sum += dd;
    return sum;
}

int main()
{
    int yy, mm, dd;
    puts("������ָ������,�Բ鿴�����ʽyyyy��mm��yy�գ�");
    scanf("%d��%d��%d��", &yy, &mm, &dd);
    int bet1 = year_dis(yy);

    int bet2 = day_dis(yy, mm, dd);

    int res = bet1 + bet2 % 5;
    if (res >= 1 && res <= 3)
    {
        printf("����\n");
    }
    else
    {
        printf("ɹ��\n");
    }
    return 0;
}