#include<stdio.h>
int main(){
	int swap(int *p1,int *p2);//����swap���� 
	int lenget(int n);//����lenget����
	int E(int x);//����E����
	int swap(int *p1,int *p2);//����swap���� 
	int cmp(int p1,int l1,int p2,int l2);//����cmp���� 
	int list[20];
	int n,i,j;//n���������i��j����ѭ�� 
	int *p_list=list;//��ϰָ���ʹ�� 
	scanf("%d",&n); 
	for(i=0;i<n;i++){//����¼�� 
		scanf("%d",p_list+i);
	}
	//������list����ð������,�����ǰ��մ�С���򣬶��ǰ��ղ�ͬ˳�����ܲ�����Ȩ�������� 
	int max=list[0];
	for(i=1;i<n;i++){
		for(j=0;j<n-i;j++){
			if(cmp(*(p_list+j),lenget(*(p_list+j)),*(p_list+j+1),lenget(*(p_list+j+1)))){//�Ӵ�С���� 
				swap(p_list+j,p_list+j+1);
			}
		//	printf("������ָ���ַ��%d\n",p_list);
		}
	}
	//�����������list
	for(i=0;i<n;i++){
		printf("%d",*(p_list+i));
	} 
	return 0;
}
int lenget(int n){//��ȡ��������͵ĳ��Ȳ��������� 
	int i=1;int j=10;
	for(;n/j;i++){
		j*=10;
	}
	return i;
}
int E(int x){//����10^x 
	int res=1;int i;
	for(i=0;i<x;i++){
		res*=10;
	}
	return res;
}
int cmp(int p1,int l1,int p2,int l2){//l1��l2�ֱ����p1��p2�ĳ��� 
	if (p1==p2){
		return 0;
	} 
	else{//����p1p2��p2p1���Ƚ����ǵĴ�С�����²�����������ѧ�� 
		if(p1*E(l2)+p2<p2*E(l1)+p1){//С��ʱ��Ҫ���� 
			return 1;
		}
		else{
			return 0;
		}
	}
}
int swap(int *p1,int *p2){//��������ָ��Ԫ�� 
	int tmp;
	tmp=*p1;*p1=*p2;*p2=tmp;
}
