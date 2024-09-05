#include <stdio.h>
#include <stdlib.h>

// 定义节点结构体
typedef struct Node
{
    int data;          // 存储的数据
    struct Node *next; // 指向下一个节点的指针
} Node;

// 定义栈类型
typedef struct Node *Stack;

// 初始化栈
void init(Stack *s)
{
    *s = NULL;
}

// 入栈操作
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

// 出栈操作
int pop(Stack *s)
{
    if (*s == NULL)
    {
        printf("Stack is empty.\n");
        return -1; // 假设-1为非法值，表示错误
    }
    Node *temp = *s;
    int value = temp->data;
    *s = (*s)->next;
    free(temp);
    return value;
}

// 销毁栈
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

// 打印整数的二进制表示
void printBinary(int n)
{
    Stack stack;
    init(&stack);

    // 当n大于0时，进行除2取余的操作
    while (n > 0)
    {
        push(&stack, n % 2);
        n /= 2;
    }

    // 从栈中取出余数并打印
    while (stack != NULL)
    {
        printf("%d", pop(&stack));
    }
    printf("\n");

    // 销毁栈
    destroy(&stack);
}

int main()
{
    int number = 10; // 示例：将10转换为二进制
    printf("The binary representation of %d is: ", number);
    printBinary(number);
    return 0;
}