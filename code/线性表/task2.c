#include <stdio.h>
#include <stdlib.h>

// 定义单链表节点结构体
typedef struct LinkListNode
{
    int data; // 假设 ElemType 为 int
    struct LinkListNode *next;
} LinkLNode;

// 插入函数
bool InsertList(LinkLNode *L, int a, int x)
{
    // 创建新节点
    LinkLNode *newNode = (LinkLNode *)malloc(sizeof(LinkLNode));
    if (newNode == NULL)
    {
        // 内存分配失败
        return false;
    }
    newNode->data = x;
    newNode->next = NULL;

    // 寻找数据域为 a 的节点
    LinkLNode *current = L;
    while (current->next != NULL && current->next->data != a)
    {
        current = current->next;
    }

    // 检查是否找到数据域为 a 的节点
    if (current->next == NULL)
    {
        // 没有找到，释放新节点内存
        free(newNode);
        return false;
    }

    // 插入新节点
    newNode->next = current->next->next;
    current->next->next = newNode;

    return true;
}