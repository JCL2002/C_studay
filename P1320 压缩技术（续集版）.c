#include<stdio.h>
#include<string.h> 
int main(){
	char in[200][200];
	scanf("%s",&in[0]);//������һ�� 
	int N;int i;
	N=strlen(in[0]);
	for(i=1;i<N;i++){
		scanf("%s",&in[i]);
	}
	int j,k;int mark=1;//mark����0ʱͳ��Ϊ0�ĸ���С��0ʱͳ��Ϊ1�ĸ��� 
	int num=0;
	printf("%d ",N);
	for(j=0;j<N;j++){
		for(k=0;k<N;k++){
			if(in[j][k]=='0'){
				if(mark>0){
					num++;
				}
				else{//���ŷ����ı�
					printf("%d ",num);
					mark*=-1;
					num=1;
				}
			}
			else{
				if(mark>0){//���ŷ����ı� 
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
	printf("%d",num);//��󻹻����һ�� 
	return 0;
}
