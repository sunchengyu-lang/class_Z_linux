#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *f1p, *f2p;
    // ֱ��׷��
    f1p = fopen("sentence1.txt", "a");
    if (f1p == NULL)
    {
        perror("��sentence1.txt����");
        exit(1);
    }
    f2p = fopen("sentence2.txt", "r");
    if (f2p == NULL)
    {
        perror("��sentence2.txt����");
        exit(1);
    }

    char str[110];
    fgets(str, sizeof(str), f2p);
    fputs(str, f1p);
    fclose(f1p);
    fclose(f2p);
    exit(0);
}