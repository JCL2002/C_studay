#include<stdio.h>
int max(int x,int y){
	if(x>y) return x;
	else return y;
}
int main(){
	int T,M,i;
	int lst[100][2];int (*p)[2]=lst;
	//���벿�� 
	scanf("%d %d",&T,&M);
	for(i=0;i<M;i++){
		scanf("%d %d",*(p+i),*(p+i)+1);
	}
	//lst[num][0]����weight; lst[num][1]����value,num����ڼ���ҩ 
	int j;int dp[1001]={0};int *pdp=dp;
	for(i=0;i<M;i++){
		for(j=T;j>=0;j--){
			if(j<*(*(p+i))) break;
			*(pdp+j)=max(*(pdp+j),*(pdp+j-*(*(p+i)))+*(*(p+i)+1));
		}
		
	}
	printf("%d",*(pdp+T)); 
	return 0;
}
