#include<stdio.h>
#define max 5000000;
int map[100][100];//存储“图”
int Distance[100];//从起点到下标点的距离
char tst[100];//T/F
void init(){//初始化 
	int i,j;
	for(i=0;i<100;i++){
		for(j=0;j<100;j++){
			if(i==j){
				map[i][j]=0;
			}
			else{
				map[i][j]=max;
			}
		}
		Distance[i]=max;
		tst[i]='F';
	}
} 
int end_test(int i,int Vertex){//tst数组中T的个数 
	int j;
	for(j=0;j<Vertex;j++){
		if(map[i][j]!=0&&map[i][j]!=5000000){
			if(tst[j]=='F'){//在当前点能达到的范围内还有 没有达到最短距离的点，算法就还没结束
				return 0;
			}
		}
	}
	return 1;//一圈下来全都是“T”，算法结束 
}
int find_min(int i,int Vertex){//tst数组中F对应Distance数组里的最小值 
	int min,min_j,j;
	min=max;
	for(j=0;j<Vertex;j++){
		if(map[i][j]!=0&&map[i][j]!=5000000){
			if(tst[j]=='F'){//在未检测的点中检测 
				if(Distance[j]<min){
					min=Distance[j];
					min_j=j;
				}else;
			}else;
		}
		else{
			continue;
		}
	}
	return min_j;
}
void dij(int i,int Vertex){
	tst[i]='T';//当前顶点为最优点
	if(end_test(i,Vertex)) return;//当tst数组中全部为T时代表算法结束 
	int j;
	for(j=0;j<Vertex;j++){
		if(map[i][j]!=0&&map[i][j]!=5000000&&tst[j]=='F'){
			if(Distance[i]+map[i][j]<Distance[j]){
				Distance[j]=Distance[i]+map[i][j];//更新距离 
			}
		}
	} 
	int min_j;
	min_j=find_min(i,Vertex);
	dij(min_j,Vertex); 
}
int main(){
	init();
	int Vertex;//number of vertex
	printf("请输入顶点数量\n");
	scanf("%d",&Vertex);
	int Edge;//number of edge
	printf("请输入边的数量\n");
	scanf("%d",&Edge);
	int cycle,i,j,Edge_long;//cycle用于循环；i：始边；j：终边 
	printf("请依次输入：起点、终点、边长\n");
	for(cycle=0;cycle<Edge;cycle++){//录入有向边的数据 
		scanf("%d %d %d",&i,&j,&Edge_long);
		map[i][j]=Edge_long;
	}
	printf("请输入起点\n");
	scanf("%d",&i);
	Distance[i]=0;
	dij(i,Vertex);
	printf("请输入要查询的终点\n");
	scanf("%d",&j);
	printf("距离是%d\n",Distance[j]);
	return 0;
}
