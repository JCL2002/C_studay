#include<stdio.h>
int main(){
	int n;int happy[3000];
	scanf("%d",&n);
	int i;int a,b;
	for(i=0;i<n;i++){
		scanf("%d %d",&a,&b);
		if(i){
			happy[i]=happy[i-1]+a+b-8;
		}
		else{
			happy[0]=a+b-8;
		}
	}
	int happy_all=0;
	for(i=0;i<n;i++){
		happy_all+=happy[i];
	}
	printf("%d",happy_all);
	return 0;
}
