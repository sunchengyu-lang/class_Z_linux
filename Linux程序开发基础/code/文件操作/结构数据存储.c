#include <stdio.h>
#include <stdlib.h>

struct student
{
    char id[10];
    char name[10];
    float score[3];
    float avg;
} stu[5];
int main()
{
    for (int i = 0; i < 5; i++)
    {
        printf("�������%d��ѧ������Ϣ:\n", i + 1);
        scanf("%s %s %f %f %f", stu[i].id, stu[i].name, &stu[i].score[0], &stu[i].score[1], &stu[i].score[2]);
        stu[i].avg = (stu[i].score[0] + stu[i].score[1] + stu[i].score[2]) / 3;
    }
    FILE *fp = fopen("stdu", "w");
    if (fp == NULL)
    {
        perror("stdu�ļ��򿪴���");
        exit(1);
    }

    fwrite(stu, sizeof stu, 5, fp);

    fclose(fp);
    exit(0);
}