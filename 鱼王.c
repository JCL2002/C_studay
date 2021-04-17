#include<stdio.h>
int main(){
	int a[100000],n,i;//列表长度得足够
	scanf("%d",&n);
	//输入部分
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	//找出最大值
	int max=a[0];
	for(i=1;i<n;i++){
		if(a[i]>max){
			max=a[i];
		}
	}
	//统计最大值出现的次数
	//只出现一次输出下标+1
	int times=0,xiabiao;
	for(i=0;i<n;i++){
		if(a[i]==max){
			times++;//出现次数
			xiabiao=i+1;//下标+1 ，只有当 当前元素是最大时才统计下标
		}
	}
	//判断
	if(times==1){
		printf("%d",xiabiao);
	}
	else{
		printf("-1");
	}
	return 0;
}
