#include <stdio.h>
#include <stdlib.h>

// 定义单链表节点结构体
typedef struct LinkListNode
{
    int data;                  // 数据域
    struct LinkListNode *next; // 指向下一个节点的指针
} LinkLNode;

// 删除从第 i 个节点开始的 n 个节点
void DeleteNodes(LinkLNode *head, int i, int n)
{
    LinkLNode *p = head, *q = head;
    int count = 1;

    // 移动 p 指针到第 i 个节点
    while (p != NULL && count < i)
    {
        q = p;
        p = p->next;
        count++;
    }

    // 如果 i 不合法，直接返回
    if (p == NULL)
    {
        return;
    }

    // 删除从第 i 个节点开始的 n 个节点
    while (n > 0 && p != NULL)
    {
        LinkLNode *temp = p;
        p = p->next;
        free(temp); // 释放节点内存
        n--;
    }

    // 更新 q 指针的 next 指针
    q->next = p;
}