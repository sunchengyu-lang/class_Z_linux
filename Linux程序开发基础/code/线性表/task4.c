#include <stdio.h>

// ���嵥����ڵ�ṹ��
typedef struct LinkListNode
{
    int data; // ���� ElemType Ϊ int
    struct LinkListNode *next;
} LinkLNode;

// ����������Ϊ x �Ľڵ����
int CountList(LinkLNode *L, int x)
{
    int count = 0;
    LinkLNode *current = L->next; // �ӵ�һ�����ݽڵ㿪ʼ

    // ��������
    while (current != NULL)
    {
        if (current->data == x)
        {
            count++; // �����ǰ�ڵ��������Ϊ x���������һ
        }
        current = current->next;
    }

    return count;
}