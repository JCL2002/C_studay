#include<stdio.h>

int main(){
	float total,in,time;
	printf("�����뱾��ʹ������:");
	scanf("%f %f",&in,&time);
	if(time<1){
		total=in+0.0275*in;
	}
	else{//ֻ�е�time����1ʱ�Ž����жϣ���Ȼ������������ƥ�䣬��ƥ�䵽default��
		int time_int=(int)time;//ǿ������ת��
		switch (time_int){
			case 1:{
				total=(1+0.0275)*in;
				break;
			}//������Ų��ܶ�
			case 2:{
				total=(1+0.0335)*in;
				break;
			}
			case 3:{
				total=(1+0.04)*in;
				break;
			}
			case 4:{//�ܲ��ܲ����˼Ҵ��
				total=(1+0.04)*in;
				break;
			}
			case 5:{
				total=(1+0.0475)*in;
				break;
			}
			default:{
				printf("���޴���");
				return 0;//ֱ�ӽ�������
				break;
			}
		}
	}
	printf("%f",total);
	return 0;
}