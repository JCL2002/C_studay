#include<stdio.h>
int main(){
	int a[10000],*p=a;
	int n,i,j,swap;//n����������i��j����ѭ��,swap���ڽ��� 
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	int count=0;//���ڼ���
	//��ʼð��
	for(i=0;i<n-1;i++){
		for(j=0;j<n-1-i;j++){
			if(*(p+j)>*(p+j+1)){//��Ҫ���� 
				count++;
				swap=*(p+j);*(p+j)=*(p+j+1);*(p+j+1)=swap;
			}
		}
	} 
	printf("%d",count);
	return 0;
}
