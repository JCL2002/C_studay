#include<stdio.h>
int fun(int i,int target,int n){
	int res=0;
	if(i==n){
		return 1;
	}
	int cycle;
	for(cycle=0;cycle<=i*2-target;cycle++){
		res+=fun(i+1,target+cycle+1,n);
	}
	return res;
}

int main(){
	int n;
	scanf("%d",&n);
	printf("%d",fun(1,1,n));
	return 0;
}
