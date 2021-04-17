#include<stdio.h>
int main(){
	int list[101];
	int i=-1;
	do{
		i++;
		scanf("%d",list+i);
	}while(list[i]!=0);
	for(i--;i>=0;i--){
		printf("%d",list[i]);
		if(i){
			printf(" ");
		}
	}
	return 0;
}
