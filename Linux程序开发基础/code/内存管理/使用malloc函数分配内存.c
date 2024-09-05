#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *n;
};

int main()
{
    struct Node *node;
    node = (struct Node *)malloc(sizeof(struct Node));
    if (node == NULL)
    {
        puts("内存分配失败！");
        return 1;
    }
    node->data = 1;
    node->n = NULL;
    printf("整形, 值为%d\n", node->data);
    printf("结构体指针,值为：%p", node->n);
    free(node);
    return 0;
}