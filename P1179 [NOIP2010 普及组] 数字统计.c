#include<stdio.h>
int main(){
	int len(int n);
	int bit(int n,int i);
	int L,R;
	scanf("%d %d",&L,&R);
	int num=0;
	int i,j;//����ѭ��
	int C_len; 
	for(i=L;i<=R;i++){
		C_len=len(i);
		for(j=1;j<=C_len;j++){
			if(2==bit(i,j)){
				num++;
			}
		}
	}
	printf("%d",num);
	return 0;
}
int len(int n){//��������λ�� 
	int i=0;
	do{
		i++;
		n/=10;
	}while(n); 
	return i;
}
int bit(int n,int i){//���������ĵ�iλ 
	int j;
	for(j=1;j<i;j++){
		n/=10;
	} 
	return n%10;
}
