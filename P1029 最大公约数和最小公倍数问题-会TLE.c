#include<stdio.h>
int main(){
	int min(int n,int m);
	int max_yue(int x,int y);
	int min_bei(int x,int y);
	int x0,y0,i,j,k;//����x0��y0��i��j����ѭ��
	int count=0;//��������ĸ��� 
	scanf("%d %d",&x0,&y0);
	for(i=x0;i<=y0;i++){
		if(y0/i){
			for(j=x0;j<=y0;j++){
				if(y0/j){
					if((max_yue(i,j)==x0)&&(min_bei(i,j)==y0)){
						count++;
					}
				}
			}
			
		}
	}
	printf("%d",count);
	return 0;
}
int min(int n,int m){
	if(n>m){
		return m;
	}
	else{
		return n;
	}
}
int max_yue(int x,int y){//�������������Լ�� 
	int i;
	for(i=min(x,y);i>0;i--){
		if(x%i==0&&y%i==0){
			return i;
		}
	}
}
int min_bei(int x,int y){//������������С������ 
	return x*y/max_yue(x,y);
}
//��һ�������㷨������TLE 
