#include<stdio.h>
int main(){
	int a[100];int n;//n代表数据的个数，a是存放数据的列表 
	int i;//用于循环计数
	scanf("%d",&n);
	for(i=0;i<n;i++){//录入部分 
		scanf("%d",&a[i]);
	} 
	int sum=0,ave;//ave是平均值 
	//计算平均值
	for(i=0;i<n;i++){
		sum+=a[i];
	}
	ave=sum/n;
	int step=0; 
	for(i=0;i<n;i++){
		if(a[i]!=ave){
			a[i+1]+=(a[i]-ave);//缺多少，向下一张牌堆“借”多少，出现负数也没关系， 
			a[i]=ave;//补齐 
			step++;
		}
	} 
	printf("%d",step);
	return 0;
} 
