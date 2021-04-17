#include<stdio.h>
#include<math.h>
int main(){
	int N;
	scanf("%d",&N);
	int i,j;//i用作循环，j用作分解 
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
int if_zhi(int n){//判断是不是质数 
	int i;
	if(!(n%2)&&n!=2){
		return 0;//是偶数则一定不是质数 
	}
	for(i=3;i<=sqrt(n);i+=2){
		if(n%i==0) return 0;
	}
	return 1;
}
