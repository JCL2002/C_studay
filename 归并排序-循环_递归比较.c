#include<stdio.h>
//�鲢����_ѭ��ʵ�� 
int list_dg[20000000];//���������顪�ݹ� 
int list[20000000];//���������� 
int cache[20000000];//�������� 
void Merge (int *s, int *t, int l, int mid, int r){
	int i = l, j = mid + 1, c = l;
	while (i != mid + 1 && j != r + 1){
		if (s[i] < s[j])
			t[c++] = s[i++];
		else
			t[c++] = s[j++];
	}//�Ƚ϶���Ԫ��
	while (i != mid + 1)
		t[c++] = s[i++];
	while (j != r + 1)
		t[c++] = s[j++];//����ʣ��Ԫ��
		int k;
	for ( k = l; k <= r; ++k)
		s[k] = t[k];//����ԭ����
}//��

void M_sort (int *s, int *t, int l, int r){
	if (l < r){
		int mid = (l + r) >> 1;
		M_sort(s, t, l, mid);
		M_sort(s, t, mid + 1, r);
		Merge(s, t, l, mid, r);
	}
}//��
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
	int n=20000000;int i;int step,n_copy=n,tmp;
	int ti_o,ti_m;//��ʱ
	srand(time(NULL));
	for(i=0;i<20000000;i++){
		tmp=rand();
		list[i]=tmp;
		list_dg[i]=tmp;
	} 
	ti_o=time(NULL);
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
	ti_m=time(NULL);
	M_sort(list_dg,cache,0,20000000-1);
	printf("ѭ����ʱ��%d��\n�ݹ���ʱ��%d��\n",ti_m-ti_o,time(NULL)-ti_m);
	for(i=0;i<20000000;i++){
		if(list[i]!=list_dg[i]){
			printf("������������ͬ");
			return 1;
		}
	}
	printf("�����,������������ͬ");
	return 0;
}
