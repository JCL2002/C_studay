#include<stdio.h>
char light[2000001];
int main(){
	double a;int t,a_i;//与题目对应
	int i,j,n,k;//用于循环
	for(k=0;k<2000001;k++){
		light[k]='0';
	}
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%lf %d",&a,&t);
		for(j=1;j<=t;j++){
			a_i=a*j;
			if(light[a_i]=='0'){
				light[a_i]='1';
			}
			else{
				light[a_i]='0';
			}
		}
	}
	for(k=1;k<=2000000;k++){
		if(light[k]=='1'){
			printf("%d",k);
		}
	}
	return 0;
}
