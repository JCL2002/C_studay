#include<stdio.h>
int main(){
	int s,x;
	scanf("%d %d",&s,&x);
	float distance=0,speed=7.0;
	while(1){
		if(distance>=(float)(s-x)) break;
		distance+=speed;
		speed*=0.98;
	}
	distance+=speed;
	if(distance>(float)(s+x)){
		printf("n");
	}
	else{
		printf("y");
	}
	return 0;
}
