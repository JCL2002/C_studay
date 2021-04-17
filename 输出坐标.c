#include<stdio.h>
struct V{
	float x;
	float y;
};
int main(){
	struct V v1,v2;
	scanf("%f %f %f %f",&(v1.x),&(v1.y),&(v2.x),&(v2.y));
	printf("(%.1f, %.1f)",v1.x-v2.x,v1.y-v2.y);
	return 0;
}
