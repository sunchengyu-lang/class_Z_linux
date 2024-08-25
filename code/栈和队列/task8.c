#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100

// 清屏函数，用于清空屏幕上的显示内容
void clearScreen()
{
#if defined(_WIN32) || defined(_WIN64)
    system("cls");
#else
    system("clear");
#endif
}

// 显示当前行
void showLine(const char *line, size_t len)
{
    printf("%.*s", (int)len, line);
}

// 编辑行
void editLine(char *line, size_t *len, size_t *pos)
{
    char ch;
    while ((ch = getchar()) != '\n')
    {
        switch (ch)
        {
        case '#': // 退格
            if (*pos > 0)
            {
                memmove(line + *pos - 1, line + *pos, *len - *pos);
                (*len)--;
                (*pos)--;
            }
            break;
        case '@': // 清除
            *len = 0;
            *pos = 0;
            memset(line, 0, sizeof(char) * MAX_LINE_LENGTH);
            break;
        default:
            if (*len < MAX_LINE_LENGTH - 1)
            {
                line[*pos] = ch;
                (*pos)++;
                (*len)++;
            }
            break;
        }
        clearScreen();
        showLine(line, *len);
    }
}

int main()
{
    char line[MAX_LINE_LENGTH] = "";
    size_t len = 0;
    size_t pos = 0;

    printf("Enter your text (use '#' to backspace, '@' to clear):\n");
    editLine(line, &len, &pos);

    printf("\nFinal line: %s\n", line);
    return 0;
}