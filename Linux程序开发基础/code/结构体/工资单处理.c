#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    char id[20];
    char name[20];
    char salary[20];
    struct Node *next;
} node;

// ����
node *create(char id[], char name[], char salary[])
{
    node *newNode = (node *)malloc(sizeof(node));
    strcpy(newNode->id, id);
    strcpy(newNode->name, name);
    strcpy(newNode->salary, salary);
    newNode->next = NULL;
    return newNode;
}

// β��
void push_back(node **phead, char id[], char name[], char salary[])
{
    node *newNode = create(id, name, salary);
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

// ð������
node *bubbleSort(node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    int swapped;
    node *current;
    node *prev; // ���� prev �ں�����ʼ��
    node *tail = NULL;

    do
    {
        swapped = 0;
        current = head;
        prev = NULL; // ��ʼ�� prev ��ÿ���ⲿѭ����ʼʱ

        while (current->next != tail)
        {
            if (strcmp(current->id, current->next->id) > 0)
            {
                node *tempNode = current->next;

                current->next = tempNode->next;
                tempNode->next = current;
                if (current == head)
                    head = tempNode;
                else
                {
                    prev->next = tempNode;
                }
                prev = tempNode; // ���� prev
                swapped = 1;
            }
            else
            {
                prev = current; // ���� prev
                current = current->next;
            }
        }
        tail = current;
    } while (swapped);

    return head;
}
// ð�����򰴹���
node *bubbleSortBySalary(node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    int swapped;
    node *current;
    node *prev;
    node *tail = NULL;

    do
    {
        swapped = 0;
        current = head;
        prev = NULL;

        while (current->next != tail)
        {
            if (atoi(current->salary) > atoi(current->next->salary)) // ʹ�� atoi ���ַ���ת��Ϊ�������бȽ�
            {
                node *tempNode = current->next;

                current->next = tempNode->next;
                tempNode->next = current;
                if (current == head)
                    head = tempNode;
                else
                    prev->next = tempNode;
                prev = tempNode;
                swapped = 1;
            }
            else
            {
                prev = current;
                current = current->next;
            }
        }
        tail = current;
    } while (swapped);

    return head;
}
// �ϲ�
node *merge(node *phead1, node *phead2)
{
    node *list3 = create(" ", " ", " ");
    node *cur3 = list3;
    node *cur1 = phead1;
    node *cur2 = phead2;

    while (cur1 != NULL)
    {
        cur3->next = cur1;
        cur1 = cur1->next;
        cur3 = cur3->next;
    }

    while (cur2 != NULL)
    {
        cur3->next = cur2;
        cur2 = cur2->next;
        cur3 = cur3->next;
    }

    cur3->next = NULL;
    return list3->next; // ����������ͷ�ڵ�
}

void print(node *list)
{
    while (list != NULL)
    {
        printf("%s %s %s\n", list->id, list->name, list->salary);
        list = list->next;
    }
}

int main()
{
    char id[20], name[20], salary[20];
    node *list1 = create(" ", " ", " ");
    node *list2 = create(" ", " ", " ");

    int n, m; // n��list1 m��list2 �ڵ�
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%s%s%s", id, name, salary);
        push_back(&list1, id, name, salary);
    }
    for (int i = 0; i < m; i++)
    {
        scanf("%s%s%s", id, name, salary);
        push_back(&list2, id, name, salary);
    }

    // �ϲ�
    node *list3 = merge(list1->next, list2->next);
    // ����Ա��������
    node *sortedList1 = bubbleSort(list3);
    puts("����Ա��������:");
    print(sortedList1);
    printf("\n\n\n");
    // ����Ա����������
    node *sortedList2 = bubbleSortBySalary(list3);
    puts("����Ա���������� ");
    print(sortedList2);

    return 0;
}
