#include <stdio.h>
#include <string.h>

struct Student{
	char name[20];
	char id[20];
	char np[20];//native place
	char ic[20];//identification card
}; 

struct Student stu[10];
int n;
void input(){
	printf("请输入信息条数：\n");
	scanf("%d",&n);
	puts("");
	printf("请按照\"姓名 学号 籍贯 身份证\"的顺序输入信息\n");
	for(int i = 0;i < n;i ++ )
		scanf("%s %s %s %s",stu[i].name,stu[i].id,stu[i].np,stu[i].ic);
	puts("");
}

void print(){
	puts("     姓名 学号 籍贯 身份证");
	for(int i = 0;i < n;i ++ )
		printf("%5d:%s %s %s %s\n",i,stu[i].name,stu[i].id,stu[i].np,stu[i].ic);
}
void search(char id[]){
	for(int i = 0;i < n;i ++ )
		if(strcmp(stu[i].id,id) == 0){
			printf("查询结果为：%s %s %s %s\n",stu[i].name,stu[i].id,stu[i].np,stu[i].ic);
			return; 
		}
		
}

int main(){
	input();
	print();
	
	puts("请输入你想要查询的学号：");
	char id[20];
	scanf("%s",id);
	search(id);
	 
	return 0;
}
