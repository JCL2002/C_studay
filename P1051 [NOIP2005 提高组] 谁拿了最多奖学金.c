#include<stdio.h>
struct student{
	char name[21];//学生姓名
	int exam_score;//期末平均成绩
	int class_score;//班级评议成绩
	char leader;//是否是学生干部
	char west;//是否是西部学生
	int chapter;//发表的论文数
	int award;//奖学金数量 
};
int main(){
	struct student peo[100];
	int n;//学生数量
	int i;//用于循环
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%s %d %d %c %c %d",&(peo[i].name),&(peo[i].exam_score),&(peo[i].class_score),&(peo[i].leader),&(peo[i].west),&(peo[i].chapter));
		peo[i].award=0;//奖金初始化为0 
		if(peo[i].chapter&&(peo[i].exam_score>80)){//院士奖金 
			peo[i].award+=8000; 
		}
		if((peo[i].exam_score>85)&&(peo[i].class_score>80)){//五四奖金 
			peo[i].award+=4000;
		}
		if(peo[i].exam_score>90){//成绩优秀奖 
			peo[i].award+=2000;
		}
		if((peo[i].west=='Y')&&(peo[i].exam_score>85)){//西部奖学金 
			peo[i].award+=1000; 
		}
		if((peo[i].leader=='Y')&&(peo[i].class_score>80)){//班级贡献奖 
			peo[i].award+=850; 
		}
	} 
	int max_i=0;//最大的下标 
	int max=peo[0].award;//最大奖学金 
	int total=max;
	for(i=1;i<n;i++){//找最大 
		if(peo[i].award>max){
			max=peo[i].award;
			max_i=i;
		}
		total+=peo[i].award;
	}
	printf("%s\n%d\n%d",peo[max_i].name,max,total);
	return 0;
}
