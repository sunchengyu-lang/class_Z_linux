#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

// 删除单链表中的最大结点
void deleteMax(Node **head)
{
    if (*head == NULL)
        return; // 如果链表为空则直接返回

    Node *maxNode = *head, *prev = NULL, *current = *head;

    // 寻找最大结点及它的前驱结点
    while (current != NULL)
    {
        if (current->data > maxNode->data)
        {
            maxNode = current;
            prev = NULL; // 重置前驱结点
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

    // 如果最大结点就是头结点
    if (maxNode == *head)
    {
        *head = (*head)->next;
        free(maxNode);
    }
    else
    {
        // 如果最大结点不是头结点
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

// 插入排序算法
void sort(DNode **head)
{
    if (*head == NULL || (*head)->next == NULL)
        return; // 如果链表为空或只有一个结点则无需排序

    DNode *current, *sortedEnd, *nextNode, *insertBefore;

    // 将第一个结点设置为已排序部分的结尾
    sortedEnd = *head;
    current = sortedEnd->next;

    // 当还有未排序的结点时
    while (current != NULL)
    {
        nextNode = current->next; // 保存下一个待排序结点

        // 找到插入位置
        insertBefore = sortedEnd;
        while (insertBefore->prior != NULL && insertBefore->prior->data < current->data)
        {
            insertBefore = insertBefore->prior;
        }

        // 将当前结点从链表中移除
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

        // 将当前结点插入到已排序的部分
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

        // 更新已排序部分的结尾
        sortedEnd = nextNode;

        current = nextNode;
    }
}