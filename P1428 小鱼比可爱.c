#include<stdio.h>
int main(){
	int number;
	scanf("%d",&number);
	int list[100];
	int i;
	for(i=0;i<number;i++){
		scanf("%d",&list[i]);
		
	}
	int j;
	int cuter;
	for(j=0;j<number;j++){
		cuter=0;
		for(i=0;i<=j;i++){
			if(list[i]<list[j]){
				cuter++;
			}
		}
		printf("%d",cuter);
		if(j<number-1){
			printf(" ");
		}
	}
	return 0;
}
