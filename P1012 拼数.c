#include<stdio.h>
int main(){
	int swap(int *p1,int *p2);//调用swap函数 
	int lenget(int n);//调用lenget函数
	int E(int x);//调用E函数
	int swap(int *p1,int *p2);//调用swap函数 
	int cmp(int p1,int l1,int p2,int l2);//调用cmp函数 
	int list[20];
	int n,i,j;//n代表个数，i、j用于循环 
	int *p_list=list;//练习指针的使用 
	scanf("%d",&n); 
	for(i=0;i<n;i++){//数据录入 
		scanf("%d",p_list+i);
	}
	//对数组list进行冒泡排序,并不是按照大小排序，而是按照不同顺序所能产生的权重来排序 
	int max=list[0];
	for(i=1;i<n;i++){
		for(j=0;j<n-i;j++){
			if(cmp(*(p_list+j),lenget(*(p_list+j)),*(p_list+j+1),lenget(*(p_list+j+1)))){//从大到小排序 
				swap(p_list+j,p_list+j+1);
			}
		//	printf("数组首指针地址：%d\n",p_list);
		}
	}
	//按序输出数组list
	for(i=0;i<n;i++){
		printf("%d",*(p_list+i));
	} 
	return 0;
}
int lenget(int n){//获取传入的整型的长度并返回整数 
	int i=1;int j=10;
	for(;n/j;i++){
		j*=10;
	}
	return i;
}
int E(int x){//计算10^x 
	int res=1;int i;
	for(i=0;i<x;i++){
		res*=10;
	}
	return res;
}
int cmp(int p1,int l1,int p2,int l2){//l1、l2分别代表p1、p2的长度 
	if (p1==p2){
		return 0;
	} 
	else{//计算p1p2和p2p1，比较他们的大小（遇事不决，量子力学） 
		if(p1*E(l2)+p2<p2*E(l1)+p1){//小于时需要交换 
			return 1;
		}
		else{
			return 0;
		}
	}
}
int swap(int *p1,int *p2){//将换两个指针元素 
	int tmp;
	tmp=*p1;*p1=*p2;*p2=tmp;
}
