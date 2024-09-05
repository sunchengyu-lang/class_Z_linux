#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static const int N = 1010;
// ���� max ����
int max(int a, int b)
{
    return a > b ? a : b;
}

// �ָ��ַ����ĺ���
char **splitStr(char *str, char ch)
{
    int cnt = 0, maxLen = 0, tmp = 0;
    char *temp = str;

    // �ȱ���һ�飬���㵥�������Լ�����ʵ��ַ���
    while (*temp)
    {
        if (*temp == ch && tmp) // ������������֮�����ո�
        {
            cnt++;
            maxLen = max(maxLen, tmp);
            tmp = 0;
        }
        else
            tmp++;
        temp++;
    }

    cnt++; // ���һ������
    if (tmp)
        maxLen = max(maxLen, tmp); // ��������ʳ���

    // �����ڴ�
    char **ans = (char **)malloc(cnt * sizeof(char *));
    if (ans == NULL)
    {
        puts("Memory allocation failed.");
        return NULL;
    }

    // �ٴα����ַ������ָ�洢����
    temp = str;

    for (int i = 0; i < cnt; i++)
    {
        ans[i] = (char *)malloc((maxLen + 1) * sizeof(char)); // Ϊÿ�����ʷ����㹻���ڴ�
        if (ans[i] == NULL)
        {
            puts("�ڴ����ʧ��");
            return NULL;
        }

        int len = 0;
        while (*temp != ch && *temp != '\0')
        {
            ans[i][len++] = *temp;
            temp++;
        }
        ans[i][len] = '\0'; // �����ֹ��
        temp++;             // �����ո�򵽴��ַ���ĩβ
    }

    return ans;
}

int main()
{
    char str[N];
    fgets(str, N, stdin); // �ӱ�׼�����ȡһ���ı�

    char **ans = splitStr(str, ' ');

    // ��ӡ�ָ��ĵ���
    if (ans != NULL)
    {
        for (int i = 0; ans[i] != NULL; i++)
        {
            printf("%s\n", ans[i]);
        }

        // �ͷ��ڴ�
        for (int i = 0; ans[i] != NULL; i++)
        {
            free(ans[i]);
        }
        free(ans);
    }

    return 0;
}