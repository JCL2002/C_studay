#include<stdio.h>
int main(){
	int a[10];int *p=a;
	int i;
	for(i=0;i<10;i++){//���벿�� 
		scanf("%d",&a[i]);
	}
	for(i=0;i<10;i++){
		printf("%d ",*(p+i));
	}
	return 0;
}
