#include <stdlib.h>

typedef struct DNode
{
    int data;
    struct DNode *next, *prior;
} DNode;

// ���ô�ͷ����˫����
void reverseDoublyLinkedList(DNode **head)
{
    if (*head == NULL || (*head)->next == NULL)
        return; // �������Ϊ�ջ�ֻ��һ���������������

    DNode *current = (*head)->next; // ��ͷ������һ����㿪ʼ
    DNode *temp = NULL;

    // ������������ÿ���ڵ��ǰ��ָ��
    while (current != NULL)
    {
        temp = current->prior;
        current->prior = current->next;
        current->next = temp;
        current = temp;
    }

    // ����ͷ���� next ָ�룬ʹ��ָ��ԭβ�ڵ�
    // ԭβ�ڵ�� prior ָ�� NULL
    (*head)->next->prior = NULL;
    *head = (*head)->next;
}