#include<stdio.h>
int fb(int x){//쳲���������,����x�����ص�x���ֵ 
	int a=1,b=1,i;
	for(i=1;i<((x+1)/2);i++){
		a+=b;
		b+=a;
	}
	if(x%2){
		return a; 
	}
	else{
		return b;
	}
} 
long long sum(int start,int end){ 
	long long Sum=0;
	int i;
	for(i=start;i<=end;i++){
		Sum+=fb(i);
	}
	return Sum;
} 
int main(){
	int a,n_2,n,m,x;//a����ʼ��վ�ϳ�������n_2����ڶ�վ�ϳ�������n����վ������m�����յ�վ�³�������x������Ҫ��ĳ�վ��
	long long UP_a=0,UP_n_2=0,DOWN_a=0,DOWN_n_2=0; 
	scanf("%d %d %d %d",&a,&n,&m,&x);
	//���һ���³����������ܵ��ϳ�����֮�ͼ�ȥ�ܵ��³�����֮�� 
	//��ʼֵaȷ�����ڶ�վ�ϳ�����������Ҫ��δ֪�������ܷ���һ��쳲��������ֿ��������ѭ���Ե�쳲��������� 
	if(n<4){//������С����ʱ���һĿ��Ȼ�Ҳ����� 
		//�ϳ���a,n_2,fb(1)*a+fb(2)*n_2
		//�³�(���費Ϊ���һվ)��0,n_2,n_2
		switch (n){
			case 1:{
				printf("0");
				break;
			}
			case 2:{
				n_2=0;
				printf("%d",a);
				break;
			}
			case 3:{
				printf("%d",a); 
				break;
			}
		}
	}
	else{
		//�ϳ���2(a+n_2)+��
		//�³���2*n_2+��
		//���ϳ�a���
		//���ϳ�n_2���
		//���³�a���
		//���³�n_2���
		UP_a+=2;
		UP_n_2+=2;
		DOWN_n_2+=2;
		if(n!=4){//�³����ı��ϳ��� 
			DOWN_n_2+=sum(2,n-3);
			DOWN_a+=sum(1,n-4);
			UP_a+=sum(2,n-3);
			UP_n_2+=sum(3,n-2);
		}
	}
	//a*UP_a+n_2*UP_n_2-a*DOWN_a-n_2*DOWN_n_2=m
	//��n_2=(m-a(UP_a-DOWN_a))/(UP_n_2-DOWN_n_2)
	n_2=(m-a*(UP_a-DOWN_a))/(UP_n_2-DOWN_n_2);//�õ��ڶ����ϳ�����
	//ֱ�����x���ϳ�����
	if(x<4){
		printf("%d",a);
	}
	else{
		long long UP=0,DOWN=0;//UP�����ϳ������ܺͣ�DOWN�����³������ܺ�
		//��a��n_2�����´������� 
		UP_a=0;UP_n_2=0;DOWN_a=0;DOWN_n_2=0;
		UP_a+=2;
		UP_n_2+=2;
		DOWN_n_2+=2;
		DOWN_n_2+=sum(2,x-2);
		DOWN_a+=sum(1,x-3);
		UP_a+=sum(2,x-2);
		UP_n_2+=sum(3,x-1);
		//����UP��DOWN
		UP=a*UP_a+n_2*UP_n_2;
		DOWN=a*DOWN_a+n_2*DOWN_n_2;
		printf("%lld",UP-DOWN); 
		}
		
	return 0;
} 
