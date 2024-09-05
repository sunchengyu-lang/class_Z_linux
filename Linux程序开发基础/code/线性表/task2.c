#include <stdio.h>
#include <stdlib.h>

// ���嵥����ڵ�ṹ��
typedef struct LinkListNode
{
    int data; // ���� ElemType Ϊ int
    struct LinkListNode *next;
} LinkLNode;

// ���뺯��
bool InsertList(LinkLNode *L, int a, int x)
{
    // �����½ڵ�
    LinkLNode *newNode = (LinkLNode *)malloc(sizeof(LinkLNode));
    if (newNode == NULL)
    {
        // �ڴ����ʧ��
        return false;
    }
    newNode->data = x;
    newNode->next = NULL;

    // Ѱ��������Ϊ a �Ľڵ�
    LinkLNode *current = L;
    while (current->next != NULL && current->next->data != a)
    {
        current = current->next;
    }

    // ����Ƿ��ҵ�������Ϊ a �Ľڵ�
    if (current->next == NULL)
    {
        // û���ҵ����ͷ��½ڵ��ڴ�
        free(newNode);
        return false;
    }

    // �����½ڵ�
    newNode->next = current->next->next;
    current->next->next = newNode;

    return true;
}