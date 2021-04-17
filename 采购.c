#include<stdio.h>
int main(){
	float value,sum=0;
	int n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%f",&value);
		sum+=value;
	}
	printf("%.1f",sum);
	return 0;
}
