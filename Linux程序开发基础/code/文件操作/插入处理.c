#include <stdio.h>
#include <stdlib.h>

struct Student
{
    char name[10];
    int number, china, math, english;
    float avg;
};

int compare(struct Student *a, struct Student *b)
{
    int sa = a->china + a->math + a->english;
    int sb = b->china + b->math + b->english;

    if (sa < sb)
        return 1;
    else
        return -1;
}

int main()
{
    FILE *fp;
    fp = fopen("stu_sort", "w+");
    if (fp == NULL)
    {
        perror("文件打开错误");
        exit(1);
    }
    struct Student stu[10];
    fread(stu, sizeof(struct Student), 3, fp);
    puts("插入新的学生的信息：");
    scanf("%s %d %d %d %d", stu[3].name, &stu[3].number, &stu[3].china, &stu[3].math, &stu[3].english);
    for (int i = 0; i < 4; i++)
        stu[i].avg = 1.0 * (stu[i].china + stu[i].math + stu[i].english) / 3;

    for (int i = 0; i < 4; i++)
        for (int j = i + 1; j < 4; j++)
            if (compare(&stu[i], &stu[j]) > 0)
            {
                struct Student temp = stu[i];
                stu[i] = stu[j];
                stu[j] = temp;
            }

    fwrite(stu, sizeof(struct Student), 4, fp);
    fclose(fp);
    exit(0);
}