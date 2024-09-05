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
    newNode->next = *s;
    *s = newNode;
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

// ��ӡ�����Ķ����Ʊ�ʾ
void printBinary(int n)
{
    Stack stack;
    init(&stack);

    // ��n����0ʱ�����г�2ȡ��Ĳ���
    while (n > 0)
    {
        push(&stack, n % 2);
        n /= 2;
    }

    // ��ջ��ȡ����������ӡ
    while (stack != NULL)
    {
        printf("%d", pop(&stack));
    }
    printf("\n");

    // ����ջ
    destroy(&stack);
}

int main()
{
    int number = 10; // ʾ������10ת��Ϊ������
    printf("The binary representation of %d is: ", number);
    printBinary(number);
    return 0;
}