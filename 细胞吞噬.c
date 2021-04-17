#include<stdio.h>
#include<math.h>
int main(){
	int x1,y1,r1,x2,y2,r2;
	scanf("%d %d %d %d %d %d",&x1,&y1,&r1,&x2,&y2,&r2);
	double dis;
	dis=1.0*sqrt(((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)));
	if(1.0*(r1+r2)<dis){
		printf("Phasocytose not started.");
	}
	else if(1.0*abs(r1+r2)==dis){
		printf("Start phagocytose.");
	}
	else if(1.0*abs(r1-r2)<dis){
		printf("Phagocytosing.");
	}
	else{
		printf("Phagocytose complete.");
	}
	return 0;
}
