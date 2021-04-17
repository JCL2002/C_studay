#include<stdio.h>
int main(){
	int n;//用电度数
	float charge;//收费数目
	scanf("%d",&n);
	if (n<=150){
		charge=n*0.4463;
	} 
	else if(n<=400){
		charge=150*0.4463+(n-150)*0.4663;
	}
	else{
		charge=150*0.4463+250*0.4663+(n-400)*0.5663;
	}
	printf("%.1f",charge);
	return 0;
}
