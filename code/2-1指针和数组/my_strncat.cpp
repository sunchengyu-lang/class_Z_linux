#include <stdio.h>

const int N = 55;

char* my_strncat(char *dest,const char *src,size_t n){
	char *dest_end = dest;
    while(*dest_end != '\0') dest_end ++ ; // ÕÒµ½destµÄÄ©Î²
	
	size_t cnt = 0;
	while(*src != '\0' && cnt < n){
		*dest_end = *src;
		src ++ ;
		dest_end ++ ;
		cnt ++ ; 
	}
	*dest_end = '\0';
	return dest;
}

int main(){
	size_t n;
	char dest[N * 2],src[N];
	scanf("%zu",&n);
	scanf("%s%s",dest,src);
	
	my_strncat(dest,src,n);
	
	printf("my_strncat:%s\n",dest);
	return 0;
}
