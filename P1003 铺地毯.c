#include<stdio.h>
int main(){
	int list[10000][4],n,x,y,i;
	int (*lp)[4]=list;//定义行指针，用于增加运算速度 
	scanf("%d",&n);
	//把n个地毯的数据录入数组list，第n个地毯对应list[n-1] 
	for(i=0;i<n;i++){
		scanf("%d %d %d %d",*(lp+i)+0,*(lp+i)+1,*(lp+i)+2,*(lp+i)+3);
	}
	scanf("%d %d",&x,&y);
	//算法开始,n中存有行数，xy代表要求的位置，list[…][0]代表地毯起始x坐标， list[…][1]代表地毯起始y坐标，list[…][2] 、list[…][3] 分别代表地毯的宽度和高度 
	int mark=1;
	for(;mark&&n>0;n--){
		if((*(*(lp+n-1))+*(*(lp+n-1)+2))>=x&&*(*(lp+n-1))<=x){//横坐标被包含在内;即 list[…][0]+ list[…][2]>=x 且list[…][0]<=x
			if((*(*(lp+n-1)+1)+*(*(lp+n-1)+3))>=y&&*(*(lp+n-1)+1)<=y){//纵坐标被包含在内;即 list[…][1]+ list[…][3]>=y 且 list[…][1]<=y 
				printf("%d",n);
				mark=0;
			}
		}
	}
	if(mark){
		printf("-1");
	}
	return 0;
}
