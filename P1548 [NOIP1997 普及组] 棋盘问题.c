#include<stdio.h>
#include<math.h>
int min(int a,int b){
	if(a>b) return b;
	else{
		return a;
	}
}
int main(){
	int N,M;
	scanf("%d %d",&N,&M);
	long long square=0,non=0;//�����κͳ����ε����� 
	int wide,high;//���Ϳ�
	int i,j;//����ѭ�� 
	for(wide=1;wide<=M;wide++){
		if(wide<=min(N,M)){//������û�г���ʱ 
			square+=(long long)(N-wide+1)*(M-wide+1);
		}
		for(high=1;high<=N;high++){
			if(high!=wide){
				non+=(long long)(N-high+1)*(M-wide+1);
			}
		}
	}
	printf("%lld %lld",square,non);
	return 0;
}
