#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100 // �������Ա���������

// ����Ԫ�ص����Ա�
void insert(int *list, int *size, int value)
{
    if (*size < MAX_SIZE)
    {
        list[*size] = value;
        (*size)++;
    }
}

// ����Ԫ���Ƿ����б���
bool search(int *list, int size, int value)
{
    for (int i = 0; i < size; i++)
        if (list[i] == value)
            return true;

    return false;
}

int main()
{
    int LA[] = {1, 2, 3, 4}; // ���� A
    int LB[] = {3, 4, 5, 6}; // ���� B
    int LC[MAX_SIZE];        // ������� C
    int sizeA = sizeof(LA) / sizeof(LA[0]);
    int sizeB = sizeof(LB) / sizeof(LB[0]);
    int sizeC = 0;

    // ������ A ��Ԫ�ز��뵽 LC ��
    for (int i = 0; i < sizeA; i++)
        insert(LC, &sizeC, LA[i]);

    // ������ B �в��ڼ��� A �е�Ԫ�ز��뵽 LC ��
    for (int i = 0; i < sizeB; i++)
        if (!search(LC, sizeC, LB[i]))
            insert(LC, &sizeC, LB[i]);

    // ��ӡ������� C
    printf("The union of A and B is: ");
    for (int i = 0; i < sizeC; i++)
        printf("%d ", LC[i]);

    printf("\n");

    return 0;
}
