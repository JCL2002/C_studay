#include<stdio.h>
int main(){
	int n;
	int num(int);
	scanf("%d",&n);
	printf("%d",num(n));
	return 0;
}
int num(int n){
	if(n==1){
		return 1;
	}
	else{
		int sum=1;
		int i;
		for(i=1;i<=(n/2);i++){
			sum+=num(i);
		}
		return sum;
	}
}
