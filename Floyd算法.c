#include<stdio.h>
#define max 500000
int A[100][100];
int path[100][100];
void init(){//初始化数组 
	int i,j;
	for(i=0;i<100;i++){
		for(j=0;j<100;j++){
			if(i==j){
				A[i][j]=0;//主对角线为0 
			}
			else{
				A[i][j]=max;
			}
			path[i][j]=-1;
		}
	}
}
void Find(int i,int j){//路径溯源 
	if(path[i][j]==-1){
		if(A[i][j]==max){
			printf("此路不通");
		}
		else{
			printf("%d->%d",i,j);
		}
	}
	else{
		int k;//中继点
		k=path[i][j];
		Find(i,k);
		printf("\b");
		Find(k,j); 
	}
	
}
int V;//V代表顶点数量
int main(){//Floyd算法 
	init();//初始化
	printf("请输入顶点数量：");scanf("%d",&V);
	if(V>100){//输入范围超出极限 
		printf("数据太大");
		return 1;
	}
	else if(V<=0){
		printf("非负整数");
		return 1;
	}//输入检测
	int i,j,k;//i为始边；j为终边；k为驻点
	int cycle;//用于循环
	printf("依次输入：边长、起点，终点，边长为0时结束\n");
	int inp;
	while(1){
		scanf("%d %d %d",&inp,&i,&j);
		if(inp==0){
			break;
		}
		if(i>99||j>99){
			printf("数据太大");
			return 1;
		}
		A[i][j]=inp;//矩阵的行代表起点，列代表终点 
	}//数据录入
	for(k=0;k<V;k++){//移动驻点 
		for(i=0;i<V;i++){
			if(A[i][k]!=0&&A[i][k]!=max){//由i可以到达k且不是k点本身 
				/*
				驻点k能起到缩短作用的前提是从i点能够到达k点 
				*/
				for(j=0;j<V;j++){
					if(A[k][j]!=0&&A[k][j]!=max){//由k可以到达j且不是k本身 
						if(A[i][k]+A[k][j]<A[i][j]){//状态转移方程 
							A[i][j]=A[i][k]+A[k][j];//更新距离信息 
							path[i][j]=k;//记录路径 
						}
					}
				}
			}
		}
	}
	printf("路径规划完毕\n");
	printf("请输入查询路径\n");
	scanf("%d %d",&i,&j);
	printf("路径长：%d\n",A[i][j]);
	Find(i,j);
	return 0;
}
