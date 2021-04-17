#include<stdio.h>
int main(){
	int sh[1000],kc[1000],SH=0,KC=0;
	int N,M,i,j=0;
	int a,b;
	for(i=0;i<1000;i++){
		sh[i]=0;kc[i]=0;
	}
	scanf("%d %d",&N,&M);
	for(i=0;i<N;i++){
		scanf("%d %d",&a,&b);
		for(j=0;j<b;j++){
			sh[SH]=a;
			SH++;
		}
	}
	for(i=0;i<M;i++){
		scanf("%d %d",&a,&b);
		for(j=0;j<b;j++){
			kc[KC]=a;
			KC++;
		}
	}
	int dis_sh=0,dis_kc=0;
	
	return 0;
}
