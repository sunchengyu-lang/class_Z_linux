#include <stdio.h>

const int N = 110;

void my_reverse(int a[], int n){
	int start = 0£¬end = n - 1;
	
    while (start < end) {
		//swap 
        int temp = a[start];
        a[start] = a[end];
        a[end] = temp;

        start++;
        end--;
    }
}
int main(){
	int a[N], n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)scanf("%d",&a[i]);
	
	my_reverse(a, n);
	
	for (int i = 0; i < n; i++)
		printf("%d ",a[i]);
		
	return 0;
}
