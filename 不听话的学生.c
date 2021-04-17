#include<stdio.h>
#define LEN sizeof(struct student_info)
struct student_info{
	char name[21];//学生姓名
	char number[21];//学号
	char clas[21];//班级
	char pro[21];//专业
	int sign;//签到情况 
};
int main(){
	struct student_info student[20];//初始化
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
