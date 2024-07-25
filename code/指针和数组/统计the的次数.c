#include <bits/stdc++.h>

const int N = 110;

int cntThe(char string[]){
	int ans = 0;
	while(*string != '\0'){
		if(*string == 't'){
			string ++ ;
			if(*string == 'h'){
				string ++ ;
				if(*string == 'e')ans ++ ;
			}
		}
		string ++ ;
	}
	return ans;
}

int main() {
	char string[N];
	scanf("%s",string);
	
	printf("The count of the is : %d\n",cntThe(string));
	
	return 0;	
}
