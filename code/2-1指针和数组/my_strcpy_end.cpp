#include <stdio.h>

const int N = 110;

char* my_strcpy_end(char *dest,char *src){
	while(*src != '\0'){
		*dest = *src;
		dest ++ ;
		src ++ ;
	}
	dest ++ ;
	*dest = '\0';
	return dest;
} 

int main(){
	char dest[N],src[N];
	scanf("&s",src);
	
	char *dest_end = my_strcpy_end(dest,src);
	return 0;
}
