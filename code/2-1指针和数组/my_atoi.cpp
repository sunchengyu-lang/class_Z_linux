#include <stdio.h>

const int N = 15;

int my_atoi(char *s){
	int res = 0;
	while (*s){
		res = res * 10 + (*s - '0');
		s ++ ;
	}
	return res;
}
int main(){
	int num;
	char str[N];
	scanf("%s", str);
	num = my_atoi(str);
	printf("atoi:%d\n", num);
	return 0;
}
