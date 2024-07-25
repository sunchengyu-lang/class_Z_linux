#include <stdio.h>

const int N = 30;


void merge(char *s1,char *s2,char *s){
	while(*s1 != '\0' && *s2 != '\0'){
		*s = *s1;
		s ++ ;
		*s = *s2;
		s ++ ;
		s1 ++ ,s2 ++ ;
	}
	while(*s1 != '\0')*s = *s1,s1 ++ ,s ++ ;
	while(*s2 != '\0')*s = *s2,s2 ++ ,s ++ ;
	s ++ ;
	*s = '\0';
}
int main(){
	char s1[N],s2[N],s[N*2];
	scanf("%s%s",s1,s2);
	
	merge(s1,s2,s);
	
	printf("The resulting string is%s\n",s);
	return 0;
} 
