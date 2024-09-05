#include <stdbool.h>
#include <stdlib.h>

typedef struct DNode
{
    int data;
    struct DNode *next, *prior;
} DNode;

// 逆置链表的后半部分
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

// 判断循环双链表是否对称
bool isSymmetricCircularDoublyLinkedList(DNode *head)
{
    if (head == NULL || head->next == head)
        return false; // 至少有两个结点

    // 使用快慢指针找到中间点
    DNode *slow = head->next, *fast = head->next;
    while (fast != head && fast->next != head)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    // 如果结点总数为奇数，则 fast 会多走一步，此时 fast == head
    if (fast->next == head)
    {
        slow = slow->next;
    }

    // 逆置后半部分
    reverseSecondHalf(&slow);

    // 比较两部分
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

    // 恢复后半部分顺序
    reverseSecondHalf(&slow);

    return isSymmetric;
}