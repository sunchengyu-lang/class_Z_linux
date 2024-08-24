#include <stdio.h>

// 定义单链表节点结构体
typedef struct LinkListNode
{
    int data; // 假设 ElemType 为 int
    struct LinkListNode *next;
} LinkLNode;

// 计算数据域为 x 的节点个数
int CountList(LinkLNode *L, int x)
{
    int count = 0;
    LinkLNode *current = L->next; // 从第一个数据节点开始

    // 遍历链表
    while (current != NULL)
    {
        if (current->data == x)
        {
            count++; // 如果当前节点的数据域为 x，则计数加一
        }
        current = current->next;
    }

    return count;
}