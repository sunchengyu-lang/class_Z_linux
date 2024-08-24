#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100 // 定义线性表的最大容量

// 插入元素到线性表
void insert(int *list, int *size, int value)
{
    if (*size < MAX_SIZE)
    {
        list[*size] = value;
        (*size)++;
    }
}

// 查找元素是否在列表中
bool search(int *list, int size, int value)
{
    for (int i = 0; i < size; i++)
        if (list[i] == value)
            return true;

    return false;
}

int main()
{
    int LA[] = {1, 2, 3, 4}; // 集合 A
    int LB[] = {3, 4, 5, 6}; // 集合 B
    int LC[MAX_SIZE];        // 结果集合 C
    int sizeA = sizeof(LA) / sizeof(LA[0]);
    int sizeB = sizeof(LB) / sizeof(LB[0]);
    int sizeC = 0;

    // 将集合 A 的元素插入到 LC 中
    for (int i = 0; i < sizeA; i++)
        insert(LC, &sizeC, LA[i]);

    // 将集合 B 中不在集合 A 中的元素插入到 LC 中
    for (int i = 0; i < sizeB; i++)
        if (!search(LC, sizeC, LB[i]))
            insert(LC, &sizeC, LB[i]);

    // 打印结果集合 C
    printf("The union of A and B is: ");
    for (int i = 0; i < sizeC; i++)
        printf("%d ", LC[i]);

    printf("\n");

    return 0;
}
