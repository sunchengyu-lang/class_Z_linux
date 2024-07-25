#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *insert(const char *s1, const char *s2, int n){
	int len1 = strlen(s1),len2 = strlen(s2); 
	int len = len1 + len2;
	
	
	char *res = (char*)malloc((len + 1) * sizeof(char));
	
	strncpy(res, s1, n);
	strcpy(res + n, s2);
	strcpy(res + n + len2, s1 + n); 
	
	return res;
}

int main(){
	int n;
	char s1[100], s2[100];

	scanf("%d", &n);
	scanf("%s%s", s1, s2);
	char *result = insert(s1, s2, n);

	
	printf("The string obtained after inserting the substring is: %s\n", result);

	free(result);

	return 0;
}
