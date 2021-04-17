#include<stdio.h>
int cow[100000];
int main(){
	int n,d;
	scanf("%d %d",&n,&d);
	int i;
	for(i=0;i<n;i++){
		scanf("%d",&cow[i]);
	}
	int num=0;int j;
	for(i=0;i<n-1;i++){
		for(j=i;j<n-1;j++){
			if(abs(cow[j+1]-cow[i])<=d){
				num++;
			}
		}
	}
	printf("%d",num);
	return 0;
}
