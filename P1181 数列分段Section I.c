#include<stdio.h>
int n[100000];
int main(){
	int N,M;
	scanf("%d %d",&N,&M);
	int i,m=M;
	int tmp;
	int times=1;
	for(i=0;i<N;i++){
		scanf("%d",&tmp);
		if(m-tmp>=0){
			m-=tmp;
		}
		else{
			m=M;
			m-=tmp;
			times++;
		}
	}
	printf("%d",times);
	return 0;
}
