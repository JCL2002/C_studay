#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define info_len sizeof(struct student_info)
#define score_len sizeof(struct sudent_score)
/*
info_len储存了student_info这个结构体的长度，用于malloc
score_len储存了score_info这个结构体的长度…… 
*/
struct student_score{//学生分数结构体 
	float C;//C语言成绩
	float H_math;//高数成绩
	float X_dai;//线代成绩 
	float Eng;//英语成绩 
};
struct student_info {//学生信息结构体，内嵌了学生分数 
	long long number;//学号 
	char name[15];//学生姓名
	char sex;//学生性别M/F
	int age;//年龄 
	struct student_score score;//包含学生的成绩数据结构 
	struct student_info *next;//指向下一个节点的指针 
};
struct student_info Kong={0,"init",'?',0,{},NULL,};//定义一个空的值，用于创建新文件时让文件有至少一个内容 
//以上是结构体的定义 
int main(){
	char interface();//引入主界面函数 
	struct student_info *Read(FILE *file);//引入文件读取函数 
	void Write(FILE *file,struct student_info *head);//引入文件写入函数 
	struct student_info *Form();//引入节点生成函数 
	void Del(struct student_info *head,long long num);//引入节点删除函数 
	void Find(struct student_info *head,long long num);//引入查找函数 
	void Change(struct student_info *head,long long num);//引入更改节点的函数
	void Borrow(struct student_info *head);//引入浏览的函数 
	void Borrow_score(struct student_info *head);//引入成绩浏览的函数 
	void  Find_score(struct student_info *head,long long num);//引入根据学号查成绩的函数 
	void Change_score(struct student_info *head,long long num);//引入根据学号修改成绩的函数 
	struct student_info *Return(struct student_info *head,long long num);//引入根据学号返回所在节点指针的函数 
	long long Name(struct student_info *head,char *NAme);//引入根据名字返回学号的函数 
	int tst(char *p1,char *p2);//引入判断字符串是否相等的函数 
	struct student_info *End(struct student_info *head);//返回链表最后一个节点的指针 
	int student_number(struct student_info *head);//返回学生数量
	//函数调用 
	struct student_info *head=NULL;//初始化head指针
	FILE *file=NULL;//定义文件指针 
	char file_name[513];//用于储存文件名
	char m_choice;//储存用户在主界面的选择 
	int mark;//用于判断是否需要继续循环 
	int f_state=0;//文件的打开状态，0代表处于未打开状态 
	while(1){//每次都回到主界面，直到用户退出 
		m_choice=interface();//调用显示函数，并带回返回值 
		FILE *file;//定义文件指针 
		switch(m_choice){
			case '1':{//用户选择了---基本信息管理 --- 
				mark=1;
				char choice;//用于保存用户的选择 
				while(mark){
					printf("---------请选择功能---------\n1 查找\n2 添加\n3 删除\n4 修改\n5 浏览\n6 退出当前模块\n请输入：");
					choice=getchar();getchar();
					switch(choice){
						case '1':{//用户选择了--查找-- 
							char choose;
							if(f_state){
								printf("输入要根据什么查找：1 学号；2 名字\n");
								choose=getchar();getchar(); 
								if(choose=='1'){
									long long nu;
									printf("请输入要查找的学生的学号：");
									scanf("%lld",&nu);getchar();//吃回车  
									Find(head,nu);//调用更改函数 
								}
								else if(choose=='2'){
									char n[15];
									printf("请输入要查找的学生的姓名：");
									gets(n);
									Find(head,Name(head,n));
								}
								else{
									printf("!!!输入有误!!!\n");
								}
							}
							else{
								printf("!!!没有打开的文件!!!\n");
							}//调试通过 
							break;
						}
						case '2':{//用户选择了--添加-- 
							char choose;
							if(f_state){
								printf("请输入要插入的位置：1 末尾 2 指定学号之后 3 指定名字之后 4 插在第一位\n");
								choose=getchar();getchar();
								if(choose=='1'){//用户要在末尾插内容 
									int count,i;//插入的个数
									printf("请输入要插入的个数:\n");
									scanf("%d",&count);getchar(); 
									for(i=0;i<count;i++){
										struct student_info *tmp;//创建一个临时指针用来盛放新创立的节点的地址；
										struct student_info *end;//用来存放结尾元素的指针 
										end=End(head);//遍历链表，找出当前末尾那个元素的指针
										tmp=Form();//使用Form函数生成一个节点
										end->next=tmp;//将临时节点加入到链表中
										//Form函数形成的节点的next为NULL，因此不需再次对他赋空 
									} 
								}
								else if(choose=='2'){//用户要在指定的学号后插入内容 
									printf("请输入学号，将在这个学号后面插入：\n");
									long long nu;
									scanf("%lld",&nu);getchar();
									int count,i;
									printf("请输入要插入的个数:\n");
									scanf("%d",&count);getchar();
									for(i=0;i<count;i++){
										struct student_info *tmp;//创建一个临时指针用来盛放新创立的节点的地址；
										struct student_info *target;//用来存放指定元素的指针
										target=Return(head,nu);//找到目标
										if(target==NULL){//查无此人的情况 
											printf("!!!查无此人!!!\n");
											break;
										}
										tmp=Form();//生成节点
										tmp->next=target->next;//将新生成的节点的下一跳指向原有链表中它该有的位置(交尾)
										nu=tmp->number;//nu值更新，为下一次循环坐准备 
										target->next=tmp;//将原有的链表目标节点的下一跳地址指向新形成的节点（碰头） 
									}
								}
								else if(choose=='3'){//用户选择在指定名字之后插入内容
									printf("请输入名字，将在这个名字后面插入：\n");
									char n[15];
									gets(n);
									long long nu;
									nu=Name(head,n);//根据名字获得学号
									int count,i;
									printf("请输入要插入的个数:\n");
									scanf("%d",&count);getchar(); 
									for(i=0;i<count;i++){
										struct student_info *tmp;//创建一个临时指针用来盛放新创立的节点的地址；
										struct student_info *target;//用来存放指定元素的指针
										target=Return(head,nu);//找到目标
										if(target==NULL){//查无此人的情况 
											printf("!!!查无此人!!!\n");
											break;
										}
										tmp=Form();//生成节点
										tmp->next=target->next;//将新生成的节点的下一跳指向原有链表中它该有的位置(交尾)
										nu=tmp->number;//nu值更新，为下一次循环坐准备 
										target->next=tmp;//将原有的链表目标节点的下一跳地址指向新形成的节点（碰头） 
									}
								}
								else if(choose=='4'){//用户选择了插在第一位 
									struct student_info *tmp;
									tmp=Form();
									tmp->next=head;
									head=tmp;
								}//调试通过 
								else{
									printf("!!!输入错误!!!\n");
								} 
							}
							else{
								printf("!!!没有已经打开的文件!!!\n");
							}
							break;
						}//调试通过 
						case '3':{//用户选择了--删除-- 
							char choose;
							if(f_state){
								if(student_number(head)>1){//当学生数大于1才能删除 
									printf("1 根据学号删除 2 根据姓名删除\n");
									choose=getchar();getchar(); 
									if(choose=='1'){//用户选择了根据学号删除 
										long long nu;
										printf("请输入要删除的学生的学号:");
										scanf("%lld",&nu);getchar();
										struct student_info *p;
										p=Return(head,nu);//先返回要删的人的位置 
										if(p==head){//如果要删除的人是第一个元素 
											head=head->next;//架空第一个元素 
										} 
										else{
											Del(head,nu);
										}
									}
									else if(choose=='2'){//用户选择了根据姓名删除 
										long long nu;
										struct student_info *p;
										printf("请输入要删除的学生的名字:");
										char n[15];gets(n);
										nu=Name(head,n);
										p=Return(head,nu);
										if(p==head){//如果要删除的人是第一个元素 
											head=head->next;//架空第一个元素 
										} 
										else{
											Del(head,nu);
										}
									} 
									else{
										printf("!!!输入有误!!!\n");
									}
								}
								else{
									printf("删除错误：只有一个学生");getchar();
								} 
								
							}
							else{
								printf("!!!没有已经打开的文件!!!\n");
							}
							break;
						}
						case '4':{//用户选择了--修改-- 
							char choose;
							if(f_state){
								printf("输入要根据什么修改：1 学号；2 名字\n");
								choose=getchar();getchar(); 
								if(choose=='1'){
									long long nu;
									printf("请输入要更改的学生的学号：");
									scanf("%lld",&nu);getchar();//吃回车  
									Change(head,nu);//调用更改函数 
								}
								else if(choose=='2'){
									char n[15];
									printf("请输入要更改的学生的姓名：");
									gets(n);
									Change(head,Name(head,n));
								}
								else{
									printf("!!!输入有误!!!\n");
								}
							}
							else{
								printf("没有已经打开的文件\n");
							}
							break;
						}//调试通过 
						case '5':{//用户选择了--浏览-- 
							if(f_state){
								Borrow(head);
							}
							else{
								printf("!!!还没有打开的文件!!!\n");
							}
							break;
						}//调试通过 
						case '6':{//用户选择了--退出当前模块
//							fclose(file);//关闭打开的文件 
							mark=0;
							break;
						}//调试通过 
						default:{//输入有误 
							printf("输入有误!!!重输\n");
						}
					} 
				} 
				break;
			}//调试通过 
			case '2':{//用户选择了---学生成绩信息管理--- 
				mark=1;
				char choice;//用于保存用户的选择 
				while(mark){
					printf("---------请选择功能---------\n1 查找\n2 修改\n3 浏览\n4 退出当前模块\n请输入：\n");
					choice=getchar();getchar();
					switch(choice){
						case '1':{//用户选择了--查找--
							char choose;
							printf("1 根据学号查找 2 根据姓名查找\n");
							choose=getchar();getchar();
							if(choose=='1'){
								long long nu;
								printf("请输入学号：\n");
								scanf("%lld",&nu);getchar();
								Find_score(head,nu);
							}
							else if(choose=='2'){
								char n[15];
								printf("请输入姓名：\n");
								gets(n);
								Find_score(head,Name(head,n));
							}
							else{
								printf("!!!输入有误!!!\n"); 
							}
							break;
						}
						case '2':{//用户选择了--修改--
							char choose;
							printf("1 根据学号修改 2 根据姓名修改\n");
							choose=getchar();getchar();
							if(choose=='1'){
								long long nu;
								printf("请输入学号：\n");
								scanf("%lld",&nu);getchar();
								Change_score(head,nu);
							}
							else if(choose=='2'){
								char n[15];
								printf("请输入姓名：\n");
								gets(n);
								Change_score(head,Name(head,n));
							}
							else{
								printf("!!!输入有误!!!\n");
							}
							break;
						}
						case '3':{//用户选择了--浏览-- 
							Borrow_score(head);
							break;
						}
						case '4':{//用户选择了--退出当前模块--
							mark=0;
							break;
						}
						default:{//输入有误
							printf("输入有误!!!重输\n");
						}
					}
				}
				break;
			} 
			case '3':{//用户选择了---文件操作--- 
				mark=1;
				char choice;//用于保存用户的选择
				while(mark){
					printf("---------请选择功能---------\n1 新建学生信息文件\n2 打开文件\n3 保存关闭文件\n4 不保存关闭文件（不进行保存）\n5 退出该模块\n请输入：");
					choice=getchar();getchar();
					switch(choice){
						case '1':{//用户选择了--新建文件-- 
							int mark_1=1;//下一层循环的判断条件
							while(mark_1){
								if(f_state){
									printf("有打开的文件没有关闭，请先关闭这个文件!");
									mark_1=0;
								} 
								else{
									printf("请输入文件名:"); 
									gets(file_name);
									if((file=fopen(file_name,"wb+"))==NULL){//文件创建不成功 
										printf("文件建立失败，请检查文件名、权限\n");
									} 
									else{
										mark_1=0;//文件已经打开，不需要再次循环 
										Write(file,&Kong);//先向文件中写一个初始化的空值，否则打不开 
										fclose(file);//关闭保存文件 
										file=fopen(file_name,"rb+");//再次打开文件，与上次不同，这次是只读
										head=Read(file);//将文件的内容读到内存中，形成链表，第一个节点的指针返回给head
										f_state=1;//标记文件为已经打开状态 
										mark=0;//直接就跳出这个模块 
								}
							} 
							}
							break;
						}//调试已通过 
						case '2':{//用户选择了--打开文件 
							if(!f_state){
								printf("请输入文件名:");
								gets(file_name);
								if((file=fopen(file_name,"rb+"))==NULL){//文件创建不成功 
									printf("文件打开失败，请检查文件名、权限");getchar();
								} 
								else{
									head=Read(file);//将文件的内容读到内存中，形成链表，第一个节点的指针返回给head
									f_state=1;//标记文件为已经打开状态 
									mark=0;//直接就跳出这个模块 
								}
							}
							else{
								printf("已有打开的文件了，请先关闭它");getchar(); 
							}
							break;
						}//调试通过 
						case '3':{//用户选择了--保存关闭文件 
							if(f_state){//判断是否有打开了的文件 
								fclose(file);//关闭原来打开的文件
								file=fopen(file_name,"wb"); 
								Write(file,head);//将内存中的链表保存到文件中
								fclose(file);//关闭文件
								f_state=0;//文件状态标记为关闭 
								mark=0;//直接就跳出这个模块 
							}
							else{
								printf("没有已经打开的文件!\n");
							}
							break;
						}//调试通过 
						case '4':{//用户选择了--不保存关闭文件 
							if(f_state){
								fclose(file);
								f_state=0;
								mark=0;//直接就跳出这个模块 
							}
							else{
								printf("没有打开的文件");
							}
							break;
						}//调试通过 
						case '5':{//用户选择了退出该模块 
							mark=0;
							break;
						}
						default:{
							printf("输入有误!!!\n");
						}
					}
				}
				break;
			}//调试通过 
			case '4':{//用户选择了---退出--- 
				if(f_state){
					printf("!!!文件还没保存!!!\n");getchar();
				}
				else{
					return 0;//直接终止程序
				}
				break;
			}//测试通过 
		}
	}
	return 0;
}
char interface(){//显示主界面 ,并接受用户输入 
	printf("**********************************************\n");
	printf("\t\t学生管理系统\n");
	printf("\t1 学生基本信息管理\n");
	printf("\t2 学生成绩管理系统\n");
	printf("\t3 文件操作\n");
	printf("\t4 退出\n");
	printf("请做出选择："); 
	char n;//用户的选择 
	n=getchar();getchar();
	return n;
}//调试通过 
//核心代码：文件打打开、写入
struct student_info *Read(FILE *file){//把文件翻译成链表，传入文件指针,返回链表的head 
	struct student_info *head,*p1,*p2;//定义head指针和p1、p2用于动态建立链表 
	head=(struct student_info *)malloc(info_len);//动态申请一个空间，用于链表的第一个节点，并将其head赋给head
	fread(head,info_len,1,file);// 向刚刚申请的第一块空间中读入相应的数据
	//有个严重的问题：当文件为一个空文件时势必会出错，因此还得写一个函数用来判读是不是空文件 
	p1=head;p2=NULL;//p1向首地址，p2指向空，用于后面的动态建立数组
	while(p1->next!=NULL){//在数据保存过程中我要求程序原封不动地将内存中的内容存储下来，即使原来结构体中指向下一个节点地指针因为每次运行内存地址不同地原因不能直接使用，但依旧可以通过是否为NULL来判断链表是否结束 
		p2=(struct student_info *)malloc(info_len);//动态申请空间用于建立链表
		fread(p2,info_len,1,file);//继续向新分配的内存中写入数据 
		p1->next=p2;//链接节点
		p1=p2;//指针后移 
	} 
	p1->next=NULL;//标志链表结束 
	return head;//有始有终 
}//调试通过 
void Write(FILE *file,struct student_info *head){//将链表原封不动地从内存写到文件里 
	struct student_info *p1,*p2;//类似于读取，用于读取链表写入
	p1=head;p2=head;//先让p1指向head，p2指空，接下来依次循环
	do{
		fwrite(p2,info_len,1,file);
		p2=p1->next;//p2指向下一个节点
		p1=p2;//p1跟进 
	}while(p2!=NULL); 
}//调试通过 
struct student_score origion={0.0,0.0,0.0,0.0};//定义一个原始的分数结构体，默认为零分，为了基本信息的添加的方便 
struct student_info *Form(){//内置输入，让用户输入数据，以形成学生的基本信息数据节点，返回该节点的头指针 
	struct student_info *head;
	//与结构体 内的变量一一对应 
	long long Number;
	char Name[15];
	char Sex;
	int Age;
	//让用户一一输入这些数据
	printf("请输入新学生的学号：");scanf("%lld",&Number);
	printf("请输入新学生的名字：");getchar();//吃回车
	gets(Name);
	printf("请输入性别M/F：");Sex=getchar();
	printf("请输入年龄：");scanf("%d",&Age);getchar(); 
	//数据录入完毕，接下来形成一个新的节点
	head=(struct student_info *)malloc(info_len);//开辟新的空间 
	head->number=Number; 
	strcpy(head->name,Name);//字符串不能直接用等号赋值 
	head->sex=Sex;
	head->age=Age;
	head->score=origion;//默认零分
	head->next=NULL;//在于原有链表链接时再赋值 
	//赋值完毕
	return head; 
}
void Del(struct student_info *head,long long num){//删除当前学号对应的节点
	struct student_info *p1,*p2;
	p1=head;p2=NULL;
	while(1){
		p2=p1->next;
		if(p2==NULL){
			break;
		}
		if(p2->number==num){//这次是p2而不是p1，因外要删除当前元素只能用前一个元素的指针来操作 
			p1->next=p2->next;//架空当前元素 
			return;
		}
		p1=p2;
	} 
	printf("!!!查无此人!!!\n");getchar();
}
void Find(struct student_info *head,long long num){//遍历head指向的链表中查找学号为num的学生 
	struct student_info *p1,*p2;//用于遍历链表
	p1=head;p2=NULL;
	do{
		p2=p1->next;
		if(p1->number==num){//如果当前元素就是要输出的元素 
			printf("---------学生信息---------\n");
			printf("学号:%lld\n",p1->number);
			printf("姓名:");puts(p1->name);
			printf("性别:%c\n",p1->sex);
			printf("年龄:%d\n",p1->age);
			printf("---------输出结束---------\n");getchar();
			return;
		}
		p1=p2;
	}while(p2!=NULL); 
	printf("!!!查无此人!!!\n");getchar();
}
void Change(struct student_info *head,long long num){//遍历head指向的链表中更改学号为num的学生的信息 
	struct student_info *p1,*p2;//用于遍历链表
	p1=head;p2=NULL;
	do{
		p2=p1->next;
		if(p1->number==num){//如果当前元素就是要更改的元素
			printf("---------原有信息---------\n");
			printf("学号:%lld\n",p1->number);
			printf("姓名:");puts(p1->name);
			printf("性别:%c\n",p1->sex);
			printf("年龄:%d\n",p1->age);
			printf("---------输出结束---------\n");
			printf("---------更改信息---------\n");
			printf("请输入新学号：");scanf("%lld",&(p1->number));
			printf("请输入新的名字：");getchar();//吃回车
			gets(p1->name);
			printf("请输入性别M/F：");p1->sex=getchar();getchar();
			printf("请输入年龄：");scanf("%d",&(p1->age));getchar();
			return;
		}
		p1=p2;
	}while(p2!=NULL);
	printf("!!!查无此人!!!\n");getchar();
}
void Borrow(struct student_info *head){//遍历链表，浏览学生信息 
	struct student_info *p1,*p2;
	p1=head;p2=NULL;
	printf("---------信息展示---------\n");
	printf("学号\t\t姓名\t性别\t年龄\n");
	do{
		p2=p1->next;
		printf("%lld\t",p1->number);//这里的长度（一个还是两个制表符）或许应该调整一下，看 具体情况 
		printf("%s",p1->name);
		printf("\t%c\t%d\n",p1->sex,p1->age);
		p1=p2;
	}while(p2!=NULL);
	printf("---------结束-------------\n");getchar();
} 
void Borrow_score(struct student_info *head){//查看所有学生的成绩 
	struct student_info *p1,*p2;
	p1=head;p2=NULL;
	do{
		p2=p1->next;
		printf("---------学生成绩输出------\n");
		printf("姓名:");puts(p1->name);
		printf("C语言成绩:%.1f\n高数成绩:%.1f\n线代成绩:%.1f\n英语成绩:%.1f\n",p1->score.C,p1->score.H_math,p1->score.X_dai,p1->score.Eng);
		printf("---------结束--------------\n");getchar();
		p1=p2;
	}while(p2!=NULL); 
}
void  Find_score(struct student_info *head,long long num){//找到学号对应的学生，并输出他/她所有的成绩 
	struct student_info *p1,*p2;
	p1=head;p2=NULL;
	do{
		p2=p1->next;
		if(p1->number==num){
			printf("---------学生成绩输出------\n");
			printf("姓名:");puts(p1->name);
			printf("C语言成绩:%.1f\n高数成绩:%.1f\n线代成绩:%.1f\n英语成绩:%.1f\n",p1->score.C,p1->score.H_math,p1->score.X_dai,p1->score.Eng);
			printf("---------结束--------------\n");getchar();
			return;
		}
		p1=p2;
	}while(p2!=NULL);
	printf("!!!查无此人!!!\n");getchar();
}
void Change_score(struct student_info *head,long long num){
	struct student_info *p1,*p2;
	p1=head;p2=NULL;
	do{
		p2=p1->next;
		if(p1->number==num){
			printf("---------学生原有成绩------\n");
			printf("姓名:");puts(p1->name);
			printf("C语言成绩:%.1f\n高数成绩:%.1f\n线代成绩:%.1f\n英语成绩:%.1f\n",p1->score.C,p1->score.H_math,p1->score.X_dai,p1->score.Eng);
			printf("---------结束--------------\n");
			printf("---------重新录入----------\n");
			printf("请依次输入C语言、高数、线代、英语成绩，空格做分割\n");
			scanf("%f %f %f %f",&(p1->score.C),&(p1->score.H_math),&(p1->score.X_dai),&(p1->score.Eng));getchar();
		}
		p1=p2;
	}while(p2!=NULL);
} 
struct student_info *Return(struct student_info *head,long long num){//返回学号为num的节点的地址 
	struct student_info *p1,*p2;
	p1=head;p2=NULL;
	do{
		p2=p1->next;
		if(p1->number==num){
			return p1;//默认学号不会重复,倘若重复，只输出第一个 
		}
		p1=p2;
	}while(p2!=NULL);
	return NULL;
}
long long Name(struct student_info *head,char *NAme){//根据名字返回学号 
	int tst(char *p1,char *p2);//调用tst函数 
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
int tst(char *p1,char *p2){//判断两个字符串是否相等，相等返回1 
	int len1,len2;
	len1=strlen(p1);len2=strlen(p2);
	if(len1!=len2){
		return 0;
	}
	else{
		int i;
		for(i=0;i<len1;i++){
			if(*(p1+i)!=*(p2+i)){
				return 0;//但凡有一个不相等他就不相等 
			}
		}
	}
	return 1;//愿你历尽千帆，归来仍是少年 
}
struct student_info *End(struct student_info *head){//遍历链表，返回最后一个节点的指针 
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
int student_number(struct student_info *head){//返回学生数量的函数，因为链表要求至少有一个元素，因此，当只有一个元素时不能删除 
	int i;
	struct student_info *p1,*p2;
	p1=head;p2=NULL;
	for(i=0;p1!=NULL;i++){
		p2=p1->next;
		p1=p2;
	}
	return i;
}
