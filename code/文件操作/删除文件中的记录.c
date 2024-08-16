#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Employee
{
    char name[20];
    int salary;
};

int main()
{
    FILE *fp;
    char fn[30];
    int n;

    puts("please input filename:");
    scanf("%s", fn);
    puts("\nplease input the number of employees:");
    scanf("%d", &n);
    struct Employee es[n];
    puts("\ninput name and salary:");
    for (int i = 0; i < n; i++)
        scanf("%s %d", es[i].name, &es[i].salary);

    puts("original data:");
    for (int i = 0; i < n; i++)
        printf("    %s   %d\n", es[i].name, es[i].salary);

    printf(" Input name which do you wangt to delete:");
    char tname[20];
    scanf("%s", tname);
    puts("\nNow,the content of file:");
    for (int i = 0; i < n; i++)
    {

        while (strcmp(es[i].name, tname) == 0)
        {
            struct Employee temp;
            temp = es[i];
            es[i] = es[n - 1];
            es[n - 1] = temp;
            n--;
            if (i == n - 1)
                break;
        }
    }
    for (int i = 0; i < n; i++)
        printf("    %s   %d\n", es[i].name, es[i].salary);
    fp = fopen(fn, "w");
    if (fp == NULL)
    {
        perror("Error opening file");
        return 1;
    }
    fwrite(es, sizeof(struct Employee), n, fp);
    fclose(fp);
    exit(0);
}