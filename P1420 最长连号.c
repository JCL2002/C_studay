#include<stdio.h>
int main(){
	int a[10000];
	int n;
	scanf("%d",&n);
	int i,j=0;
	for(i=0;i<n;i++){//数据输入 
		scanf("%d",&a[i]);
	}
	int num=1;
	for(i=1;i<n;i++){//找出每一个连续的数串长度 
		if(a[i]-a[i-1]==1){
			num++;
		}
		else{
			a[j]=num;//查找的进度始终比写入进度快 
			j++;
			num=1;
		}
	}
	int max=a[0];
	for(i=1;i<j;i++){//找长度的最大值 
		if(a[i]>max) max=a[i];
	}
	printf("%d",max);
	return 0;
}
