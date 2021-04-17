#include<stdio.h>
int main(){
	int a[10000],*p=a;
	int n,i,j,swap;//n代表数量，i、j用于循环,swap用于交换 
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	int count=0;//用于计数
	//开始冒泡
	for(i=0;i<n-1;i++){
		for(j=0;j<n-1-i;j++){
			if(*(p+j)>*(p+j+1)){//需要交换 
				count++;
				swap=*(p+j);*(p+j)=*(p+j+1);*(p+j+1)=swap;
			}
		}
	} 
	printf("%d",count);
	return 0;
}
