#include<stdio.h>
int main(){
	int N,sum=0;
	scanf("%d",&N);
	int in[40000];int i=0;
	while(sum!=N*N){
		scanf("%d",&in[i]);
		sum+=in[i];
		i++;
	}
	int j,k;int mark=1;
	sum=0;
	for(j=0;j<i;j++){
		mark*=-1;
		if(mark>0){
			for(k=0;k<in[j];k++){
				printf("1");
				sum++;
				if(sum%N==0){
					printf("\n");
				}
			}
		}
		else{
			for(k=0;k<in[j];k++){
				printf("0");
				sum++;
				if(sum%N==0){
					printf("\n");
				}
			}
		}
	}
	return 0;
}
