#include<stdio.h>
int main(){
	long long n,m;double total;
	scanf("%lld %lld",&n,&m);//�������� 
	//n->��
	//m->��ʿ
	total=n+(1.0*m/100);//�����ܼ�ֵ 
	if(total==9.15){
		printf("C");
	}
	else if(total>9.15){
		printf("D");
	}
	else if(total<9.15){
		printf("AB");
	}
	return 0;
}
