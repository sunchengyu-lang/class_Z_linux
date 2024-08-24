#include <stdlib.h>

typedef struct DNode
{
    int data;
    struct DNode *next, *prior;
} DNode;

// 逆置带头结点的双链表
void reverseDoublyLinkedList(DNode **head)
{
    if (*head == NULL || (*head)->next == NULL)
        return; // 如果链表为空或只有一个结点则无需逆置

    DNode *current = (*head)->next; // 从头结点的下一个结点开始
    DNode *temp = NULL;

    // 遍历链表，交换每个节点的前后指针
    while (current != NULL)
    {
        temp = current->prior;
        current->prior = current->next;
        current->next = temp;
        current = temp;
    }

    // 更新头结点的 next 指针，使其指向原尾节点
    // 原尾节点的 prior 指向 NULL
    (*head)->next->prior = NULL;
    *head = (*head)->next;
}