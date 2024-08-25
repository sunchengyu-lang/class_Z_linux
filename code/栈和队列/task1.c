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
    newNode->next = s;
    s = newNode;
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

// 栈的遍历
void traverse(Stack s)
{
    while (s != NULL)
    {
        printf("%d ", s->data);
        s = s->next;
    }
    printf("\n");
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