#include<stdio.h>
int main(){
	int a[100000],n,i;//�б��ȵ��㹻
	scanf("%d",&n);
	//���벿��
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	//�ҳ����ֵ
	int max=a[0];
	for(i=1;i<n;i++){
		if(a[i]>max){
			max=a[i];
		}
	}
	//ͳ�����ֵ���ֵĴ���
	//ֻ����һ������±�+1
	int times=0,xiabiao;
	for(i=0;i<n;i++){
		if(a[i]==max){
			times++;//���ִ���
			xiabiao=i+1;//�±�+1 ��ֻ�е� ��ǰԪ�������ʱ��ͳ���±�
		}
	}
	//�ж�
	if(times==1){
		printf("%d",xiabiao);
	}
	else{
		printf("-1");
	}
	return 0;
}
