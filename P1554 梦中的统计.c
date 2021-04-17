#include<stdio.h>
int main(){
	int number[10]={0,0,0,0,0,0,0,0,0,0};
	long long M,N,i,i_cache;
	scanf("%lld %lld",&M,&N);
	int j;
	
	for(i=M;i<=N;i++){
		i_cache=i;
		for(j=0;i_cache!=0;j++){
			number[i_cache%10]++;
			i_cache/=10;
		}
	}
	for(j=0;j<10;j++){
		if(j!=9){
			printf("%d ",number[j]);
		}
		else{
			printf("%d",number[9]);
		}
	}
	return 0;
}
