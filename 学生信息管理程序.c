#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define info_len sizeof(struct student_info)
#define score_len sizeof(struct sudent_score)
/*
info_len������student_info����ṹ��ĳ��ȣ�����malloc
score_len������score_info����ṹ��ĳ��ȡ��� 
*/
struct student_score{//ѧ�������ṹ�� 
	float C;//C���Գɼ�
	float H_math;//�����ɼ�
	float X_dai;//�ߴ��ɼ� 
	float Eng;//Ӣ��ɼ� 
};
struct student_info {//ѧ����Ϣ�ṹ�壬��Ƕ��ѧ������ 
	long long number;//ѧ�� 
	char name[15];//ѧ������
	char sex;//ѧ���Ա�M/F
	int age;//���� 
	struct student_score score;//����ѧ���ĳɼ����ݽṹ 
	struct student_info *next;//ָ����һ���ڵ��ָ�� 
};
struct student_info Kong={0,"init",'?',0,{},NULL,};//����һ���յ�ֵ�����ڴ������ļ�ʱ���ļ�������һ������ 
//�����ǽṹ��Ķ��� 
int main(){
	char interface();//���������溯�� 
	struct student_info *Read(FILE *file);//�����ļ���ȡ���� 
	void Write(FILE *file,struct student_info *head);//�����ļ�д�뺯�� 
	struct student_info *Form();//����ڵ����ɺ��� 
	void Del(struct student_info *head,long long num);//����ڵ�ɾ������ 
	void Find(struct student_info *head,long long num);//������Һ��� 
	void Change(struct student_info *head,long long num);//������Ľڵ�ĺ���
	void Borrow(struct student_info *head);//��������ĺ��� 
	void Borrow_score(struct student_info *head);//����ɼ�����ĺ��� 
	void  Find_score(struct student_info *head,long long num);//�������ѧ�Ų�ɼ��ĺ��� 
	void Change_score(struct student_info *head,long long num);//�������ѧ���޸ĳɼ��ĺ��� 
	struct student_info *Return(struct student_info *head,long long num);//�������ѧ�ŷ������ڽڵ�ָ��ĺ��� 
	long long Name(struct student_info *head,char *NAme);//����������ַ���ѧ�ŵĺ��� 
	int tst(char *p1,char *p2);//�����ж��ַ����Ƿ���ȵĺ��� 
	struct student_info *End(struct student_info *head);//�����������һ���ڵ��ָ�� 
	int student_number(struct student_info *head);//����ѧ������
	//�������� 
	struct student_info *head=NULL;//��ʼ��headָ��
	FILE *file=NULL;//�����ļ�ָ�� 
	char file_name[513];//���ڴ����ļ���
	char m_choice;//�����û����������ѡ�� 
	int mark;//�����ж��Ƿ���Ҫ����ѭ�� 
	int f_state=0;//�ļ��Ĵ�״̬��0������δ��״̬ 
	while(1){//ÿ�ζ��ص������棬ֱ���û��˳� 
		m_choice=interface();//������ʾ�����������ط���ֵ 
		FILE *file;//�����ļ�ָ�� 
		switch(m_choice){
			case '1':{//�û�ѡ����---������Ϣ���� --- 
				mark=1;
				char choice;//���ڱ����û���ѡ�� 
				while(mark){
					printf("---------��ѡ����---------\n1 ����\n2 ���\n3 ɾ��\n4 �޸�\n5 ���\n6 �˳���ǰģ��\n�����룺");
					choice=getchar();getchar();
					switch(choice){
						case '1':{//�û�ѡ����--����-- 
							char choose;
							if(f_state){
								printf("����Ҫ����ʲô���ң�1 ѧ�ţ�2 ����\n");
								choose=getchar();getchar(); 
								if(choose=='1'){
									long long nu;
									printf("������Ҫ���ҵ�ѧ����ѧ�ţ�");
									scanf("%lld",&nu);getchar();//�Իس�  
									Find(head,nu);//���ø��ĺ��� 
								}
								else if(choose=='2'){
									char n[15];
									printf("������Ҫ���ҵ�ѧ����������");
									gets(n);
									Find(head,Name(head,n));
								}
								else{
									printf("!!!��������!!!\n");
								}
							}
							else{
								printf("!!!û�д򿪵��ļ�!!!\n");
							}//����ͨ�� 
							break;
						}
						case '2':{//�û�ѡ����--���-- 
							char choose;
							if(f_state){
								printf("������Ҫ�����λ�ã�1 ĩβ 2 ָ��ѧ��֮�� 3 ָ������֮�� 4 ���ڵ�һλ\n");
								choose=getchar();getchar();
								if(choose=='1'){//�û�Ҫ��ĩβ������ 
									int count,i;//����ĸ���
									printf("������Ҫ����ĸ���:\n");
									scanf("%d",&count);getchar(); 
									for(i=0;i<count;i++){
										struct student_info *tmp;//����һ����ʱָ������ʢ���´����Ľڵ�ĵ�ַ��
										struct student_info *end;//������Ž�βԪ�ص�ָ�� 
										end=End(head);//���������ҳ���ǰĩβ�Ǹ�Ԫ�ص�ָ��
										tmp=Form();//ʹ��Form��������һ���ڵ�
										end->next=tmp;//����ʱ�ڵ���뵽������
										//Form�����γɵĽڵ��nextΪNULL����˲����ٴζ������� 
									} 
								}
								else if(choose=='2'){//�û�Ҫ��ָ����ѧ�ź�������� 
									printf("������ѧ�ţ��������ѧ�ź�����룺\n");
									long long nu;
									scanf("%lld",&nu);getchar();
									int count,i;
									printf("������Ҫ����ĸ���:\n");
									scanf("%d",&count);getchar();
									for(i=0;i<count;i++){
										struct student_info *tmp;//����һ����ʱָ������ʢ���´����Ľڵ�ĵ�ַ��
										struct student_info *target;//�������ָ��Ԫ�ص�ָ��
										target=Return(head,nu);//�ҵ�Ŀ��
										if(target==NULL){//���޴��˵���� 
											printf("!!!���޴���!!!\n");
											break;
										}
										tmp=Form();//���ɽڵ�
										tmp->next=target->next;//�������ɵĽڵ����һ��ָ��ԭ�������������е�λ��(��β)
										nu=tmp->number;//nuֵ���£�Ϊ��һ��ѭ����׼�� 
										target->next=tmp;//��ԭ�е�����Ŀ��ڵ����һ����ַָ�����γɵĽڵ㣨��ͷ�� 
									}
								}
								else if(choose=='3'){//�û�ѡ����ָ������֮���������
									printf("���������֣�����������ֺ�����룺\n");
									char n[15];
									gets(n);
									long long nu;
									nu=Name(head,n);//�������ֻ��ѧ��
									int count,i;
									printf("������Ҫ����ĸ���:\n");
									scanf("%d",&count);getchar(); 
									for(i=0;i<count;i++){
										struct student_info *tmp;//����һ����ʱָ������ʢ���´����Ľڵ�ĵ�ַ��
										struct student_info *target;//�������ָ��Ԫ�ص�ָ��
										target=Return(head,nu);//�ҵ�Ŀ��
										if(target==NULL){//���޴��˵���� 
											printf("!!!���޴���!!!\n");
											break;
										}
										tmp=Form();//���ɽڵ�
										tmp->next=target->next;//�������ɵĽڵ����һ��ָ��ԭ�������������е�λ��(��β)
										nu=tmp->number;//nuֵ���£�Ϊ��һ��ѭ����׼�� 
										target->next=tmp;//��ԭ�е�����Ŀ��ڵ����һ����ַָ�����γɵĽڵ㣨��ͷ�� 
									}
								}
								else if(choose=='4'){//�û�ѡ���˲��ڵ�һλ 
									struct student_info *tmp;
									tmp=Form();
									tmp->next=head;
									head=tmp;
								}//����ͨ�� 
								else{
									printf("!!!�������!!!\n");
								} 
							}
							else{
								printf("!!!û���Ѿ��򿪵��ļ�!!!\n");
							}
							break;
						}//����ͨ�� 
						case '3':{//�û�ѡ����--ɾ��-- 
							char choose;
							if(f_state){
								if(student_number(head)>1){//��ѧ��������1����ɾ�� 
									printf("1 ����ѧ��ɾ�� 2 ��������ɾ��\n");
									choose=getchar();getchar(); 
									if(choose=='1'){//�û�ѡ���˸���ѧ��ɾ�� 
										long long nu;
										printf("������Ҫɾ����ѧ����ѧ��:");
										scanf("%lld",&nu);getchar();
										struct student_info *p;
										p=Return(head,nu);//�ȷ���Ҫɾ���˵�λ�� 
										if(p==head){//���Ҫɾ�������ǵ�һ��Ԫ�� 
											head=head->next;//�ܿյ�һ��Ԫ�� 
										} 
										else{
											Del(head,nu);
										}
									}
									else if(choose=='2'){//�û�ѡ���˸�������ɾ�� 
										long long nu;
										struct student_info *p;
										printf("������Ҫɾ����ѧ��������:");
										char n[15];gets(n);
										nu=Name(head,n);
										p=Return(head,nu);
										if(p==head){//���Ҫɾ�������ǵ�һ��Ԫ�� 
											head=head->next;//�ܿյ�һ��Ԫ�� 
										} 
										else{
											Del(head,nu);
										}
									} 
									else{
										printf("!!!��������!!!\n");
									}
								}
								else{
									printf("ɾ������ֻ��һ��ѧ��");getchar();
								} 
								
							}
							else{
								printf("!!!û���Ѿ��򿪵��ļ�!!!\n");
							}
							break;
						}
						case '4':{//�û�ѡ����--�޸�-- 
							char choose;
							if(f_state){
								printf("����Ҫ����ʲô�޸ģ�1 ѧ�ţ�2 ����\n");
								choose=getchar();getchar(); 
								if(choose=='1'){
									long long nu;
									printf("������Ҫ���ĵ�ѧ����ѧ�ţ�");
									scanf("%lld",&nu);getchar();//�Իس�  
									Change(head,nu);//���ø��ĺ��� 
								}
								else if(choose=='2'){
									char n[15];
									printf("������Ҫ���ĵ�ѧ����������");
									gets(n);
									Change(head,Name(head,n));
								}
								else{
									printf("!!!��������!!!\n");
								}
							}
							else{
								printf("û���Ѿ��򿪵��ļ�\n");
							}
							break;
						}//����ͨ�� 
						case '5':{//�û�ѡ����--���-- 
							if(f_state){
								Borrow(head);
							}
							else{
								printf("!!!��û�д򿪵��ļ�!!!\n");
							}
							break;
						}//����ͨ�� 
						case '6':{//�û�ѡ����--�˳���ǰģ��
//							fclose(file);//�رմ򿪵��ļ� 
							mark=0;
							break;
						}//����ͨ�� 
						default:{//�������� 
							printf("��������!!!����\n");
						}
					} 
				} 
				break;
			}//����ͨ�� 
			case '2':{//�û�ѡ����---ѧ���ɼ���Ϣ����--- 
				mark=1;
				char choice;//���ڱ����û���ѡ�� 
				while(mark){
					printf("---------��ѡ����---------\n1 ����\n2 �޸�\n3 ���\n4 �˳���ǰģ��\n�����룺\n");
					choice=getchar();getchar();
					switch(choice){
						case '1':{//�û�ѡ����--����--
							char choose;
							printf("1 ����ѧ�Ų��� 2 ������������\n");
							choose=getchar();getchar();
							if(choose=='1'){
								long long nu;
								printf("������ѧ�ţ�\n");
								scanf("%lld",&nu);getchar();
								Find_score(head,nu);
							}
							else if(choose=='2'){
								char n[15];
								printf("������������\n");
								gets(n);
								Find_score(head,Name(head,n));
							}
							else{
								printf("!!!��������!!!\n"); 
							}
							break;
						}
						case '2':{//�û�ѡ����--�޸�--
							char choose;
							printf("1 ����ѧ���޸� 2 ���������޸�\n");
							choose=getchar();getchar();
							if(choose=='1'){
								long long nu;
								printf("������ѧ�ţ�\n");
								scanf("%lld",&nu);getchar();
								Change_score(head,nu);
							}
							else if(choose=='2'){
								char n[15];
								printf("������������\n");
								gets(n);
								Change_score(head,Name(head,n));
							}
							else{
								printf("!!!��������!!!\n");
							}
							break;
						}
						case '3':{//�û�ѡ����--���-- 
							Borrow_score(head);
							break;
						}
						case '4':{//�û�ѡ����--�˳���ǰģ��--
							mark=0;
							break;
						}
						default:{//��������
							printf("��������!!!����\n");
						}
					}
				}
				break;
			} 
			case '3':{//�û�ѡ����---�ļ�����--- 
				mark=1;
				char choice;//���ڱ����û���ѡ��
				while(mark){
					printf("---------��ѡ����---------\n1 �½�ѧ����Ϣ�ļ�\n2 ���ļ�\n3 ����ر��ļ�\n4 ������ر��ļ��������б��棩\n5 �˳���ģ��\n�����룺");
					choice=getchar();getchar();
					switch(choice){
						case '1':{//�û�ѡ����--�½��ļ�-- 
							int mark_1=1;//��һ��ѭ�����ж�����
							while(mark_1){
								if(f_state){
									printf("�д򿪵��ļ�û�йرգ����ȹر�����ļ�!");
									mark_1=0;
								} 
								else{
									printf("�������ļ���:"); 
									gets(file_name);
									if((file=fopen(file_name,"wb+"))==NULL){//�ļ��������ɹ� 
										printf("�ļ�����ʧ�ܣ������ļ�����Ȩ��\n");
									} 
									else{
										mark_1=0;//�ļ��Ѿ��򿪣�����Ҫ�ٴ�ѭ�� 
										Write(file,&Kong);//�����ļ���дһ����ʼ���Ŀ�ֵ������򲻿� 
										fclose(file);//�رձ����ļ� 
										file=fopen(file_name,"rb+");//�ٴδ��ļ������ϴβ�ͬ�������ֻ��
										head=Read(file);//���ļ������ݶ����ڴ��У��γ�������һ���ڵ��ָ�뷵�ظ�head
										f_state=1;//����ļ�Ϊ�Ѿ���״̬ 
										mark=0;//ֱ�Ӿ��������ģ�� 
								}
							} 
							}
							break;
						}//������ͨ�� 
						case '2':{//�û�ѡ����--���ļ� 
							if(!f_state){
								printf("�������ļ���:");
								gets(file_name);
								if((file=fopen(file_name,"rb+"))==NULL){//�ļ��������ɹ� 
									printf("�ļ���ʧ�ܣ������ļ�����Ȩ��");getchar();
								} 
								else{
									head=Read(file);//���ļ������ݶ����ڴ��У��γ�������һ���ڵ��ָ�뷵�ظ�head
									f_state=1;//����ļ�Ϊ�Ѿ���״̬ 
									mark=0;//ֱ�Ӿ��������ģ�� 
								}
							}
							else{
								printf("���д򿪵��ļ��ˣ����ȹر���");getchar(); 
							}
							break;
						}//����ͨ�� 
						case '3':{//�û�ѡ����--����ر��ļ� 
							if(f_state){//�ж��Ƿ��д��˵��ļ� 
								fclose(file);//�ر�ԭ���򿪵��ļ�
								file=fopen(file_name,"wb"); 
								Write(file,head);//���ڴ��е������浽�ļ���
								fclose(file);//�ر��ļ�
								f_state=0;//�ļ�״̬���Ϊ�ر� 
								mark=0;//ֱ�Ӿ��������ģ�� 
							}
							else{
								printf("û���Ѿ��򿪵��ļ�!\n");
							}
							break;
						}//����ͨ�� 
						case '4':{//�û�ѡ����--������ر��ļ� 
							if(f_state){
								fclose(file);
								f_state=0;
								mark=0;//ֱ�Ӿ��������ģ�� 
							}
							else{
								printf("û�д򿪵��ļ�");
							}
							break;
						}//����ͨ�� 
						case '5':{//�û�ѡ�����˳���ģ�� 
							mark=0;
							break;
						}
						default:{
							printf("��������!!!\n");
						}
					}
				}
				break;
			}//����ͨ�� 
			case '4':{//�û�ѡ����---�˳�--- 
				if(f_state){
					printf("!!!�ļ���û����!!!\n");getchar();
				}
				else{
					return 0;//ֱ����ֹ����
				}
				break;
			}//����ͨ�� 
		}
	}
	return 0;
}
char interface(){//��ʾ������ ,�������û����� 
	printf("**********************************************\n");
	printf("\t\tѧ������ϵͳ\n");
	printf("\t1 ѧ��������Ϣ����\n");
	printf("\t2 ѧ���ɼ�����ϵͳ\n");
	printf("\t3 �ļ�����\n");
	printf("\t4 �˳�\n");
	printf("������ѡ��"); 
	char n;//�û���ѡ�� 
	n=getchar();getchar();
	return n;
}//����ͨ�� 
//���Ĵ��룺�ļ���򿪡�д��
struct student_info *Read(FILE *file){//���ļ���������������ļ�ָ��,���������head 
	struct student_info *head,*p1,*p2;//����headָ���p1��p2���ڶ�̬�������� 
	head=(struct student_info *)malloc(info_len);//��̬����һ���ռ䣬��������ĵ�һ���ڵ㣬������head����head
	fread(head,info_len,1,file);// ��ո�����ĵ�һ��ռ��ж�����Ӧ������
	//�и����ص����⣺���ļ�Ϊһ�����ļ�ʱ�Ʊػ������˻���дһ�����������ж��ǲ��ǿ��ļ� 
	p1=head;p2=NULL;//p1���׵�ַ��p2ָ��գ����ں���Ķ�̬��������
	while(p1->next!=NULL){//�����ݱ����������Ҫ�����ԭ�ⲻ���ؽ��ڴ��е����ݴ洢��������ʹԭ���ṹ����ָ����һ���ڵ��ָ����Ϊÿ�������ڴ��ַ��ͬ��ԭ����ֱ��ʹ�ã������ɿ���ͨ���Ƿ�ΪNULL���ж������Ƿ���� 
		p2=(struct student_info *)malloc(info_len);//��̬����ռ����ڽ�������
		fread(p2,info_len,1,file);//�������·�����ڴ���д������ 
		p1->next=p2;//���ӽڵ�
		p1=p2;//ָ����� 
	} 
	p1->next=NULL;//��־������� 
	return head;//��ʼ���� 
}//����ͨ�� 
void Write(FILE *file,struct student_info *head){//������ԭ�ⲻ���ش��ڴ�д���ļ��� 
	struct student_info *p1,*p2;//�����ڶ�ȡ�����ڶ�ȡ����д��
	p1=head;p2=head;//����p1ָ��head��p2ָ�գ�����������ѭ��
	do{
		fwrite(p2,info_len,1,file);
		p2=p1->next;//p2ָ����һ���ڵ�
		p1=p2;//p1���� 
	}while(p2!=NULL); 
}//����ͨ�� 
struct student_score origion={0.0,0.0,0.0,0.0};//����һ��ԭʼ�ķ����ṹ�壬Ĭ��Ϊ��֣�Ϊ�˻�����Ϣ����ӵķ��� 
struct student_info *Form(){//�������룬���û��������ݣ����γ�ѧ���Ļ�����Ϣ���ݽڵ㣬���ظýڵ��ͷָ�� 
	struct student_info *head;
	//��ṹ�� �ڵı���һһ��Ӧ 
	long long Number;
	char Name[15];
	char Sex;
	int Age;
	//���û�һһ������Щ����
	printf("��������ѧ����ѧ�ţ�");scanf("%lld",&Number);
	printf("��������ѧ�������֣�");getchar();//�Իس�
	gets(Name);
	printf("�������Ա�M/F��");Sex=getchar();
	printf("���������䣺");scanf("%d",&Age);getchar(); 
	//����¼����ϣ��������γ�һ���µĽڵ�
	head=(struct student_info *)malloc(info_len);//�����µĿռ� 
	head->number=Number; 
	strcpy(head->name,Name);//�ַ�������ֱ���õȺŸ�ֵ 
	head->sex=Sex;
	head->age=Age;
	head->score=origion;//Ĭ�����
	head->next=NULL;//����ԭ����������ʱ�ٸ�ֵ 
	//��ֵ���
	return head; 
}
void Del(struct student_info *head,long long num){//ɾ����ǰѧ�Ŷ�Ӧ�Ľڵ�
	struct student_info *p1,*p2;
	p1=head;p2=NULL;
	while(1){
		p2=p1->next;
		if(p2==NULL){
			break;
		}
		if(p2->number==num){//�����p2������p1������Ҫɾ����ǰԪ��ֻ����ǰһ��Ԫ�ص�ָ�������� 
			p1->next=p2->next;//�ܿյ�ǰԪ�� 
			return;
		}
		p1=p2;
	} 
	printf("!!!���޴���!!!\n");getchar();
}
void Find(struct student_info *head,long long num){//����headָ��������в���ѧ��Ϊnum��ѧ�� 
	struct student_info *p1,*p2;//���ڱ�������
	p1=head;p2=NULL;
	do{
		p2=p1->next;
		if(p1->number==num){//�����ǰԪ�ؾ���Ҫ�����Ԫ�� 
			printf("---------ѧ����Ϣ---------\n");
			printf("ѧ��:%lld\n",p1->number);
			printf("����:");puts(p1->name);
			printf("�Ա�:%c\n",p1->sex);
			printf("����:%d\n",p1->age);
			printf("---------�������---------\n");getchar();
			return;
		}
		p1=p2;
	}while(p2!=NULL); 
	printf("!!!���޴���!!!\n");getchar();
}
void Change(struct student_info *head,long long num){//����headָ��������и���ѧ��Ϊnum��ѧ������Ϣ 
	struct student_info *p1,*p2;//���ڱ�������
	p1=head;p2=NULL;
	do{
		p2=p1->next;
		if(p1->number==num){//�����ǰԪ�ؾ���Ҫ���ĵ�Ԫ��
			printf("---------ԭ����Ϣ---------\n");
			printf("ѧ��:%lld\n",p1->number);
			printf("����:");puts(p1->name);
			printf("�Ա�:%c\n",p1->sex);
			printf("����:%d\n",p1->age);
			printf("---------�������---------\n");
			printf("---------������Ϣ---------\n");
			printf("��������ѧ�ţ�");scanf("%lld",&(p1->number));
			printf("�������µ����֣�");getchar();//�Իس�
			gets(p1->name);
			printf("�������Ա�M/F��");p1->sex=getchar();getchar();
			printf("���������䣺");scanf("%d",&(p1->age));getchar();
			return;
		}
		p1=p2;
	}while(p2!=NULL);
	printf("!!!���޴���!!!\n");getchar();
}
void Borrow(struct student_info *head){//�����������ѧ����Ϣ 
	struct student_info *p1,*p2;
	p1=head;p2=NULL;
	printf("---------��Ϣչʾ---------\n");
	printf("ѧ��\t\t����\t�Ա�\t����\n");
	do{
		p2=p1->next;
		printf("%lld\t",p1->number);//����ĳ��ȣ�һ�����������Ʊ��������Ӧ�õ���һ�£��� ������� 
		printf("%s",p1->name);
		printf("\t%c\t%d\n",p1->sex,p1->age);
		p1=p2;
	}while(p2!=NULL);
	printf("---------����-------------\n");getchar();
} 
void Borrow_score(struct student_info *head){//�鿴����ѧ���ĳɼ� 
	struct student_info *p1,*p2;
	p1=head;p2=NULL;
	do{
		p2=p1->next;
		printf("---------ѧ���ɼ����------\n");
		printf("����:");puts(p1->name);
		printf("C���Գɼ�:%.1f\n�����ɼ�:%.1f\n�ߴ��ɼ�:%.1f\nӢ��ɼ�:%.1f\n",p1->score.C,p1->score.H_math,p1->score.X_dai,p1->score.Eng);
		printf("---------����--------------\n");getchar();
		p1=p2;
	}while(p2!=NULL); 
}
void  Find_score(struct student_info *head,long long num){//�ҵ�ѧ�Ŷ�Ӧ��ѧ�����������/�����еĳɼ� 
	struct student_info *p1,*p2;
	p1=head;p2=NULL;
	do{
		p2=p1->next;
		if(p1->number==num){
			printf("---------ѧ���ɼ����------\n");
			printf("����:");puts(p1->name);
			printf("C���Գɼ�:%.1f\n�����ɼ�:%.1f\n�ߴ��ɼ�:%.1f\nӢ��ɼ�:%.1f\n",p1->score.C,p1->score.H_math,p1->score.X_dai,p1->score.Eng);
			printf("---------����--------------\n");getchar();
			return;
		}
		p1=p2;
	}while(p2!=NULL);
	printf("!!!���޴���!!!\n");getchar();
}
void Change_score(struct student_info *head,long long num){
	struct student_info *p1,*p2;
	p1=head;p2=NULL;
	do{
		p2=p1->next;
		if(p1->number==num){
			printf("---------ѧ��ԭ�гɼ�------\n");
			printf("����:");puts(p1->name);
			printf("C���Գɼ�:%.1f\n�����ɼ�:%.1f\n�ߴ��ɼ�:%.1f\nӢ��ɼ�:%.1f\n",p1->score.C,p1->score.H_math,p1->score.X_dai,p1->score.Eng);
			printf("---------����--------------\n");
			printf("---------����¼��----------\n");
			printf("����������C���ԡ��������ߴ���Ӣ��ɼ����ո����ָ�\n");
			scanf("%f %f %f %f",&(p1->score.C),&(p1->score.H_math),&(p1->score.X_dai),&(p1->score.Eng));getchar();
		}
		p1=p2;
	}while(p2!=NULL);
} 
struct student_info *Return(struct student_info *head,long long num){//����ѧ��Ϊnum�Ľڵ�ĵ�ַ 
	struct student_info *p1,*p2;
	p1=head;p2=NULL;
	do{
		p2=p1->next;
		if(p1->number==num){
			return p1;//Ĭ��ѧ�Ų����ظ�,�����ظ���ֻ�����һ�� 
		}
		p1=p2;
	}while(p2!=NULL);
	return NULL;
}
long long Name(struct student_info *head,char *NAme){//�������ַ���ѧ�� 
	int tst(char *p1,char *p2);//����tst���� 
	struct student_info *p1,*p2;
	p1=head;p2=NULL;
	do{
		p2=p1->next;
		if(tst(p1->name,NAme)){
			return p1->number;
		}
		p1=p2;
	}while(p2!=NULL);
	return -1;
}
int tst(char *p1,char *p2){//�ж������ַ����Ƿ���ȣ���ȷ���1 
	int len1,len2;
	len1=strlen(p1);len2=strlen(p2);
	if(len1!=len2){
		return 0;
	}
	else{
		int i;
		for(i=0;i<len1;i++){
			if(*(p1+i)!=*(p2+i)){
				return 0;//������һ����������Ͳ���� 
			}
		}
	}
	return 1;//Ը������ǧ���������������� 
}
struct student_info *End(struct student_info *head){//���������������һ���ڵ��ָ�� 
	struct student_info *p1,*p2;
	p1=head;p2=NULL;
	while(1){
		p2=p1->next;
		if(p2==NULL){
			return p1;
		}
		p1=p2; 
	}
}
int student_number(struct student_info *head){//����ѧ�������ĺ�������Ϊ����Ҫ��������һ��Ԫ�أ���ˣ���ֻ��һ��Ԫ��ʱ����ɾ�� 
	int i;
	struct student_info *p1,*p2;
	p1=head;p2=NULL;
	for(i=0;p1!=NULL;i++){
		p2=p1->next;
		p1=p2;
	}
	return i;
}
