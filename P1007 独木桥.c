#include<stdio.h>
int Min(int x,int y){
	if(x>y) return y;
	else return x;
}
int Max(int x,int y){
	if(x>y) return x;
	else return y;
}
int main(){
	int L,N,location[5000],i;
	//���벿�� 
	scanf("%d\n%d",&L,&N);
	for(i=0;i<N;i++){
		scanf("%d",&location[i]);
	}
	//����Сֵ������ʿ�����������Լ�����ķ���ȥ
	int min;
	min=Min(location[0],L-location[0]+1);
	for(i=1;i<N;i++){
		min=Max(min,Min(location[i],L-location[i]+1));
	}
	//�����ֵ��ʿ��ײ��󽻻����򣬿��Կ��ɱ˴˴����Է�������ǰ�ߣ������������
	//����Сֵ��ͬ��ֻ������ʼ����ı�
	int max;
	max=Max(location[0],L-location[0]+1);
	for(i=1;i<N;i++){
		max=Max(max,Max(location[i],L-location[i]+1));
	}
	printf("%d %d",min,max);
	return 0;
}
