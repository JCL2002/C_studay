#include<stdio.h>
#include<stdlib.h> 
#include<string.h> 
#define T_l sizeof(struct traveler)//�ÿ����ṹ��Ĵ�С 
#define H_l sizeof(struct hotel)//�ùݽṹ���С 
struct traveler{//�ÿ���Ϣ�ṹ�� 
	long long ID;
	char name[21];
}; 
struct hotel{//�ùݷ�����Ϣ�ṹ�� 
	int number;//�������
	int room_volume;//��������
	int room_state;//����״̬���Ѿ�ס�˼�����
	struct  traveler people[3];//������ס����,��󷿼����������������� 
};
int main(){
	//��������
	void hotel_show(struct hotel *h,int n);//������Ϣչʾ 
	void hotel_search(struct hotel *h,int n,int hid);//������Ϣ���� 
	void traveler_show(struct traveler *t,int tn,struct hotel *h,int hn);//�ÿ���Ϣչʾ 
	void traveler_search(struct traveler *t,int tn,int id,struct hotel *h,int hn);//�ÿ���Ϣ���� 
	void traveler_search_name(struct traveler *t,int tn,char n[15],struct hotel *h,int hn);//�ÿ���Ϣ���ҡ��������� 
	int In(struct hotel *h,int hn,struct traveler *t,int tn,int num,int id);//�ÿ���ס 
	void Change(struct hotel *h,int hn,struct traveler *t,int tn,int num,int id);//���� 
	void Out(struct hotel *h,int hn,int id);//�˷� 
	
	//����������� 
	FILE *file;
	file=fopen("database","rb");//����ڱ༭�����Զ������ļ����������Ҫ�޸�
	int tn,hn;//tl���ÿ͵�������hl���ùݷ������� 
	int i;//i����ѭ�� 
	fread(&hn,4,1,file);//��ȡ�ù����� 
	fread(&tn,4,1,file);//��ȡ�ÿ����� 
	struct traveler t[512];//Ӧ��û���ĸ���̬�����ô�� 
	struct hotel h[256];//Ӧ��û���ĸ���̬�����ô��
	//���ݶ���
	for(i=0;i<hn;i++){//�ù���Ϣ���� 
		fread(&h[i],H_l,1,file);
	}
	for(i=0;i<tn;i++){//�ÿ���Ϣ���� 
		fread(&t[i],T_l,1,file);
	}
	fclose(file);
	//���ݶ����ڴ���� 
	char choose;//�û�ѡ���ģʽ
	while(1){//���û�һֱ����������ѡ�� 
		printf("-----------------------------------\n");
		printf("1 �鿴�õ���Ϣ\n2 �鿴ĳһ�������Ϣ\n3 �����ÿ���Ϣ\n4 ����ĳһ�ÿ���Ϣ\n5 �ÿ���ס\n6 �ÿͻ���\n7 �ÿ��˷�\n8 �˳�\n");
		choose=getchar();getchar();
		switch(choose){
			case '1':{//�鿴�õ���Ϣ
				hotel_show(h,hn);
				break;
			}//����ͨ�� 
			case '2':{//�鿴ĳһ�������Ϣ
				int hid;
				printf("������Ҫ���ҵķ���ID��\n");
				scanf("%d",&hid);getchar();
				hotel_search(h,hn,hid);
				break;
			}//����ͨ�� 
			case '3':{//�����ÿ���Ϣ
				traveler_show(t,tn,h,hn); 
				break;
			}//����ͨ�� 
			case '4':{//��ĳһ�ÿ���Ϣ
				char choose;
				printf("���������ʲô����\n1 ID  2 ����:\n");
				choose=getchar();getchar();
				if(choose=='1'){//����ID���� 
					int id;
					printf("�������ÿ�ID��");
					scanf("%d",&id);getchar(); 
					traveler_search(t,tn,id,h,hn);
				}//����ͨ�� 
				else if(choose=='2'){//������������ 
					char n[21];
					printf("�������ÿ����֣�\n");
					gets(n);
					traveler_search_name(t,tn,n,h,hn);
				}//����ͨ�� 
				else {
					printf("��������\n");getchar(); 
				}
				break;
			}//����ͨ�� 
			case '5':{//�ÿ���ס
				int num,id;
				printf("������Ҫ��ס�ķ���ţ�\n");scanf("%d",&num);getchar();
				printf("������Ҫ��ס���˵�ID��\n");scanf("%d",&id);getchar();
				In(h,hn,t,tn,num,id);
				break;
			}//����ͨ�� 
			case '6':{//�ÿͻ���
				int num,id;
				printf("������Ҫ���ĵ��·���ţ�\n");scanf("%d",&num);getchar();
				printf("������Ҫ���ķ�����ÿ͵�id��\n");scanf("%d",&id);getchar();
				Change(h,hn,t,tn,num,id);
				break;
			}
			case '7':{//�ÿ��˷�
				int id;
				printf("������Ҫ�˷����˵�ID\n");
				scanf("%d",&id);getchar();
				Out(h,hn,id);
				break;
			}
			case '8':{//�˳�
				file=fopen("database","wb");//������д������Ƶ���ʽ���ļ� 
				fwrite(&hn,4,1,file);//����д���ù�����
				fwrite(&tn,4,1,file);//����д���ÿ����� 
				fwrite(h,H_l,hn,file);//����д���ùݽṹ�� 
				fwrite(t,T_l,tn,file);//��дд���ÿͽṹ�� 
				fclose(file);//�ر��ļ� 
				return 0;
				break;
			}
		} 
	
	} 
	return 0;
}
void hotel_show(struct hotel *h,int n){//�鿴�õ���Ϣ,���δ���ṹ�������ù�����
	int i;
	printf("------------������Ϣ---------------\n"); 
	for(i=0;i<n;i++){
		printf("������룺%d\n",h[i].number);
		printf("����������%d\n",h[i].room_volume);
		printf("������ס������%d\n",h[i].room_state);
		if(h[i].room_state>0){//������������ˣ���ѭ����������� 
			int j;
			printf("��Ա������");
			for(j=0;j<h[i].room_state;j++){
				printf("%s\t",h[i].people[j].name); 
			}
			printf("\n");
		}
		printf("*********\n");//���ڷָͬ�������Ϣ���������� 
		getchar(); 
	}
}
void hotel_search(struct hotel *h,int n,int hid){//����ĳһ�������Ϣ,���δ���ṹ��������������������� 
	int i;
	printf("------------������Ϣ����-----------\n");
	for(i=0;i<n;i++){
		if(h[i].number==hid){
			printf("������룺%d\n",h[i].number);
			printf("����������%d\n",h[i].room_volume);
			printf("������ס������%d\n",h[i].room_state);
			if(h[i].room_state>0){//������������ˣ���ѭ����������� 
				int j;
				printf("��Ա������");
				for(j=0;j<h[i].room_state;j++){
					printf("%s",h[i].people[j]); 
				}
				printf("\n");
			}
			getchar();
		}
	}
} 
void traveler_show(struct traveler *t,int tn,struct hotel *h,int hn){//�ÿ���Ϣչʾ�����������ÿͽṹ�������ÿ��������ùݽṹ�������ù����� 
	int i,j,k;int mark=1;
	printf("------------�ÿ���Ϣ---------------\n");
	for(i=0;i<tn;i++,mark=1){
		printf("�ÿ�������%s\n",t[i].name);
		printf("�ÿ�ID��%d\n",t[i].ID);
		for(j=0;j<hn;j++){//���ùݽṹ���б����������ÿ͵���ס��Ϣ 
			if(h[j].room_state){//����ù�����ס 
				for(k=0;k<h[j].room_state;k++){//����ס�����б������ң����Ƿ�������� 
					if(h[j].people[k].ID==t[i].ID){
						printf("��ס�ķ��䣺%d\n",h[j].number);
						mark=0;
					}
				}
			}
		}
		if(mark){
			printf("û����ס�ù�\n");
		}
		printf("*********\n");getchar();
	} 
}
void traveler_search(struct traveler *t,int tn,int id,struct hotel *h,int hn){//�ÿ���Ϣ���ң�����ID�������δ����ÿͽṹ�������ÿ�������Ҫ���ҵ��ÿ�ID���ùݽṹ�������ù����� 
	int i,j,k;int mark=1; 
	printf("------------�ÿ���Ϣ����-----------\n");
	for(i=0;i<tn;i++,mark=1){
		if(t[i].ID==id){//�ҵ�����˵Ĵ��� 
			printf("�ÿ�������%s\n",t[i].name);
			printf("�ÿ�ID��%d\n",t[i].ID);
			for(j=0;j<hn;j++){//���ùݽṹ���б����������ÿ͵���ס��Ϣ 
				if(h[j].room_state){//����ù�����ס 
					for(k=0;k<h[j].room_state;k++){//����ס�����б������ң����Ƿ�������� 
						if(h[j].people[k].ID==id){
							printf("��ס�ķ��䣺%d\n",h[j].number);
							mark=0;
						}
					}
				}
			}
			if(mark){
				printf("û����ס�ù�\n");
			}
			printf("*********\n");getchar();
		}
	}
}
void traveler_search_name(struct traveler *t,int tn,char n[15],struct hotel *h,int hn){//�ÿ���Ϣ���ң����������������δ����ÿͽṹ�������ÿ�������Ҫ���ҵ��ÿ͵������ַ��������ùݽṹ�������ù�����
	int i,j,k;int mark=1; 
	int charequal(char *p1,char *p2);//�����ַ����ȽϺ��� 
	printf("------------�ÿ���Ϣ����-----------\n");
	for(i=0;i<tn;i++){
		if(charequal(t[i].name,n)){//�ҵ�����˵Ĵ��� 
			printf("�ÿ�������%s\n",t[i].name);
			printf("�ÿ�ID��%d\n",t[i].ID);
			for(j=0;j<hn;j++){//���ùݽṹ���б����������ÿ͵���ס��Ϣ 
				if(h[j].room_state){//����ù�����ס 
					for(k=0;k<h[j].room_state;k++){//����ס�����б������ң����Ƿ�������� 
						if(h[j].people[k].ID==t[i].ID){
							printf("��ס�ķ��䣺%d\n",h[j].number);
							mark=0;
						}
					}
				}
			}
			if(mark){
				printf("û����ס�ù�\n");
			}
			printf("*********\n");getchar();
		}
	}
}
int charequal(char *p1,char *p2){//�ж������ַ����Ƿ���ȣ���ȷ���1�����ȷ���0 
	int l1,l2;
	l1=strlen(p1);l2=strlen(p2);
	if(l1==l2){
		int i;
		for(i=0;i<l1;i++){
			if(*(p1+i)!=*(p2+i)){
				return 0;
			}
		}
		return 1;//Ը������ǧ���������������� 
	}
	else{
		return 0;
	}
}
int In(struct hotel *h,int hn,struct traveler *t,int tn,int num,int id){//��Ա��ס�����������ùݽṹ���������������ÿͽṹ�������ÿ�������Ҫ��ס�ڼ������䡢Ҫ��ס���ÿ�ID 
	int i,j;int goon;//������ǹ����Ƿ�Ҫ�������� 
	int tid;//����Ҫ��ס���˵��±� 
	printf("------------�ÿ���ס---------------\n");
	//����Ƿ�����������
	if((num<1000)||(num-999>hn)){
		printf("���䲻����");getchar();
		goon=0;
	} 
	//����Ƿ�������� 
	if(goon){
		for(i=0;i<tn;i++){
			if(t[i].ID==id){
				tid=i;
				break;
			}
		}
		if(i==tn){
			goon=0;
		}
	}
	//���������Ƿ��Ѿ���ס
	if(goon){
		for(i=0;i<hn;i++){
			if(h[i].room_state){//�����������ס������ס�������������ǲ�������� 
				for(j=0;j<h[i].room_state;j++){
					if(h[i].people[j].ID==id){
						printf("%s�Ѿ���ס��%d\n",t[tid].name,h[i].number);getchar();
						goon=0;
					}
				}
			} 
		}
	} 
	//���Ҫ����ķ����Ƿ�ס��
	if(goon){
		if(h[num-1000].room_state==h[num-1000].room_volume){
			printf("����������");getchar();
			goon=0;
		}
	} 
	//��ʽ��ס
	if(goon){
		h[num-1000].room_state++;
		h[num-1000].people[h[num-1000].room_state-1]=t[tid];
	} 
	if(goon){
		return 1;
	}
	else {
		return 0;
	}
}
void Out(struct hotel *h,int hn,int id){//�˷������δ����ùݽṹ����������������Ҫ�˷����˵�ID 
	int i,j;//����ѭ�� 
	for(i=0;i<hn;i++){
		if(h[i].room_state){//���������� 
			for(j=0;j<h[i].room_state;j++){//����ÿ���� 
				 if(h[i].people[j].ID==id){//�ҵ�Ҫ�˷�����,��ʱiΪ�ùݽṹ��������±ꡢjΪ�ÿͽṹ��������±� 
				 	h[i].room_state--;
				 	printf("�Ѿ��˷�");getchar();
				 	return;
				 }
			}
		}
	}
	printf("�˷�ʧ�ܣ�����ԭ��:\n1.�ÿ�ID����\n2.�ÿ���δ��ס");getchar();
}
void Change(struct hotel *h,int hn,struct traveler *t,int tn,int num,int id){
	void Out(struct hotel *h,int hn,int id);//�����˷����� 
	int In(struct hotel *h,int hn,struct traveler *t,int tn,int num,int id);//������ס���� 
	int mark_out=0,mark_in=0;//��������˷�����ס�Ƿ�ɹ� 
	//�ȱ����˷���Ϣ
	int o_number;//����ԭס��number 
	int i,j;//����ѭ�� 
	for(i=0;i<hn;i++){
		if(h[i].room_state){//���������� 
			for(j=0;j<h[i].room_state;j++){//����ÿ���� 
				 if(h[i].people[j].ID==id){//�ҵ�Ҫ�˷�����,��ʱiΪ�ùݽṹ��������±ꡢjΪ�ÿͽṹ��������±� 
				 	o_number=h[i].number;
				 	mark_out=1;//���ҵ���һ�����˷� 
				 }
			}
		}
	}
	//�˷�
	if(mark_out)Out(h,hn,id);
	//��ס�·�
	if(mark_out)mark_in=In(h,hn,t,tn,num,id);
	//�ж��Ƿ���Ҫ��ԭ 
	if(mark_in){//�ɹ���ס 
		printf("�����ɹ�\n");getchar(); 
	}
	else{//�������ɹ�����ԭԭ��״̬ 
		if(mark_out){
			In(h,hn,t,tn,num,id);
		}
		else{
			printf("���ÿͻ�δ��ס");getchar();
		}
		 
	}
}
