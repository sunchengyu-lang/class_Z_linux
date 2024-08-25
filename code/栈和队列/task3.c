#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 100 // ����ջ���������

// ����ջ�ṹ��
typedef struct
{
    char items[MAX_SIZE]; // ջ��Ԫ������
    int top;              // ջ��ָ��
} Stack;

// ��ʼ��ջ
void init(Stack *s)
{
    s->top = -1;
}

// �ж�ջ�Ƿ�Ϊ��
bool isEmpty(const Stack *s)
{
    return s->top == -1;
}

// ��ջ����
bool push(Stack *s, char item)
{
    if (s->top >= MAX_SIZE - 1)
    { // ջ��
        printf("Stack overflow.\n");
        return false;
    }
    s->items[++(s->top)] = item;
    return true;
}

// ��ջ����
char pop(Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack underflow.\n");
        return '\0';
    }
    return s->items[(s->top)--];
}

// ��ȡջ��Ԫ��
char peek(const Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack is empty.\n");
        return '\0';
    }
    return s->items[s->top];
}

// ��������Ƿ�ƥ��
bool checkBrackets(const char *str)
{
    Stack stack;
    init(&stack);

    for (int i = 0; str[i] != '\0'; i++)
    {
        switch (str[i])
        {
        case '(':
        case '{':
        case '[':
            push(&stack, str[i]);
            break;
        case ')':
            if (peek(&stack) == '(')
                pop(&stack);
            else
                return false;
            break;
        case '}':
            if (peek(&stack) == '{')
                pop(&stack);
            else
                return false;
            break;
        case ']':
            if (peek(&stack) == '[')
                pop(&stack);
            else
                return false;
            break;
        default:
            // ���Է������ַ�
            break;
        }
    }

    return isEmpty(&stack); // ���ջ�����������Ŷ�ƥ��
}

int main()
{
    char input[] = "{[()]}";
    if (checkBrackets(input))
    {
        printf("The brackets in the string '%s' are correctly matched.\n", input);
    }
    else
    {
        printf("The brackets in the string '%s' are not correctly matched.\n", input);
    }
    return 0;
}