#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    char filename[20];
    puts("please input filename");
    scanf("%s", filename);

    fp = fopen(filename, "r+");
    if (fp == NULL)
    {
        perror("Error opening file");
        exit(1);
    }

    char ch;
    while ((ch = fgetc(fp)) != EOF)
    {
        if (ch == '\t')
        {
            fprintf(fp, "    ");
            if (ferror(fp))
            {
                puts("Error writing file");
                fclose(fp);
                exit(1);
            }
        }
        else
        {
            fputc(ch, fp);
            if (ferror(fp))
            {
                puts("Error writing file");
                fclose(fp);
                exit(1);
            }
        }
    }
    puts("done");
    fclose(fp);
    exit(0);
}