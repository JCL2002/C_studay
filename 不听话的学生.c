#include<stdio.h>
#define LEN sizeof(struct student_info)
struct student_info{
	char name[21];//ѧ������
	char number[21];//ѧ��
	char clas[21];//�༶
	char pro[21];//רҵ
	int sign;//ǩ����� 
};
int main(){
	struct student_info student[20];//��ʼ��
	int n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%s %s %s %s %d",&(student[i].name),&(student[i].number),&(student[i].clas),&(student[i].pro),&(student[i].sign)); 
	}
	int mark=1;
	for(i=0;i<n;i++){
		if(student[i].sign==0){
			mark=0;
			printf("%s %s %s %s\n",student[i].name,student[i].number,student[i].clas,student[i].pro);
		}
	}
	if(mark){
		printf("All the staff are here!");
	}
	return 0;
}
