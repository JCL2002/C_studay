#include<stdio.h>
int main(){
	int a[9];
	char identify;
	int out;
	scanf("%1d-%1d%1d%1d-%1d%1d%1d%1d%1d-%c",a,a+1,a+2,a+3,a+4,a+5,a+6,a+7,a+8,&identify);
	out=(a[0]+2*a[1]+3*a[2]+4*a[3]+5*a[4]+6*a[5]+7*a[6]+8*a[7]+9*a[8]);
	out=out%11;
	char Out;
	if(out<10){
		Out='0'+out;
	}
	else{
		Out='X';
	}
	if(Out==identify){
		printf("Right");
	}
	else{
		printf("%d-%d%d%d-%d%d%d%d%d-%c\n",a[0],a[1],a[2],a[3],a[4],a[5],a[6],a[7],a[8],Out);
	}
	return 0;
}
