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

// 创建
node *create(char id[], char name[], char salary[])
{
    node *newNode = (node *)malloc(sizeof(node));
    strcpy(newNode->id, id);
    strcpy(newNode->name, name);
    strcpy(newNode->salary, salary);
    newNode->next = NULL;
    return newNode;
}

// 尾插
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

// 冒泡排序
node *bubbleSort(node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    int swapped;
    node *current;
    node *prev; // 声明 prev 在函数开始处
    node *tail = NULL;

    do
    {
        swapped = 0;
        current = head;
        prev = NULL; // 初始化 prev 在每次外部循环开始时

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
                prev = tempNode; // 更新 prev
                swapped = 1;
            }
            else
            {
                prev = current; // 更新 prev
                current = current->next;
            }
        }
        tail = current;
    } while (swapped);

    return head;
}
// 冒泡排序按工资
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
            if (atoi(current->salary) > atoi(current->next->salary)) // 使用 atoi 将字符串转换为整数进行比较
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
// 合并
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
    return list3->next; // 返回真正的头节点
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

    int n, m; // n是list1 m是list2 节点
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

    // 合并
    node *list3 = merge(list1->next, list2->next);
    // 按照员工号排序
    node *sortedList1 = bubbleSort(list3);
    puts("按照员工号排序:");
    print(sortedList1);
    printf("\n\n\n");
    // 根据员工工资排序
    node *sortedList2 = bubbleSortBySalary(list3);
    puts("根据员工工资排序 ");
    print(sortedList2);

    return 0;
}
