#include<stdio.h>
int main(){
	int a[10000];
	int n;
	scanf("%d",&n);
	int i,j=0;
	for(i=0;i<n;i++){//�������� 
		scanf("%d",&a[i]);
	}
	int num=1;
	for(i=1;i<n;i++){//�ҳ�ÿһ���������������� 
		if(a[i]-a[i-1]==1){
			num++;
		}
		else{
			a[j]=num;//���ҵĽ���ʼ�ձ�д����ȿ� 
			j++;
			num=1;
		}
	}
	int max=a[0];
	for(i=1;i<j;i++){//�ҳ��ȵ����ֵ 
		if(a[i]>max) max=a[i];
	}
	printf("%d",max);
	return 0;
}
