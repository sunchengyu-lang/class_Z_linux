#include <stdio.h>
#include <stdlib.h>

// 定义链表节点结构体
typedef struct Param
{
    int ci; // 系数
    int ei; // 指数
    struct Param *next;
} Param;

// 创建新的链表节点
Param *createParam(int coef, int exp)
{
    Param *newParam = (Param *)malloc(sizeof(Param));
    newParam->ci = coef;
    newParam->ei = exp;
    newParam->next = NULL;
    return newParam;
}

// 打印多项式
void printPolynomial(Param *head)
{
    Param *temp = head;
    while (temp != NULL)
    {
        printf("%d %d ", temp->ci, temp->ei);
        temp = temp->next;
    }
    puts("");
}

// 添加两个多项式
Param *addPolynomials(Param *poly1, Param *poly2)
{
    int cnt = 0;
    Param *result = NULL;
    Param *p1 = poly1, *p2 = poly2;
    while (p1 != NULL && p2 != NULL)
    {
        if (p1->ei > p2->ei)
        {
            Param *newParam = createParam(p1->ci, p1->ei);
            newParam->next = result;
            result = newParam;
            p1 = p1->next;
        }
        else if (p1->ei < p2->ei)
        {
            Param *newParam = createParam(p2->ci, p2->ei);
            newParam->next = result;
            result = newParam;
            p2 = p2->next;
        }
        else
        {
            int sum = p1->ci + p2->ci;
            if (sum != 0)
            {
                Param *newParam = createParam(sum, p1->ei);
                newParam->next = result;
                result = newParam;
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        cnt++;
    }
    while (p1 != NULL)
    {
        Param *newParam = createParam(p1->ci, p1->ei);
        newParam->next = result;
        result = newParam;
        p1 = p1->next;
        cnt++;
    }
    while (p2 != NULL)
    {
        Param *newParam = createParam(p2->ci, p2->ei);
        newParam->next = result;
        result = newParam;
        p2 = p2->next;
        cnt++;
    }
    printf("结果多项式的项数:\n%d\n", cnt);
    return result;
}

int main()
{
    int M, N; // 多项式的项数
    scanf("%d", &M);

    Param *poly1 = NULL;
    for (int i = 0; i < M; i++)
    {
        int ci, ei;
        scanf("%d %d", &ci, &ei);
        Param *newParam = createParam(ci, ei);
        newParam->next = poly1;
        poly1 = newParam;
    }

    scanf("%d", &N);

    Param *poly2 = NULL;
    for (int i = 0; i < N; i++)
    {
        int ci, ei;
        scanf("%d %d", &ci, &ei);
        Param *newParam = createParam(ci, ei);
        newParam->next = poly2;
        poly2 = newParam;
    }

    printf("第一个多项式:\n");
    printPolynomial(poly1);

    printf("第二个多项式:\n");
    printPolynomial(poly2);

    Param *result = addPolynomials(poly1, poly2);

    printf("结果多项式:\n");
    printPolynomial(result);

    return 0;
}