#include <stdio.h>
#include <stdlib.h>

struct Student
{
    char name[10];
    int number, china, math, english;
};
int main()
{
    int n;
    char fn[30];
    puts("how many students in your class?");
    scanf("%d", &n);
    struct Student stu[n];
    puts("\nplease input filename:");
    scanf("%s", fn);
    puts("\nplease input name,number,China,math,English:");
    for (int i = 0; i < n; i++)
    {
        char temp[10];
        scanf("%s %s %d %d %d %d", temp, stu[i].name, &stu[i].number, &stu[i].china, &stu[i].math, &stu[i].english);
    }

    FILE *fp = fopen(fn, "w+");
    if (fp == NULL)
    {
        perror("文件打开错误");
        exit(1);
    }
    fwrite(stu, sizeof(struct Student), n, fp);

    for (int i = 0; i < n; i++)
        printf("%s %d %d %d %d\n", stu[i].name, stu[i].number, stu[i].china, stu[i].math, stu[i].english);

    fclose(fp);
    exit(0);
}