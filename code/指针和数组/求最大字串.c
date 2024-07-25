#include <stdio.h>
#include <string.h>

int main(){
	char maxString[10],str[10];
	scanf("%s",str);
	strcpy(maxString,str);
	while(strcmp(str,"*****")){
		if(strcmp(str,maxString) > 0)strcpy(maxString,str);
		scanf("%s",str);
	}
	printf("result:%s\n",maxString);
	return 0;
}
