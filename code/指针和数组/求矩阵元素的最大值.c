#include <stdio.h>

void findMax(int p[][3],int m,int n,int *pRow,int *pCol){
	int max = p[0][0];
	for(int i = 0;i < 2;i ++ )
		for(int j = 0;j < 3;j ++ ){
			if(p[i][j] > max){
				max = p[i][j];
				*pRow = i;
				*pCol = j;
			}
		}
}

int main(){
	int a[2][3];
	int ans_x,ans_y;
	for(int i = 0;i < 2;i ++ )
		for(int j = 0;j < 3;j ++ )
			scanf("%d",&a[i][j]);
	
	findMax(a,2,3,&ans_x,&ans_y);
	
	printf("行下标：%d，列下标：%d，最大值为：%d\n",ans_x,ans_y,a[ans_x][ans_y]);
	return 0;
}
