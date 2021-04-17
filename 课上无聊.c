#include<stdio.h>
int main(){
	int a[256][256];
	int (*p_a)[256]=a;
	int n,m;
	scanf("%d %d",&n,&m);
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			scanf("%d",(*(p_a+i)+j));
		}
	}
	show(n,m,p_a);
	return 0;
}
int show(int n,int m,int *(h_p)[256]){
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			printf("%d ",*(*(h_p+i)+j));
		}
		printf("\n");
	}
}
