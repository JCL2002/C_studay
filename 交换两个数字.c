#include<stdio.h>
int main(){
	int swap(int *a,int*b);
	int a,b,*p_a=&a,*p_b=&b;
	scanf("%d %d",p_a,p_b);
	swap(p_a,p_b);
	return 0;
}
int swap(int *a,int*b){
	printf("%d %d",*b,*a);
}
