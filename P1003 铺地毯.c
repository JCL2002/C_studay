#include<stdio.h>
int main(){
	int list[10000][4],n,x,y,i;
	int (*lp)[4]=list;//������ָ�룬�������������ٶ� 
	scanf("%d",&n);
	//��n����̺������¼������list����n����̺��Ӧlist[n-1] 
	for(i=0;i<n;i++){
		scanf("%d %d %d %d",*(lp+i)+0,*(lp+i)+1,*(lp+i)+2,*(lp+i)+3);
	}
	scanf("%d %d",&x,&y);
	//�㷨��ʼ,n�д���������xy����Ҫ���λ�ã�list[��][0]�����̺��ʼx���꣬ list[��][1]�����̺��ʼy���꣬list[��][2] ��list[��][3] �ֱ�����̺�Ŀ�Ⱥ͸߶� 
	int mark=1;
	for(;mark&&n>0;n--){
		if((*(*(lp+n-1))+*(*(lp+n-1)+2))>=x&&*(*(lp+n-1))<=x){//�����걻��������;�� list[��][0]+ list[��][2]>=x ��list[��][0]<=x
			if((*(*(lp+n-1)+1)+*(*(lp+n-1)+3))>=y&&*(*(lp+n-1)+1)<=y){//�����걻��������;�� list[��][1]+ list[��][3]>=y �� list[��][1]<=y 
				printf("%d",n);
				mark=0;
			}
		}
	}
	if(mark){
		printf("-1");
	}
	return 0;
}
