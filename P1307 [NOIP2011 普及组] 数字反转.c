#include<stdio.h>
int main(){
	int n;
	scanf("%d",&n);
	int a[10];
	int i=0;
	do{
		a[i]=n%10;
		n/=10;
		i++;
	}while(n);
	int j;
	for(j=0;j<i;j++){
		n+=a[j];
		n*=10;
	}
	n/=10;//n会多乘一次 
	printf("%d",n);
	return 0;
}
