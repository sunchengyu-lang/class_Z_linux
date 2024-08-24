#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

// ɾ���������е������
void deleteMax(Node **head)
{
    if (*head == NULL)
        return; // �������Ϊ����ֱ�ӷ���

    Node *maxNode = *head, *prev = NULL, *current = *head;

    // Ѱ������㼰����ǰ�����
    while (current != NULL)
    {
        if (current->data > maxNode->data)
        {
            maxNode = current;
            prev = NULL; // ����ǰ�����
        }
        else if (prev == NULL)
        {
            prev = *head;
        }
        else
        {
            prev = prev->next;
        }
        current = current->next;
    }

    // �����������ͷ���
    if (maxNode == *head)
    {
        *head = (*head)->next;
        free(maxNode);
    }
    else
    {
        // �������㲻��ͷ���
        prev->next = maxNode->next;
        free(maxNode);
    }
}

#include <stdlib.h>

typedef struct DNode
{
    int data;
    struct DNode *next, *prior;
} DNode;

// ���������㷨
void sort(DNode **head)
{
    if (*head == NULL || (*head)->next == NULL)
        return; // �������Ϊ�ջ�ֻ��һ���������������

    DNode *current, *sortedEnd, *nextNode, *insertBefore;

    // ����һ���������Ϊ�����򲿷ֵĽ�β
    sortedEnd = *head;
    current = sortedEnd->next;

    // ������δ����Ľ��ʱ
    while (current != NULL)
    {
        nextNode = current->next; // ������һ����������

        // �ҵ�����λ��
        insertBefore = sortedEnd;
        while (insertBefore->prior != NULL && insertBefore->prior->data < current->data)
        {
            insertBefore = insertBefore->prior;
        }

        // ����ǰ�����������Ƴ�
        if (current->prior != NULL)
        {
            current->prior->next = current->next;
        }
        else
        {
            *head = current->next;
        }
        if (current->next != NULL)
        {
            current->next->prior = current->prior;
        }

        // ����ǰ�����뵽������Ĳ���
        current->next = insertBefore;
        current->prior = insertBefore->prior;
        if (insertBefore->prior != NULL)
        {
            insertBefore->prior->next = current;
        }
        else
        {
            *head = current;
        }
        insertBefore->prior = current;

        // ���������򲿷ֵĽ�β
        sortedEnd = nextNode;

        current = nextNode;
    }
}