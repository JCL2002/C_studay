#include<stdio.h>
int main(){
	int a[100];int n;//n�������ݵĸ�����a�Ǵ�����ݵ��б� 
	int i;//����ѭ������
	scanf("%d",&n);
	for(i=0;i<n;i++){//¼�벿�� 
		scanf("%d",&a[i]);
	} 
	int sum=0,ave;//ave��ƽ��ֵ 
	//����ƽ��ֵ
	for(i=0;i<n;i++){
		sum+=a[i];
	}
	ave=sum/n;
	int step=0; 
	for(i=0;i<n;i++){
		if(a[i]!=ave){
			a[i+1]+=(a[i]-ave);//ȱ���٣�����һ���ƶѡ��衱���٣����ָ���Ҳû��ϵ�� 
			a[i]=ave;//���� 
			step++;
		}
	} 
	printf("%d",step);
	return 0;
} 
