#include<stdio.h>
#define max 500000
int A[100][100];
int path[100][100];
void init(){//��ʼ������ 
	int i,j;
	for(i=0;i<100;i++){
		for(j=0;j<100;j++){
			if(i==j){
				A[i][j]=0;//���Խ���Ϊ0 
			}
			else{
				A[i][j]=max;
			}
			path[i][j]=-1;
		}
	}
}
void Find(int i,int j){//·����Դ 
	if(path[i][j]==-1){
		if(A[i][j]==max){
			printf("��·��ͨ");
		}
		else{
			printf("%d->%d",i,j);
		}
	}
	else{
		int k;//�м̵�
		k=path[i][j];
		Find(i,k);
		printf("\b");
		Find(k,j); 
	}
	
}
int V;//V����������
int main(){//Floyd�㷨 
	init();//��ʼ��
	printf("�����붥��������");scanf("%d",&V);
	if(V>100){//���뷶Χ�������� 
		printf("����̫��");
		return 1;
	}
	else if(V<=0){
		printf("�Ǹ�����");
		return 1;
	}//������
	int i,j,k;//iΪʼ�ߣ�jΪ�ձߣ�kΪפ��
	int cycle;//����ѭ��
	printf("�������룺�߳�����㣬�յ㣬�߳�Ϊ0ʱ����\n");
	int inp;
	while(1){
		scanf("%d %d %d",&inp,&i,&j);
		if(inp==0){
			break;
		}
		if(i>99||j>99){
			printf("����̫��");
			return 1;
		}
		A[i][j]=inp;//������д�����㣬�д����յ� 
	}//����¼��
	for(k=0;k<V;k++){//�ƶ�פ�� 
		for(i=0;i<V;i++){
			if(A[i][k]!=0&&A[i][k]!=max){//��i���Ե���k�Ҳ���k�㱾�� 
				/*
				פ��k�����������õ�ǰ���Ǵ�i���ܹ�����k�� 
				*/
				for(j=0;j<V;j++){
					if(A[k][j]!=0&&A[k][j]!=max){//��k���Ե���j�Ҳ���k���� 
						if(A[i][k]+A[k][j]<A[i][j]){//״̬ת�Ʒ��� 
							A[i][j]=A[i][k]+A[k][j];//���¾�����Ϣ 
							path[i][j]=k;//��¼·�� 
						}
					}
				}
			}
		}
	}
	printf("·���滮���\n");
	printf("�������ѯ·��\n");
	scanf("%d %d",&i,&j);
	printf("·������%d\n",A[i][j]);
	Find(i,j);
	return 0;
}
