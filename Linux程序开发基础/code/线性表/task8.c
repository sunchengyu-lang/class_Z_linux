#include <stdbool.h>
#include <stdlib.h>

typedef struct DNode
{
    int data;
    struct DNode *next, *prior;
} DNode;

// 删除带头结点的循环双链表中第一个 data 域值为 x 的结点
bool delete(DNode **head, int x)
{
    if (*head == NULL)
        return false; // 如果链表为空则直接返回 false

    DNode *p = (*head)->next; // 从头结点的下一个结点开始
    DNode *prev = *head;      // 保存当前结点的前驱结点

    // 循环遍历直到回到头结点
    do
    {
        if (p->data == x)
        { // 找到了 data 值为 x 的结点
            // 更新前驱结点的 next 指针
            prev->next = p->next;
            // 更新后继结点的 prior 指针
            p->next->prior = prev;
            // 释放结点 p 占用的内存
            free(p);
            return true; // 成功删除结点，返回 true
        }
        prev = p;    // 更新前驱结点
        p = p->next; // 移动到下一个结点
    } while (p != (*head)->next); // 继续循环直到回到起始位置

    return false; // 没有找到 data 值为 x 的结点，返回 false
}