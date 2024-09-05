#include <stdio.h>
#include <stdlib.h>

struct Student
{
    char name[20];
    int number, age;
};

int main()
{
    char filename[20];
    FILE *fp;
    int n;
    puts("please input filename:");
    scanf("%s", filename);
    puts("\nplease input the number of students:");
    scanf("%d", &n);
    struct Student stu[n];
    puts("\nplease input name,number,age:");
    for (int i = 0; i < n; i++)
    {
        char temp[20];
        scanf("%s %s %d %d", temp, stu[i].name, &stu[i].number, &stu[i].age);
    }

    for (int i = 0; i < n; i++)
        if (i % 2 == 0)
            printf("%s %4d %4d\n", stu[i].name, stu[i].number, stu[i].age);

    fp = fopen(filename, "w");
    if (fp == NULL)
    {
        perror("文件打开错误");
        exit(1);
    }
    fwrite(stu, sizeof(struct Student), n, fp);
    fclose(fp);
    exit(0);
}