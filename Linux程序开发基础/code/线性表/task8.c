#include <stdbool.h>
#include <stdlib.h>

typedef struct DNode
{
    int data;
    struct DNode *next, *prior;
} DNode;

// ɾ����ͷ����ѭ��˫�����е�һ�� data ��ֵΪ x �Ľ��
bool delete(DNode **head, int x)
{
    if (*head == NULL)
        return false; // �������Ϊ����ֱ�ӷ��� false

    DNode *p = (*head)->next; // ��ͷ������һ����㿪ʼ
    DNode *prev = *head;      // ���浱ǰ����ǰ�����

    // ѭ������ֱ���ص�ͷ���
    do
    {
        if (p->data == x)
        { // �ҵ��� data ֵΪ x �Ľ��
            // ����ǰ������ next ָ��
            prev->next = p->next;
            // ���º�̽��� prior ָ��
            p->next->prior = prev;
            // �ͷŽ�� p ռ�õ��ڴ�
            free(p);
            return true; // �ɹ�ɾ����㣬���� true
        }
        prev = p;    // ����ǰ�����
        p = p->next; // �ƶ�����һ�����
    } while (p != (*head)->next); // ����ѭ��ֱ���ص���ʼλ��

    return false; // û���ҵ� data ֵΪ x �Ľ�㣬���� false
}