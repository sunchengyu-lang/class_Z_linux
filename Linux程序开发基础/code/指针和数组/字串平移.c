#include <stdio.h>
#include <string.h>

const int N = 25;

void translateString(char *str,int n){
	char temp[N];
	int len = strlen(str);
	strncpy(temp,str,n);
	for(int i = 0;i < len - n;i ++ )str[i] = str[i+n];
	for(int i = len - n,j = 0;i < len;i ++ ,j ++ )str[i] = temp[j];
}
int main(){
	char str[N];
	int n;
	scanf("%s %d",str,&n);
	
	translateString(str,n);
	printf("The resulting string is%s\n",str);
	return 0;
}
