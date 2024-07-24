#include <stdio.h>

const int N = 110;

void count(char *str,int *cnt1,int *cnt2,int *cnt3){
	int a = 0,b = 0,c = 0;
	while(*str != '\0'){
		char t = *str;
		if(t >= '0' && t <= '9') a ++ ;
		else if((t >= 'a' && t <= 'z') || (t >= 'A' && t <= 'Z'))b ++ ;
		else if(t == ' ')c ++ ;
		
		str ++ ;
	}
	*cnt1 = a;
	*cnt2 = b;
	*cnt3 = c;
}

int main(){
	char str[N];
	gets(str);
	int cnt1 = 0,cnt2 = 0,cnt3 = 0;//1.字母2.数字3.空格 
	count(str,&cnt1,&cnt2,&cnt3);
	
	printf("字母的个数为：%d,数字的个数为：%d,空格的个数为：%d.\n",cnt1,cnt2,cnt3);
	return 0;
}
