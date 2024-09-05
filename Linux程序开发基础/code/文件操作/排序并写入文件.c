#include <stdio.h>
#include <stdlib.h>

struct Student
{
    char name[10];
    int number, china, math, english;
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
    fp = fopen("stu", "r");
    if (fp == NULL)
    {
        perror("stu文件打开错误");
        exit(1);
    }
    struct Student stu[10];
    const int n = 3;
    fread(stu, sizeof(struct Student), n, fp);
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (compare(&stu[i], &stu[j]) > 0)
            {
                struct Student temp = stu[i];
                stu[i] = stu[j];
                stu[j] = temp;
            }

    for (int i = 0; i < n; i++)
        printf("%s %d %d %d %d\n", stu[i].name, stu[i].number, stu[i].china, stu[i].math, stu[i].english);

    FILE *nfp;
    nfp = fopen("stu_sort", "w");
    fwrite(stu, sizeof(struct Student), n, nfp);
    fclose(nfp);
    fclose(fp);
    exit(0);
}