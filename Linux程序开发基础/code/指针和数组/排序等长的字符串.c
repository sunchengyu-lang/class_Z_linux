#include <stdio.h>
#include <string.h>
 
using namespace std;

const int N = 110,T = 10;
 
void sort(char str[][N]){
	char temp[N];
	
	for(int i = 1;i < T;i ++ )
		for(int j = i;j < T;j ++ )
			if(strcmp(str[j-1],str[j]) > 0){
				strcpy(temp,str[j-1]);
				strcpy(str[j-1],str[j]);
				strcpy(str[j],temp);
			}

}

int main(){
	char strings[N][N];
	for(int i = 0;i < T;i ++ )scanf("%s",&strings[i]);
	
	sort(strings);
	
	puts("result:");
	for(int i = 0;i < T;i ++ )printf("%s\n",strings[i]);
	
	return 0;
} 
