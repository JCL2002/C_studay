#include<stdio.h>
double matrixAvg(int m,int n,double (*p)[n]){
	double sum=0.0;int i,j;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			sum+=*(*(p+i)+j);
		}
	}
	return sum/(n*m);
}
int main(){
	int M,N;
	scanf("%d%d",&M,&N);
	double aver,a[M][N];
	int i,j;
	for(i=0;i<M;i++)
		for(j=0;j<N;j++)
			scanf("%lf",&a[i][j]);
        aver=matrixAvg(M,N,a);
	printf("%.2f\n",aver);
	return 0;
}
