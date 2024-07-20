#include <stdio.h>

int my_strcmp(char *p1,char *p2){
	while(*p1 != '\0' && *p2 != '\0'){
		if(*p1 != *p2)return *p1 - *p2;
		
		p1 ++ ,p2 ++ ;
	}
	
	if(*p1 == '\0' && *p2 == '\0')return 0;
	if(*p1 == '\0')return -1;
	if(*p2 == '\0')return 1;
} 

int main(){
	char s1[110],s2[110];
	scanf("%s%s",s1,s2);
	printf("%d\n",my_strcmp(s1,s2));
	return 0;
}


