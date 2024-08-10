#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static const int N = 1010;
// 定义 max 函数
int max(int a, int b)
{
    return a > b ? a : b;
}

// 分割字符串的函数
char **splitStr(char *str, char ch)
{
    int cnt = 0, maxLen = 0, tmp = 0;
    char *temp = str;

    // 先遍历一遍，计算单词数，以及最长单词的字符数
    while (*temp)
    {
        if (*temp == ch && tmp) // 考虑两个单词之间多个空格
        {
            cnt++;
            maxLen = max(maxLen, tmp);
            tmp = 0;
        }
        else
            tmp++;
        temp++;
    }

    cnt++; // 最后一个单词
    if (tmp)
        maxLen = max(maxLen, tmp); // 更新最长单词长度

    // 分配内存
    char **ans = (char **)malloc(cnt * sizeof(char *));
    if (ans == NULL)
    {
        puts("Memory allocation failed.");
        return NULL;
    }

    // 再次遍历字符串，分割并存储单词
    temp = str;

    for (int i = 0; i < cnt; i++)
    {
        ans[i] = (char *)malloc((maxLen + 1) * sizeof(char)); // 为每个单词分配足够的内存
        if (ans[i] == NULL)
        {
            puts("内存分配失败");
            return NULL;
        }

        int len = 0;
        while (*temp != ch && *temp != '\0')
        {
            ans[i][len++] = *temp;
            temp++;
        }
        ans[i][len] = '\0'; // 添加终止符
        temp++;             // 跳过空格或到达字符串末尾
    }

    return ans;
}

int main()
{
    char str[N];
    fgets(str, N, stdin); // 从标准输入读取一行文本

    char **ans = splitStr(str, ' ');

    // 打印分割后的单词
    if (ans != NULL)
    {
        for (int i = 0; ans[i] != NULL; i++)
        {
            printf("%s\n", ans[i]);
        }

        // 释放内存
        for (int i = 0; ans[i] != NULL; i++)
        {
            free(ans[i]);
        }
        free(ans);
    }

    return 0;
}