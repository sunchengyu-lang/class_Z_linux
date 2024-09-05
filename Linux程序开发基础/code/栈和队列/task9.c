#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// �ж��ַ����Ƿ�Ϊ����
bool isPalindrome(const char *str)
{
    int length = strlen(str);
    int left = 0;
    int right = length - 1;

    // �����˿�ʼ�����Ŀ���
    while (left < right)
    {
        if (str[left] != str[right])
        {
            return false; // ����κ�һ���ַ�����ͬ�����ǻ���
        }
        left++;
        right--;
    }

    return true; // �����ַ�����ͬ���ǻ���
}

int main()
{
    char str[MAX_LINE_LENGTH]; // ������󳤶�Ϊ100
    printf("Enter a string: ");
    fgets(str, MAX_LINE_LENGTH, stdin);

    // ȥ��ĩβ�Ļ��з�
    str[strcspn(str, "\n")] = 0;

    if (isPalindrome(str))
    {
        printf("The string '%s' is a palindrome.\n", str);
    }
    else
    {
        printf("The string '%s' is not a palindrome.\n", str);
    }

    return 0;
}