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
	printf("��������Ϣ������\n");
	scanf("%d",&n);
	puts("");
	printf("�밴��\"���� ѧ�� ���� ���֤\"��˳��������Ϣ\n");
	for(int i = 0;i < n;i ++ )
		scanf("%s %s %s %s",stu[i].name,stu[i].id,stu[i].np,stu[i].ic);
	puts("");
}

void print(){
	puts("     ���� ѧ�� ���� ���֤");
	for(int i = 0;i < n;i ++ )
		printf("%5d:%s %s %s %s\n",i,stu[i].name,stu[i].id,stu[i].np,stu[i].ic);
}
void search(char id[]){
	for(int i = 0;i < n;i ++ )
		if(strcmp(stu[i].id,id) == 0){
			printf("��ѯ���Ϊ��%s %s %s %s\n",stu[i].name,stu[i].id,stu[i].np,stu[i].ic);
			return; 
		}
		
}

int main(){
	input();
	print();
	
	puts("����������Ҫ��ѯ��ѧ�ţ�");
	char id[20];
	scanf("%s",id);
	search(id);
	 
	return 0;
}
