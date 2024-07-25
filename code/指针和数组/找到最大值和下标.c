#include <stdio.h>

const int N = 15,T = 10;

void search(int *pa,int n,int *pmax,int *pflag){
	*pmax = pa[0];
	
	for(int i = 0;i < n;i ++ ){
		if(pa[i] > *pmax){
			*pmax = pa[i];
			*pflag = i;
		}
	}
}

int main(){
	int a[N];
	int max,flag = -1;
	for(int i = 0;i < T;i ++ )scanf("%d",&a[i]);
	
	search(a,T,&max,&flag);
	
	printf("max:%d,maxn_flag:%d",max,flag);
	return 0;
} 
