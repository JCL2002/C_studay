#include<stdio.h>
#include<stdlib.h>
#define len sizeof(struct book)
struct book{
	long long id;//编号
	char book_name[257];//书名
	char auther[129];//作者
	int charge;//价格
	struct book *next;//指针 
};
int main(){
	long long Search(struct book *head);
	struct book *head,*p1,*p2;//定义指针
	head=(struct book *)malloc(len); 
	p1=head;p2=NULL;
	int n;//书籍数量
	int i;//用于循环
	printf("书籍数量：");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("####第%d个书的信息录入，共%d个####\n",i+1,n);
		printf("请输入书籍id：");
		scanf("%lld",&(p1->id));getchar();//消化回车
		printf("请输入书籍名称：");
		gets(p1->book_name);
		printf("作者：");
		gets(p1->auther);
		printf("价格：");
		scanf("%d",&(p1->charge));getchar();
		if(i+1==n){
			p1->next=NULL;//结束 
		}
		else{
			p2=(struct book *)malloc(len);
			p1->next=p2;
			p1=p2;
		} 
	} 
	//以上是链表的创建 
	printf("最贵的书的id是：%lld",Search(head));
	return 0;
}
long long Search(struct book *head){
	struct book  *p1,*p2;
	int max=head->charge;
	long long max_id=head->id;//最贵的书的id 
	p1=head;p2=NULL;//再度初始化指针 
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
