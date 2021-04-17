#include<stdio.h>
#define True 1
#define False 0
#define rank_on False //改为True启用按秩合并 
int list[1000000];

int rank[1000000];//高度 

void init(){//数组初始化 
	int i;
	if (rank_on){
		for(i=0;i<1000000;i++){
			list[i]=i;
			rank[i]=1;
		}
	} 
	else{
		for(i=0;i<1000000;i++){
			list[i]=i;
		}
	}
} 

int find_root(int a){//找根 
	int a_o=a,next; 
	while(True){
		if(list[a]==a){
			break;//此时a就是根 
		}
		else{
			a=list[a];
		}
	}
	//路径压缩
	while(True){
		if(a_o==a){
			return a;
		}
		else{
			next=list[a_o];
			list[a_o]=a;//统一指向根
			a_o=next; 
		}
	}
}


void Union(int a,int b){
	int root_a,root_b;
	root_a=find_root(a);root_b=find_root(b);
	if(rank_on){//按秩合并 
		if(rank[root_a]>rank[root_b]){
			list[root_b]=root_a;
		}
		else if(rank[root_a]<rank[root_b]){
			list[root_a]=root_b;
		}
		else{
			list[root_a]=root_b;
			rank[root_b]++;
		}
	}
	else{
		list[root_a]=root_b;
	} 
}

int main(){
	init();//初始化数组 
	
	return 0;
}
