#include<stdio.h>
struct student{
	char name[21];//ѧ������
	int exam_score;//��ĩƽ���ɼ�
	int class_score;//�༶����ɼ�
	char leader;//�Ƿ���ѧ���ɲ�
	char west;//�Ƿ�������ѧ��
	int chapter;//�����������
	int award;//��ѧ������ 
};
int main(){
	struct student peo[100];
	int n;//ѧ������
	int i;//����ѭ��
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%s %d %d %c %c %d",&(peo[i].name),&(peo[i].exam_score),&(peo[i].class_score),&(peo[i].leader),&(peo[i].west),&(peo[i].chapter));
		peo[i].award=0;//�����ʼ��Ϊ0 
		if(peo[i].chapter&&(peo[i].exam_score>80)){//Ժʿ���� 
			peo[i].award+=8000; 
		}
		if((peo[i].exam_score>85)&&(peo[i].class_score>80)){//���Ľ��� 
			peo[i].award+=4000;
		}
		if(peo[i].exam_score>90){//�ɼ����㽱 
			peo[i].award+=2000;
		}
		if((peo[i].west=='Y')&&(peo[i].exam_score>85)){//������ѧ�� 
			peo[i].award+=1000; 
		}
		if((peo[i].leader=='Y')&&(peo[i].class_score>80)){//�༶���׽� 
			peo[i].award+=850; 
		}
	} 
	int max_i=0;//�����±� 
	int max=peo[0].award;//���ѧ�� 
	int total=max;
	for(i=1;i<n;i++){//����� 
		if(peo[i].award>max){
			max=peo[i].award;
			max_i=i;
		}
		total+=peo[i].award;
	}
	printf("%s\n%d\n%d",peo[max_i].name,max,total);
	return 0;
}
