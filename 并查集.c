#include<stdio.h>
#define True 1
#define False 0
#define rank_on False //��ΪTrue���ð��Ⱥϲ� 
int list[1000000];

int rank[1000000];//�߶� 

void init(){//�����ʼ�� 
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

int find_root(int a){//�Ҹ� 
	int a_o=a,next; 
	while(True){
		if(list[a]==a){
			break;//��ʱa���Ǹ� 
		}
		else{
			a=list[a];
		}
	}
	//·��ѹ��
	while(True){
		if(a_o==a){
			return a;
		}
		else{
			next=list[a_o];
			list[a_o]=a;//ͳһָ���
			a_o=next; 
		}
	}
}


void Union(int a,int b){
	int root_a,root_b;
	root_a=find_root(a);root_b=find_root(b);
	if(rank_on){//���Ⱥϲ� 
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
	init();//��ʼ������ 
	
	return 0;
}
