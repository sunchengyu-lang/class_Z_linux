#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

void insertIntoSortedDescendingList(Node **L, int x)
{
    // ����һ���µĽڵ�
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = x;
    newNode->next = NULL;

    // ����б�Ϊ�գ������½ڵ�����ݴ��ڵ�������ͷ�ڵ������
    if (*L == NULL || (*L)->data <= x)
    {
        newNode->next = *L; // ���µĽڵ��nextָ��ָ��ԭ����ͷ�ڵ�
        *L = newNode;       // �����½ڵ�Ϊͷ�ڵ�
    }
    else
    {
        // ��������ֱ���ҵ���ȷ��λ��
        Node *current = *L;
        while (current->next != NULL && current->next->data > x)
        {
            current = current->next;
        }
        // �����½ڵ�
        newNode->next = current->next;
        current->next = newNode;
    }
}