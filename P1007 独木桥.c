#include<stdio.h>
int Min(int x,int y){
	if(x>y) return y;
	else return x;
}
int Max(int x,int y){
	if(x>y) return x;
	else return y;
}
int main(){
	int L,N,location[5000],i;
	//输入部分 
	scanf("%d\n%d",&L,&N);
	for(i=0;i<N;i++){
		scanf("%d",&location[i]);
	}
	//求最小值，假设士兵都朝着离自己最近的方向去
	int min;
	min=Min(location[0],L-location[0]+1);
	for(i=1;i<N;i++){
		min=Max(min,Min(location[i],L-location[i]+1));
	}
	//求最大值，士兵撞面后交换方向，可以看成彼此穿过对方继续向前走，即基本情况于
	//求最小值相同，只不过初始方向改变
	int max;
	max=Max(location[0],L-location[0]+1);
	for(i=1;i<N;i++){
		max=Max(max,Max(location[i],L-location[i]+1));
	}
	printf("%d %d",min,max);
	return 0;
}
