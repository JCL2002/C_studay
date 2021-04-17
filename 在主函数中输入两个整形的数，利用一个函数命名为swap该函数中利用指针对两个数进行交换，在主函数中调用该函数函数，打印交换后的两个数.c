#include<stdio.h>
int main(){
	int x,y;int *px,*py;px=&x;py=&y;
	int swap(int *x,int *y);
	printf("«Î ‰»Îx,y:");
	scanf("%d %d",&x,&y); 
	swap(px,py);
	printf("x=%d y=%d",*px,*py);
	return 0;
}
int swap(int *x,int *y){
	int s;
	s=*x;*x=*y;*y=s;
}
