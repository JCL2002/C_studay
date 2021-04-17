#include<stdio.h>
struct student{
	int number;
	char name[21];
	int score;//他这个题又不说分数是整型还是实数型 
};
int main(){
	struct student stu[512],Max,carry[256];
	int N;int max,i;
	int times=0;
	while(1){
	
	scanf("%d",&N);
	if(!N){
		break;
	}
	for(i=0;i<N;i++){
		scanf("%d %s %d",&(stu[i].number),&(stu[i].name),&(stu[i].score));
	}
	max=stu[0].score;
	Max=stu[0];
	for(i=1;i<N;i++){
		if(stu[i].score>max){
			max=stu[i].score;
			Max=stu[i];
		}
	}
	carry[times]=Max;times++;
	}
	for(i=0;i<times;i++){
		printf("%d %s\n",carry[i].number,carry[i].name);
	}
	return 0;
} 
