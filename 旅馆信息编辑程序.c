#include<stdio.h>
#define L_t sizeof(struct traveler)
#define L_h sizeof(struct hotel)
struct traveler{//�ÿ���Ϣ�ṹ�� 
	long long ID;
	char name[21];
}; 
struct hotel{//�ùݷ�����Ϣ�ṹ�� 
	int number;//�������
	int room_volume;//��������
	int room_state;//����״̬���Ѿ�ס�˼�����
	struct  traveler people[3];//������ס���� 
};
int main(){
	printf("�ڶ������û��Ҫ����ùݺ��ÿ͵����ݽ��б༭");getchar();
	printf("��ô�������ݾ����ڳ�������֮���͸�������");getchar();
	printf("�ܲ��ܡ������ˡ������ݶ���һ���İɣ��㶮��");getchar();
	printf("�������ֻ�������༭��ʼ���ݵģ�û�ж��������ݵ���ȷ�����м��\n");
	printf("��ϸ���룬������һ�����ͳ�BUG");getchar(); 
	int t_n,h_n;//�����������ÿ�����
	printf("�����뷿��������������15,������50����\n");
	scanf("%d",&h_n);
	printf("�������ÿ�������������100����\n");
	scanf("%d",&t_n);
	int i;
	struct hotel hot[256];
	struct traveler peo[512]; 
	for(i=0;i<h_n;i++){
		printf("---¼���%d���������Ϣ---\n",i+1);
		printf("�����ţ�%d(���Զ�����)\n",1000+i);
		hot[i].number=1000+i;
		printf("�����뵱ǰ����������1-3����\n");scanf("%d",&(hot[i].room_volume));getchar();
		hot[i].room_state=0;//Ĭ��û��ס 
		printf("----------------------------------\n"); 
	}
	for(i=0;i<t_n;i++){
		printf("---��%d���ÿ���Ϣ¼��:---\n",i+1);
		printf("�������ÿ�����(����̫��)��");gets(peo[i].name);
		printf("�������ÿ�ID:");scanf("%lld",&(peo[i].ID));getchar();
		printf("----------------------------------\n");
	} 
	FILE *file;
	/*
	�ļ���ʽ��
	�ļ���ǰ4�ֽڴ����ùݷ����������Ϊ��������ֱ�Ӵ��ڴ���תת��
	�ļ���5-8�ֽڴ����ÿ͵���������Ϊת��
	�ļ��������Ĳ��־ͷֱ����ùݽṹ���ת�����ÿͽṹ���ת������С��1-8�ֽ����ݶ��� 
	*/ 
	//h_n���ùݵ�������t_n���ÿ͵�����
	char choose;
	printf("1 �Զ��������ļ���\n2 ���ʹ��ͬһ���ļ���\n");
	choose=getchar();getchar();
	switch(choose){
		case '1':{
			char filename[513];
			printf("�������ļ�����\n");
			gets(filename);
			file=fopen(filename,"wb");
			fwrite(&h_n,4,1,file);
			fwrite(&t_n,4,1,file);
			fwrite(hot,L_h,h_n,file);
			fwrite(peo,L_t,t_n,file);
			fclose(file);
			break;
		}
		case '2':{
			char filename[10]={"database"};
			file=fopen(filename,"wb");
			fwrite(&h_n,4,1,file);
			fwrite(&t_n,4,1,file);
			fwrite(hot,L_h,h_n,file);
			fwrite(peo,L_t,t_n,file);
			fclose(file);
			break;
		}
	} 
	return 0;
}
