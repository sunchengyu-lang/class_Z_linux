#include <stdio.h>
#include <stdlib.h>

// ����ڵ�ṹ��
typedef struct Node
{
    int data;          // �洢������
    struct Node *next; // ָ����һ���ڵ��ָ��
} Node;

// ����ջ����
typedef struct Node *Stack;

// ��ʼ��ջ
void init(Stack *s)
{
    *s = NULL;
}

// ��ջ����
void push(Stack s, int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->data = value;
    newNode->next = s;
    s = newNode;
}

// ��ջ����
int pop(Stack *s)
{
    if (*s == NULL)
    {
        printf("Stack is empty.\n");
        return -1; // ����-1Ϊ�Ƿ�ֵ����ʾ����
    }
    Node *temp = *s;
    int value = temp->data;
    *s = (*s)->next;
    free(temp);
    return value;
}

// ջ�ı���
void traverse(Stack s)
{
    while (s != NULL)
    {
        printf("%d ", s->data);
        s = s->next;
    }
    printf("\n");
}

// ����ջ
void destroy(Stack *s)
{
    Node *current = *s;
    Node *next;
    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
    *s = NULL;
}

int main()
{
    Stack stack;
    init(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printf("Stack after pushes: ");
    traverse(stack);

    printf("Popped element: %d\n", pop(&stack));

    printf("Stack after pop: ");
    traverse(stack);

    destroy(&stack);
    return 0;
}