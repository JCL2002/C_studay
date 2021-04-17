#include<stdio.h>
#include<math.h>
int main(){
	int n;int i;
	int list[1000];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&list[i]);
	}
	int ABS[999];int mark;//maek用于标记是否有元素不符合要求
	for(i=0;i<n-1;i++){
		ABS[i]=abs(list[i]-list[i+1]);
	} 
	int j;
	for(i=1;i<n;i++){
		mark=1;
		for(j=0;j<n-1;j++){
			if(i==ABS[j]){
				mark=0;
				break;
			}
		}
		if(mark){
			printf("Not jolly");
			return 0;
		}
	}
	printf("Jolly");
	return 0;
}
