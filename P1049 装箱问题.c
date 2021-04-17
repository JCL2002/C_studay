#include<stdio.h>
int main(){
	int min(int x,int y);
	int V,n;int a[30];//数组a用来存放各个物品的大小
	int backpack[20001];//定义一个足够大的背包,多出一个的原因是：第一个为0 
	int i,j;//用于循环
	scanf("%d %d",&V,&n);
	for(i=0;i<n;i++){//物体大小的录入 
		scanf("%d",&a[i]);
	} 
	for(i=20000;i>=0;i--){
		backpack[i]=i;//初始化背包，背包的每个下标对应了动态规划中当前容量（下标）对应的空间剩余 
	} 
	//动态规划
	for(i=0;i<n;i++){//遍历每一个物品，看看要不要放进去 
		for(j=V;j>=0;j--){//因为每次循环得用到小于当前背包剩余容量的数据，而只定义了一维数组，背包容量采用倒序循环不会覆盖之前的数据 
			if(j>=a[i]){//只有当背包容量有可能装得下当前物品时才进行规划 
				backpack[j]=min(backpack[j],backpack[j-a[i]]);//状态转移方程，在放和不放之间选一个最小的解 
			} 
		}
	} 
	printf("%d",backpack[V]); 
	return 0;
}
int min(int x,int y){//懂得都懂 
	if(x>y){
		return y;
	}
	else{
		return x;
	}
}
