#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 100 // 定义栈的最大容量

// 定义栈结构体
typedef struct
{
    char items[MAX_SIZE]; // 栈中元素数组
    int top;              // 栈顶指针
} Stack;

// 初始化栈
void init(Stack *s)
{
    s->top = -1;
}

// 判断栈是否为空
bool isEmpty(const Stack *s)
{
    return s->top == -1;
}

// 入栈操作
bool push(Stack *s, char item)
{
    if (s->top >= MAX_SIZE - 1)
    { // 栈满
        printf("Stack overflow.\n");
        return false;
    }
    s->items[++(s->top)] = item;
    return true;
}

// 出栈操作
char pop(Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack underflow.\n");
        return '\0';
    }
    return s->items[(s->top)--];
}

// 获取栈顶元素
char peek(const Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack is empty.\n");
        return '\0';
    }
    return s->items[s->top];
}

// 检查括号是否匹配
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
            // 忽略非括号字符
            break;
        }
    }

    return isEmpty(&stack); // 如果栈空则所有括号都匹配
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