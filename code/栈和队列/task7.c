#include <stdio.h>
#include <stdlib.h>

// 定义节点结构体
typedef struct Node
{
    int data;          // 存储的数据
    struct Node *next; // 指向下一个节点的指针
} Node;

// 定义队列结构体
typedef struct Queue
{
    Node *front; // 队头指针
    Node *rear;  // 队尾指针
} Queue;

// 初始化队列
void initQueue(Queue *q)
{
    q->front = NULL;
    q->rear = NULL;
}

// 检查队列是否为空
int isQueueEmpty(const Queue *q)
{
    return q->front == NULL;
}

// 入队操作（逆序）
void enqueue(Queue *q, int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->data = value;
    newNode->next = q->front; // 新节点放在队头
    q->front = newNode;

    // 如果队列之前为空，更新队尾指针
    if (q->rear == NULL)
    {
        q->rear = newNode;
    }
}

// 出队操作
int dequeue(Queue *q)
{
    if (isQueueEmpty(q))
    {
        printf("Queue is empty.\n");
        return -1; // 假设-1为非法值，表示错误
    }
    Node *temp = q->rear;
    int value = temp->data;
    q->rear = q->rear->next;

    // 如果队列现在为空，更新队头指针
    if (q->rear == NULL)
    {
        q->front = NULL;
    }

    free(temp);
    return value;
}

// 遍历队列中的所有元素
void traverseQueue(const Queue *q)
{
    Node *current = q->rear;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// 销毁队列
void destroyQueue(Queue *q)
{
    Node *current = q->rear;
    Node *next;
    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
    q->front = q->rear = NULL;
}

int main()
{
    Queue queue;
    initQueue(&queue);

    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);

    printf("Queue after enqueues: ");
    traverseQueue(&queue);

    printf("Dequeued element: %d\n", dequeue(&queue));

    printf("Queue after dequeue: ");
    traverseQueue(&queue);

    destroyQueue(&queue);
    return 0;
}