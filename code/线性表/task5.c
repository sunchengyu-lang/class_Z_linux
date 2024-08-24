#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

void insertIntoSortedDescendingList(Node **L, int x)
{
    // 创建一个新的节点
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = x;
    newNode->next = NULL;

    // 如果列表为空，或者新节点的数据大于等于链表头节点的数据
    if (*L == NULL || (*L)->data <= x)
    {
        newNode->next = *L; // 将新的节点的next指针指向原来的头节点
        *L = newNode;       // 设置新节点为头节点
    }
    else
    {
        // 遍历链表直到找到正确的位置
        Node *current = *L;
        while (current->next != NULL && current->next->data > x)
        {
            current = current->next;
        }
        // 插入新节点
        newNode->next = current->next;
        current->next = newNode;
    }
}