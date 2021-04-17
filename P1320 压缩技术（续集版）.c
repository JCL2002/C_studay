#include<stdio.h>
#include<string.h> 
int main(){
	char in[200][200];
	scanf("%s",&in[0]);//先输入一行 
	int N;int i;
	N=strlen(in[0]);
	for(i=1;i<N;i++){
		scanf("%s",&in[i]);
	}
	int j,k;int mark=1;//mark大于0时统计为0的个数小于0时统计为1的个数 
	int num=0;
	printf("%d ",N);
	for(j=0;j<N;j++){
		for(k=0;k<N;k++){
			if(in[j][k]=='0'){
				if(mark>0){
					num++;
				}
				else{//符号发生改变
					printf("%d ",num);
					mark*=-1;
					num=1;
				}
			}
			else{
				if(mark>0){//符号发生改变 
					printf("%d ",num);
					mark*=-1;
					num=1;
				}
				else{
					num++;
				}
			}
		}
	}
	printf("%d",num);//最后还会残留一个 
	return 0;
}
