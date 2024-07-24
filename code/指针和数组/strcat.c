#include <stdio.h>

const int N = 55;

char* my_strcat(char *dest,char *src){
	char *dest_end = dest;
    while(*dest_end != '\0') dest_end ++ ; // ÕÒµ½destµÄÄ©Î²
	
	while(*src != '\0'){
		*dest_end = *src;
		src ++ ;
		dest_end ++ ;
	}
	*dest_end = '\0';
	return dest;
}

int main(){
	char dest[N * 2],src[N];
	scanf("%s%s",dest,src);
	
	my_strcat(dest,src);
	
	printf("my_strcat:%s\n",dest);
	return 0;
}
