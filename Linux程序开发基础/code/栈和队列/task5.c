#include <stdio.h>
#include <stdlib.h>

// ����ڵ�ṹ��
typedef struct Node
{
    int data;          // �洢������
    struct Node *next; // ָ����һ���ڵ��ָ��
} Node;

// ������нṹ��
typedef struct Queue
{
    Node *front; // ��ͷָ��
    Node *rear;  // ��βָ��
} Queue;

// ��ʼ������
void initQueue(Queue *q)
{
    q->front = NULL;
    q->rear = NULL;
}

// ��Ӳ���
void enqueue(Queue *q, int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;

    if (q->rear == NULL)
    {
        q->front = q->rear = newNode;
    }
    else
    {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

// ���Ӳ���
int dequeue(Queue *q)
{
    if (q->front == NULL)
    {
        printf("Queue is empty.\n");
        return -1; // ����-1Ϊ�Ƿ�ֵ����ʾ����
    }
    Node *temp = q->front;
    int value = temp->data;
    q->front = q->front->next;
    free(temp);

    if (q->front == NULL)
    {
        q->rear = NULL;
    }

    return value;
}

// ���������е�����Ԫ��
void traverseQueue(Queue *q)
{
    Node *current = q->front;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// ���ٶ���
void destroyQueue(Queue *q)
{
    Node *current = q->front;
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