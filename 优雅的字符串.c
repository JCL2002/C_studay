#include<stdio.h>
#include<string.h>
int main(){
	char a[10001];//�����б���
	gets(a);//¼���ַ��� 
	int length,i,zheng=0,fu=0;
	length=strlen(a);//���ַ�������
	//�ֱ�ͳ�����򡢽���Ĵ���
	for(i=0;i<length-1;i++){
		if(a[i]<=a[i+1]){
			zheng++;//�������ͳ�� 
		}
		else if(a[i]>=a[i+1]){
			fu++;//�������ͳ��
		}
	}
	if(length-1==zheng){
			printf("Positive elegance");
		}
		else if(length-1==fu){
			printf("Negative elegance");
		}
		else{
			printf("Non elegance");
		}
	return 0; 
}
