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

// �������Ƿ�Ϊ��
int isQueueEmpty(const Queue *q)
{
    return q->front == NULL;
}

// ��Ӳ���������
void enqueue(Queue *q, int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->data = value;
    newNode->next = q->front; // �½ڵ���ڶ�ͷ
    q->front = newNode;

    // �������֮ǰΪ�գ����¶�βָ��
    if (q->rear == NULL)
    {
        q->rear = newNode;
    }
}

// ���Ӳ���
int dequeue(Queue *q)
{
    if (isQueueEmpty(q))
    {
        printf("Queue is empty.\n");
        return -1; // ����-1Ϊ�Ƿ�ֵ����ʾ����
    }
    Node *temp = q->rear;
    int value = temp->data;
    q->rear = q->rear->next;

    // �����������Ϊ�գ����¶�ͷָ��
    if (q->rear == NULL)
    {
        q->front = NULL;
    }

    free(temp);
    return value;
}

// ���������е�����Ԫ��
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

// ���ٶ���
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