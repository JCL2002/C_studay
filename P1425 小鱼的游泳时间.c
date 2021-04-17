#include<stdio.h>
int main(){
	int a,b,c,d;
	scanf("%d %d %d %d",&a,&b,&c,&d);
	int e,f;
	if(d-b>=0){
		e=c-a;
		f=d-b;
	}
	else{
		e=c-a-1;
		f=60+d-b;
	}
	printf("%d %d",e,f);
	return 0;
}
