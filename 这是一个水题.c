#include<stdio.h>
struct student{
	char name[21];
	float H_math;
	float X_dai;
	float Eng;
	float ave;
};
int main(){
	struct student stu[3],tmp;
	int i,j;
	for(i=0;i<3;i++){
		scanf("%s %f %f %f",&(stu[i].name),&(stu[i].H_math),&(stu[i].X_dai),&(stu[i].Eng));
		stu[i].ave=(stu[i].H_math+stu[i].X_dai+stu[i].Eng)/3.0;
	} 
	//Ã°ÅİÅÅĞò
	for(i=0;i<2;i++){
		for(j=0;j<2-i;j++){
			if(stu[i].ave<stu[i+1].ave){
				tmp=stu[i];stu[i]=stu[i+1];stu[i+1]=tmp;
			}
		}
	} 
//	for(i=0;i<3;i++){
//		printf("%s\n%.2f\n",stu[i].name,stu[i].ave);
//	}
	printf("%s %.2f",stu[0].name,stu[0].ave);
	return 0;
}
