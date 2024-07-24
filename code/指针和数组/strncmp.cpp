#include <stdio.h>

 int my_strncmp(char *p1,char *p2,int n){
 	int cnt = 0;//¼ÆÊý 
	while(*p1 != '\0' && *p2 != '\0' && cnt < n){
		if(*p1 != *p2)return *p1 - *p2;
		
		p1 ++ ,p2 ++ ;
		cnt ++ ;
	}
	
	if(*p1 == '\0' && *p2 == '\0')return 0;
	if(*p1 == '\0')return -1;
	if(*p2 == '\0')return 1;
} 

int main(){
	int n; 
	char s1[110],s2[110];
	
	scanf("%d%s%s",&n,s1,s2);
	printf("%d\n",my_strncmp(s1,s2,n));
	return 0;
}


