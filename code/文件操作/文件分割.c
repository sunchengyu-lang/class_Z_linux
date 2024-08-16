#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char filename[30];
    int chunk_size;
    FILE *fp;

    puts("�������ļ���:");
    scanf("%s", filename);
    puts("\n������ÿ���ֿ�Ĵ�С (KB):");
    scanf("%d", &chunk_size);
    chunk_size *= 1024; // ��KBת��Ϊ�ֽ�

    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        perror("�޷����ļ�");
        exit(1);
    }

    // �ҵ��ļ��ܵ��ֽ���
    fseek(fp, 0, SEEK_END);
    int file_size = ftell(fp);
    rewind(fp); // �ص���ͷ

    // ��ʼ�ָ��ļ�
    int chunk_num = file_size / chunk_size + (file_size % chunk_size ? 1 : 0); // �������õ�������ж�������
    for (int i = 0; i < chunk_num; i++)
    {
        char tempFilename[30];
        // �����µ��ļ�����ɾ����չ������ԭʼ�ļ�������ӵ�������ĸ
        strncpy(tempFilename, filename, strcspn(filename, "."));
        tempFilename[strcspn(filename, ".")] = '\0'; // ȷ���ַ����� null ��ֹ
        snprintf(tempFilename, sizeof(tempFilename), "%s%c.txt", tempFilename, 'a' + i);

        FILE *output = fopen(tempFilename, "w");
        if (output == NULL)
        {
            perror("�޷���������ļ�");
            fclose(fp);
            exit(1);
        }

        char buffer[chunk_size];
        size_t read_size = (i == chunk_num - 1) ? (file_size - (chunk_size * i)) : chunk_size;

        // ��ȡ���ݲ�д�뵽���ļ�
        size_t bytes_read = fread(buffer, 1, read_size, fp);
        fwrite(buffer, 1, bytes_read, output);

        fclose(output);
    }

    fclose(fp);
    return 0;
}