#include<stdio.h>
#include<math.h>
int main(){
	int ifz(int n);//引入判断质数的函数 
	int a,i;//a为输入的值，i用于循环 
	scanf("%d",&a);
	for(i=2;i<a;i++){
		if(a%i==0){
			printf("%d",a/i);
			break;
		}
	}
	return 0; 
}
