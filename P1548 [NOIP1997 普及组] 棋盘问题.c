#include<stdio.h>
#include<math.h>
int min(int a,int b){
	if(a>b) return b;
	else{
		return a;
	}
}
int main(){
	int N,M;
	scanf("%d %d",&N,&M);
	long long square=0,non=0;//正方形和长方形的数量 
	int wide,high;//长和宽
	int i,j;//用于循环 
	for(wide=1;wide<=M;wide++){
		if(wide<=min(N,M)){//正方形没有超纲时 
			square+=(long long)(N-wide+1)*(M-wide+1);
		}
		for(high=1;high<=N;high++){
			if(high!=wide){
				non+=(long long)(N-high+1)*(M-wide+1);
			}
		}
	}
	printf("%lld %lld",square,non);
	return 0;
}
