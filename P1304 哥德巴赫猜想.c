#include<stdio.h>
#include<math.h>
int main(){
	int N;
	scanf("%d",&N);
	int i,j;//i����ѭ����j�����ֽ� 
	for(i=4;i<=N;i+=2){
		for(j=2;j<=i/2;j++){
			if(if_zhi(j)){
				if(if_zhi(i-j)){
					printf("%d=%d+%d\n",i,j,i-j);
					break;
				}
			}
		}
	}
	return 0;
}
int if_zhi(int n){//�ж��ǲ������� 
	int i;
	if(!(n%2)&&n!=2){
		return 0;//��ż����һ���������� 
	}
	for(i=3;i<=sqrt(n);i+=2){
		if(n%i==0) return 0;
	}
	return 1;
}
