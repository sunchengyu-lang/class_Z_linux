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
        puts("�ڴ����ʧ�ܣ�");
        return 1;
    }
    node->data = 1;
    node->n = NULL;
    printf("����, ֵΪ%d\n", node->data);
    printf("�ṹ��ָ��,ֵΪ��%p", node->n);
    free(node);
    return 0;
}