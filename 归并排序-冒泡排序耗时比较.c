#include<stdio.h>
//�鲢����-ð������ʱ��Ƚ� 
int list[1000000];//���������� 
int cache[1000000];//�������� 
int list_mp[1000000];;//ð�ݵ����� 
void conquer(int head,int mid,int end){//�� 
	int p1,p2,p3;//p1ָ���һ�Σ�p2ָ��ڶ��Σ�p3ָ��cache
	p1=head;p2=mid;p3=head;
	while(1){//��cache�ж� 
		if(p1<mid){//p1û�дﵽĩβ 
			if(p2<end){//p2Ҳû�дﵽĩβ 
				if(list[p1]>list[p2]){
					cache[p3]=list[p2];//�ѱȽ�С�Ķ��뻺��cache
					p3++;p2++;//��ָ�롱���� 
				}
				else{
					cache[p3]=list[p1];//�ѱȽ�С�Ķ��뻺��cache
					p3++;p1++;//��ָ�롱����
				}
			}
			else{//p1û�н���������p2���� 
				cache[p3]=list[p1];
				p3++;p1++;
			}
		}
		else{//p1���� 
			if(p2<end){//p1��������p2û�н��� 
				cache[p3]=list[p2];
				p3++;p2++;
				
			}
			else{//p1��p2������ 
				break;//����ѭ�� 
			}
		}
	}
	//���ݻض�
	for(p1=head;p1<end;head++){
		list[p1]=cache[p1];p1++;
	} 
} 
int main(){
	int i,n,j,swap;
	printf("������������:");
	scanf("%d",&n); 
	for(i=0;i<n;i++){
		list[i]=rand();
	}
	int ti_o=time(NULL);
	int step,n_copy=n;
	for(i=1;n_copy;n_copy/=2,i*=2){//�� 
		step=0;
		while(1){
			if(step+2*i>n){//�жϵ�ǰһ���ܲ��ܺ���һ��ȴ�ϲ� 
				if(step+i<n){//�����ж�ʣ�µ��ǲ���һ��������һ��ʣ�ࣨһ���飩 
					conquer(step,step+i,n);
					break;
				}
				break;
			}
			else{
				conquer(step,step+i,step+2*i);
				step+=2*i;
			}
		}
		
	}
//	for(i=0;i<n;i++){
//		printf("%d ",list[i]);
//	}
	int ti_gui=time(NULL);//�鲢��ʱ��
	//ð������ 
	for(i=0;i<n;i++){
		for(j=0;j<n-i-1;j++){
			if(list_mp[j]>list_mp[j+1]){
				swap=list_mp[j+1];
				list_mp[j+1]=list_mp[j];
				list_mp[j]=swap;
			}
		}
	}
	int ti_mp=time(NULL);
	printf("�鲢��ʱ��%d��\nð�ݺ�ʱ��%d��",ti_gui-ti_o,ti_mp-ti_gui);
	return 0;
}
