#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char filename[30];
    int chunk_size;
    FILE *fp;

    puts("请输入文件名:");
    scanf("%s", filename);
    puts("\n请输入每个分块的大小 (KB):");
    scanf("%d", &chunk_size);
    chunk_size *= 1024; // 将KB转换为字节

    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        perror("无法打开文件");
        exit(1);
    }

    // 找到文件总的字节数
    fseek(fp, 0, SEEK_END);
    int file_size = ftell(fp);
    rewind(fp); // 回到开头

    // 开始分割文件
    int chunk_num = file_size / chunk_size + (file_size % chunk_size ? 1 : 0); // 考虑正好的情况和有多余的情况
    for (int i = 0; i < chunk_num; i++)
    {
        char tempFilename[30];
        // 生成新的文件名，删除扩展名并在原始文件名后添加递增的字母
        strncpy(tempFilename, filename, strcspn(filename, "."));
        tempFilename[strcspn(filename, ".")] = '\0'; // 确保字符串以 null 终止
        snprintf(tempFilename, sizeof(tempFilename), "%s%c.txt", tempFilename, 'a' + i);

        FILE *output = fopen(tempFilename, "w");
        if (output == NULL)
        {
            perror("无法创建输出文件");
            fclose(fp);
            exit(1);
        }

        char buffer[chunk_size];
        size_t read_size = (i == chunk_num - 1) ? (file_size - (chunk_size * i)) : chunk_size;

        // 读取数据并写入到新文件
        size_t bytes_read = fread(buffer, 1, read_size, fp);
        fwrite(buffer, 1, bytes_read, output);

        fclose(output);
    }

    fclose(fp);
    return 0;
}