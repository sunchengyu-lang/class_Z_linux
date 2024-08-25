#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 10 // ���е��������

typedef struct
{
    int front;                    // ��ͷָ��
    int rear;                     // ��βָ��
    int elements[MAX_QUEUE_SIZE]; // �����洢����Ԫ�ص�����
} Queue;

// ��ʼ������
void initQueue(Queue *q)
{
    q->front = 0;
    q->rear = 0;
}

// �ж϶����Ƿ�Ϊ��
int isQueueEmpty(const Queue *q)
{
    return q->front == q->rear;
}

// �ж϶����Ƿ�����
int isQueueFull(const Queue *q)
{
    return (q->rear + 1) % MAX_QUEUE_SIZE == q->front;
}

// ��Ӳ���
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

// ���Ӳ���
int dequeue(Queue *q)
{
    if (isQueueEmpty(q))
    {
        printf("Queue is empty.\n");
        return -1; // ����-1Ϊ�Ƿ�ֵ����ʾ����
    }
    int value = q->elements[q->front];
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return value;
}

// ���������е�����Ԫ��
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