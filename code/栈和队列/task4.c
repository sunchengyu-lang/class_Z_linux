#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 10 // 队列的最大容量

typedef struct
{
    int front;                    // 队头指针
    int rear;                     // 队尾指针
    int elements[MAX_QUEUE_SIZE]; // 用来存储队列元素的数组
} Queue;

// 初始化队列
void initQueue(Queue *q)
{
    q->front = 0;
    q->rear = 0;
}

// 判断队列是否为空
int isQueueEmpty(const Queue *q)
{
    return q->front == q->rear;
}

// 判断队列是否已满
int isQueueFull(const Queue *q)
{
    return (q->rear + 1) % MAX_QUEUE_SIZE == q->front;
}

// 入队操作
int enqueue(Queue *q, int value)
{
    if (isQueueFull(q))
    {
        printf("Queue is full.\n");
        return 0;
    }
    q->elements[q->rear] = value;
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    return 1;
}

// 出队操作
int dequeue(Queue *q)
{
    if (isQueueEmpty(q))
    {
        printf("Queue is empty.\n");
        return -1; // 假设-1为非法值，表示错误
    }
    int value = q->elements[q->front];
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return value;
}

// 遍历队列中的所有元素
void traverseQueue(const Queue *q)
{
    if (isQueueEmpty(q))
    {
        printf("Queue is empty.\n");
        return;
    }
    int index = q->front;
    while (index != q->rear)
    {
        printf("%d ", q->elements[index]);
        index = (index + 1) % MAX_QUEUE_SIZE;
    }
    printf("\n");
}

int main()
{
    Queue queue;
    initQueue(&queue);

    enqueue(&queue, 1);
    enqueue(&queue, 2);
    enqueue(&queue, 3);

    printf("Queue after enqueues: ");
    traverseQueue(&queue);

    printf("Dequeued element: %d\n", dequeue(&queue));

    printf("Queue after dequeue: ");
    traverseQueue(&queue);

    return 0;
}