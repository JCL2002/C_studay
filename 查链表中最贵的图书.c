#include<stdio.h>
#include<stdlib.h>
#define len sizeof(struct book)
struct book{
	long long id;//���
	char book_name[257];//����
	char auther[129];//����
	int charge;//�۸�
	struct book *next;//ָ�� 
};
int main(){
	long long Search(struct book *head);
	struct book *head,*p1,*p2;//����ָ��
	head=(struct book *)malloc(len); 
	p1=head;p2=NULL;
	int n;//�鼮����
	int i;//����ѭ��
	printf("�鼮������");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("####��%d�������Ϣ¼�룬��%d��####\n",i+1,n);
		printf("�������鼮id��");
		scanf("%lld",&(p1->id));getchar();//�����س�
		printf("�������鼮���ƣ�");
		gets(p1->book_name);
		printf("���ߣ�");
		gets(p1->auther);
		printf("�۸�");
		scanf("%d",&(p1->charge));getchar();
		if(i+1==n){
			p1->next=NULL;//���� 
		}
		else{
			p2=(struct book *)malloc(len);
			p1->next=p2;
			p1=p2;
		} 
	} 
	//����������Ĵ��� 
	printf("�������id�ǣ�%lld",Search(head));
	return 0;
}
long long Search(struct book *head){
	struct book  *p1,*p2;
	int max=head->charge;
	long long max_id=head->id;//�������id 
	p1=head;p2=NULL;//�ٶȳ�ʼ��ָ�� 
	while(p1->next!=NULL){
		p2=p1->next;
		if((p2->charge)>max){
			max=p2->charge;
			max_id=p2->id;
		}
		p1=p2;
	}
	return max_id;
}
