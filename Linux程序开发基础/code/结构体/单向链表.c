#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    int id;
    char name[20];
    struct Node *next;
} node;

node *create(int id, char name[])
{
    node *newNode = (node *)malloc(sizeof(node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->id = id;
    strcpy(newNode->name, name);
    newNode->next = NULL;
    return newNode;
}

void push_back(node **phead, int id, char name[])
{
    node *newNode = create(id, name);
    if (*phead == NULL)
    {
        *phead = newNode;
    }
    else
    {
        node *tail = *phead;
        while (tail->next != NULL)
        {
            tail = tail->next;
        }
        tail->next = newNode;
    }
}

node *bubbleSortById(node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    int swapped;
    node *current;
    node *last = NULL;

    do
    {
        swapped = 0;
        current = head;

        while (current->next != last)
        {
            if (current->id > current->next->id)
            {
                int tempId = current->id;
                current->id = current->next->id;
                current->next->id = tempId;

                char tempName[20];
                strcpy(tempName, current->name);
                strcpy(current->name, current->next->name);
                strcpy(current->next->name, tempName);

                swapped = 1;
            }
            current = current->next;
        }
        last = current;
    } while (swapped);

    return head;
}

int count(node *phead)
{
    int cnt = 0;
    node *cur = phead;
    while (cur != NULL)
    {
        cur = cur->next;
        cnt++;
    }
    return cnt;
}

node *reverse(node *head)
{
    node *prev = NULL;
    node *cur = head;
    node *next = NULL;
    while (cur != NULL)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}

void list(node *head)
{
    node *cur = head;
    while (cur != NULL)
    {
        printf("ѧ��: %d ����: %s \n", cur->id, cur->name);
        cur = cur->next;
    }
}

node *search(node *head, int id)
{
    node *cur = head;
    while (cur != NULL)
    {
        if (cur->id == id)
        {
            return cur;
        }
        cur = cur->next;
    }
    return NULL;
}

int main()
{
    int id;
    char name[20];
    int n;

    node *phead1 = NULL;

    printf("�������������� n: \n");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d %s", &id, name);
        push_back(&phead1, id, name);
    }

    // ����ѧ����������
    phead1 = bubbleSortById(phead1);

    printf("�ڵ������: %d\n", count(phead1));

    // Reverse the list before printing
    phead1 = reverse(phead1);

    list(phead1);

    printf("������Ҫ���ҵ�ѧ��: ");
    scanf("%d", &id);
    node *student = search(phead1, id);

    if (student != NULL)
    {
        printf("ѧ��: %d ����: %s\n", student->id, student->name);
    }
    else
    {
        printf("�����ڸ�ѧ����¼\n");
    }

    return 0;
}
