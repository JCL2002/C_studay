#include<stdio.h>
int main(){
	int n,a[10000];
	scanf("%d",&n);
	int i;
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	int num=0;
	for(i=1;i<n-1;i++){
		if(a[i]<a[i+1]&&a[i]<=a[i-1]){
			num++;
			i++;//��һ��һ�����ǣ�ֱ��������ʡʱ�� 
		}
	}
	printf("%d",num); 
	return 0;
}
