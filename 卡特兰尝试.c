#include<stdio.h>
long long C(int n,int m){
	int i;
	if(n>24){
		return C(n-1,m-1)+C(n-1,m);
	}
	long long molecule=1,denominator=1;
	int k=m;
	for(i=0;i<k;i++){
		molecule*=n;n--;
		denominator*=m;m--;
		
	}
	return molecule/denominator;
}
int main(){
	int n;
	scanf("%d",&n);
	long long result;
	result=C(2*n,n);
	result/=(n+1);
	printf("%lld",result);
	return 0;
}
