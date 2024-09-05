#include <stdbool.h>
#include <stdlib.h>

typedef struct DNode
{
    int data;
    struct DNode *next, *prior;
} DNode;

// ��������ĺ�벿��
void reverseSecondHalf(DNode **mid)
{
    DNode *prev = *mid, *current = prev->next, *nextNode = NULL;
    while (current != *mid)
    {
        nextNode = current->next;
        current->next = current->prior;
        current->prior = nextNode;
        prev = current;
        current = nextNode;
    }
}

// �ж�ѭ��˫�����Ƿ�Գ�
bool isSymmetricCircularDoublyLinkedList(DNode *head)
{
    if (head == NULL || head->next == head)
        return false; // �������������

    // ʹ�ÿ���ָ���ҵ��м��
    DNode *slow = head->next, *fast = head->next;
    while (fast != head && fast->next != head)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    // ����������Ϊ�������� fast �����һ������ʱ fast == head
    if (fast->next == head)
    {
        slow = slow->next;
    }

    // ���ú�벿��
    reverseSecondHalf(&slow);

    // �Ƚ�������
    DNode *first = head->next, *second = slow;
    bool isSymmetric = true;
    while (first != slow)
    {
        if (first->data != second->data)
        {
            isSymmetric = false;
            break;
        }
        first = first->next;
        second = second->next;
    }

    // �ָ���벿��˳��
    reverseSecondHalf(&slow);

    return isSymmetric;
}