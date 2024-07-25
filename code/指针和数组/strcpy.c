#include <stdio.h>

const int N = 110;

void my_strcpy(char *dest,char *src){\
	
	while(*src != '\0'){
		*dest = *src;
		dest ++ ;
		src ++ ;
	}
	dest ++ ;
	*dest = '\0';
}
int main(){
	char dest[N],src[N];
	scanf("%s",src);
	
	my_strcpy(dest,src);
	
	printf("dest:%s\n",dest);
	return 0;
}
