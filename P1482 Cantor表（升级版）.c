#include<stdio.h>
int test(int a,int b){//检查是否为最简 
	int i;
	for(i=2;i<=a&&i<=b;i++){//遍历公因数 
		if(a%i==0&&b%i==0) return i;
	}
	return 0;
}
int main(){
	int b1,a1,b2,a2,b,a;
	int i;
	scanf("%d/%d",&b1,&a1);
	scanf("%d/%d",&b2,&a2);
	b=b1*b2;a=a1*a2;
	while(1){
		i=test(a,b);
		if(i){
			a/=i;b/=i;
		}
		else{
			break;
		}
	}
	printf("%d %d",a,b);
	return 0;
}
