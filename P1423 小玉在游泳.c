#include<stdio.h>
int main(){
	float distance,distance_swim,step=2.0;
	scanf("%f",&distance);
	int i=0;
	while(1){
		distance_swim+=step;
		step*=0.98;
		i++;
		if(distance_swim>=distance) break;
	}
	printf("%d",i);
	return 0;
}
