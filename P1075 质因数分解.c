#include<stdio.h>
#include<math.h>
int main(){
	int ifz(int n);//�����ж������ĺ��� 
	int a,i;//aΪ�����ֵ��i����ѭ�� 
	scanf("%d",&a);
	for(i=2;i<a;i++){
		if(a%i==0){
			printf("%d",a/i);
			break;
		}
	}
	return 0; 
}
