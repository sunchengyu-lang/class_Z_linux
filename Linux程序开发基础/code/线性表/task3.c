#include <stdio.h>
#include <stdlib.h>

// ���嵥����ڵ�ṹ��
typedef struct LinkListNode
{
    int data;                  // ������
    struct LinkListNode *next; // ָ����һ���ڵ��ָ��
} LinkLNode;

// ɾ���ӵ� i ���ڵ㿪ʼ�� n ���ڵ�
void DeleteNodes(LinkLNode *head, int i, int n)
{
    LinkLNode *p = head, *q = head;
    int count = 1;

    // �ƶ� p ָ�뵽�� i ���ڵ�
    while (p != NULL && count < i)
    {
        q = p;
        p = p->next;
        count++;
    }

    // ��� i ���Ϸ���ֱ�ӷ���
    if (p == NULL)
    {
        return;
    }

    // ɾ���ӵ� i ���ڵ㿪ʼ�� n ���ڵ�
    while (n > 0 && p != NULL)
    {
        LinkLNode *temp = p;
        p = p->next;
        free(temp); // �ͷŽڵ��ڴ�
        n--;
    }

    // ���� q ָ��� next ָ��
    q->next = p;
}