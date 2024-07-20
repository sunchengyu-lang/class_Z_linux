#include <stdio.h>
#include <string.h>

const int N = 110;

void my_Bubble_Sort(char str[][N], int n){
    char temp[N];

    for (int i = 0; i < n - 1; i ++ )
        for (int j = 0; j < n - i - 1; j ++ )
            if (strcmp(str[j], str[j + 1]) > 0){
                strcpy(temp, str[j]);
                strcpy(str[j], str[j + 1]);
                strcpy(str[j + 1], temp);
            }
}
int main(){
	int n;
    char str[N][N];
    
    scanf("%d", &n);
    for(int i = 0; i < n; i ++ )scanf("%s", str[i]);
    
    my_Bubble_Sort(str, n);
    
    for (int i = 0; i < n; i ++ )printf("%s ", str[i]);
    
    return 0;
}
