#include<stdio.h>
int main(){
	int m;//m�������������
	int a[100];//����a������������
	int i,j;//i,j����ѭ�� 
	scanf("%d",&m);
	for(i=0;i<m;i++){//�����¼�벿�� 
		scanf("%d",&a[i]);
	} 
	int b[100],b_len=0;//����һ���µ��������ڴ��ɸ��֮������飬b_len�����������ĳ���
	int count;//count����ͳ��a[i]��b�г��ֵĴ��� 
	for(i=0;i<m;i++){//����a���� 
		count=0;
		for(j=0;j<=b_len;j++){//ͳ��a[i]��b�г��ֵĴ���
			if(a[i]==b[j]){
				count++;
			}
		}
		if(!count){
			b[b_len]=a[i];
			b_len++;
		}
		
	}
	//������b����ð������
	int tmp;//���ڽ�������ʱ���� 
	for(i=0;i<b_len-1;i++){//b_len�ĳ���Ϊb��ʵ�ʳ���
		for(j=0;j<b_len-i-1;j++){
			if(b[j]>b[j+1]){//���մ�С�����˳������ 
				tmp=b[j];b[j]=b[j+1];b[j+1]=tmp;
			}
		}
	} 
	printf("%d\n",b_len);
	//�������b
	for(i=0;i<b_len-1;i++){//���������b�ĵ����ڶ���Ԫ�ؾ�ͣ�£���Ϊ���һ�����治��Ҫ�ӿո� 
		printf("%d ",b[i]);
	} 
	printf("%d",b[b_len-1]);
	return 0;
} 
