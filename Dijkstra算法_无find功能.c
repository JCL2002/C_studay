#include<stdio.h>
#define max 5000000;
int map[100][100];//�洢��ͼ��
int Distance[100];//����㵽�±��ľ���
char tst[100];//T/F
void init(){//��ʼ�� 
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
int end_test(int i,int Vertex){//tst������T�ĸ��� 
	int j;
	for(j=0;j<Vertex;j++){
		if(map[i][j]!=0&&map[i][j]!=5000000){
			if(tst[j]=='F'){//�ڵ�ǰ���ܴﵽ�ķ�Χ�ڻ��� û�дﵽ��̾���ĵ㣬�㷨�ͻ�û����
				return 0;
			}
		}
	}
	return 1;//һȦ����ȫ���ǡ�T�����㷨���� 
}
int find_min(int i,int Vertex){//tst������F��ӦDistance���������Сֵ 
	int min,min_j,j;
	min=max;
	for(j=0;j<Vertex;j++){
		if(map[i][j]!=0&&map[i][j]!=5000000){
			if(tst[j]=='F'){//��δ���ĵ��м�� 
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
	tst[i]='T';//��ǰ����Ϊ���ŵ�
	if(end_test(i,Vertex)) return;//��tst������ȫ��ΪTʱ�����㷨���� 
	int j;
	for(j=0;j<Vertex;j++){
		if(map[i][j]!=0&&map[i][j]!=5000000&&tst[j]=='F'){
			if(Distance[i]+map[i][j]<Distance[j]){
				Distance[j]=Distance[i]+map[i][j];//���¾��� 
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
	printf("�����붥������\n");
	scanf("%d",&Vertex);
	int Edge;//number of edge
	printf("������ߵ�����\n");
	scanf("%d",&Edge);
	int cycle,i,j,Edge_long;//cycle����ѭ����i��ʼ�ߣ�j���ձ� 
	printf("���������룺��㡢�յ㡢�߳�\n");
	for(cycle=0;cycle<Edge;cycle++){//¼������ߵ����� 
		scanf("%d %d %d",&i,&j,&Edge_long);
		map[i][j]=Edge_long;
	}
	printf("���������\n");
	scanf("%d",&i);
	Distance[i]=0;
	dij(i,Vertex);
	printf("������Ҫ��ѯ���յ�\n");
	scanf("%d",&j);
	printf("������%d\n",Distance[j]);
	return 0;
}
