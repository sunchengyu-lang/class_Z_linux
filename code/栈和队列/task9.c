#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// 判断字符串是否为回文
bool isPalindrome(const char *str)
{
    int length = strlen(str);
    int left = 0;
    int right = length - 1;

    // 从两端开始向中心靠近
    while (left < right)
    {
        if (str[left] != str[right])
        {
            return false; // 如果任何一对字符不相同，则不是回文
        }
        left++;
        right--;
    }

    return true; // 所有字符都相同，是回文
}

int main()
{
    char str[MAX_LINE_LENGTH]; // 假设最大长度为100
    printf("Enter a string: ");
    fgets(str, MAX_LINE_LENGTH, stdin);

    // 去掉末尾的换行符
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