#include<stdio.h>
int main(){
	int sum,i,j,n,a[1001]={1,1,2};
	scanf("%d",&n);
	if(n<2){
		printf("1");
	}
	else{
		for(i=2;i<=n;i++){//a[3]是第四个元素，所以从3开始递推 
			sum=1;
			for(j=1;j<=(i/2);j++){
				sum+=a[j];
			}
			a[i]=sum;
		}
		printf("%d",a[n]);
	}
	return 0;
}
