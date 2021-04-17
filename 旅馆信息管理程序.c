#include<stdio.h>
#include<stdlib.h> 
#include<string.h> 
#define T_l sizeof(struct traveler)//旅客数结构体的大小 
#define H_l sizeof(struct hotel)//旅馆结构体大小 
struct traveler{//旅客信息结构体 
	long long ID;
	char name[21];
}; 
struct hotel{//旅馆房间信息结构体 
	int number;//房间号码
	int room_volume;//房间容量
	int room_state;//房间状态，已经住了几个人
	struct  traveler people[3];//房间里住的人,最大房间容量不超过三个人 
};
int main(){
	//函数引入
	void hotel_show(struct hotel *h,int n);//房间信息展示 
	void hotel_search(struct hotel *h,int n,int hid);//房间信息查找 
	void traveler_show(struct traveler *t,int tn,struct hotel *h,int hn);//旅客信息展示 
	void traveler_search(struct traveler *t,int tn,int id,struct hotel *h,int hn);//旅客信息查找 
	void traveler_search_name(struct traveler *t,int tn,char n[15],struct hotel *h,int hn);//旅客信息查找—根据名字 
	int In(struct hotel *h,int hn,struct traveler *t,int tn,int num,int id);//旅客入住 
	void Change(struct hotel *h,int hn,struct traveler *t,int tn,int num,int id);//换房 
	void Out(struct hotel *h,int hn,int id);//退房 
	
	//函数引入结束 
	FILE *file;
	file=fopen("database","rb");//如果在编辑程序自定义了文件名，这里就要修改
	int tn,hn;//tl是旅客的数量，hl是旅馆房间数量 
	int i;//i用于循环 
	fread(&hn,4,1,file);//读取旅馆数量 
	fread(&tn,4,1,file);//读取旅客数量 
	struct traveler t[512];//应该没有哪个变态会搞这么多 
	struct hotel h[256];//应该没有哪个变态会搞这么多
	//数据读入
	for(i=0;i<hn;i++){//旅馆信息读入 
		fread(&h[i],H_l,1,file);
	}
	for(i=0;i<tn;i++){//旅客信息读入 
		fread(&t[i],T_l,1,file);
	}
	fclose(file);
	//数据读入内存完毕 
	char choose;//用户选择的模式
	while(1){//让用户一直在主界面做选择 
		printf("-----------------------------------\n");
		printf("1 查看旅店信息\n2 查看某一房间的信息\n3 产看旅客信息\n4 查找某一旅客信息\n5 旅客入住\n6 旅客换房\n7 旅客退房\n8 退出\n");
		choose=getchar();getchar();
		switch(choose){
			case '1':{//查看旅店信息
				hotel_show(h,hn);
				break;
			}//调试通过 
			case '2':{//查看某一房间的信息
				int hid;
				printf("请输入要查找的房间ID：\n");
				scanf("%d",&hid);getchar();
				hotel_search(h,hn,hid);
				break;
			}//调试通过 
			case '3':{//产看旅客信息
				traveler_show(t,tn,h,hn); 
				break;
			}//调试通过 
			case '4':{//找某一旅客信息
				char choose;
				printf("请输入根据什么查找\n1 ID  2 姓名:\n");
				choose=getchar();getchar();
				if(choose=='1'){//根据ID查找 
					int id;
					printf("请输入旅客ID：");
					scanf("%d",&id);getchar(); 
					traveler_search(t,tn,id,h,hn);
				}//调试通过 
				else if(choose=='2'){//根据姓名查找 
					char n[21];
					printf("请输入旅客名字：\n");
					gets(n);
					traveler_search_name(t,tn,n,h,hn);
				}//调试通过 
				else {
					printf("输入有误！\n");getchar(); 
				}
				break;
			}//调试通过 
			case '5':{//旅客入住
				int num,id;
				printf("请输入要入住的房间号：\n");scanf("%d",&num);getchar();
				printf("请输入要入住的人的ID：\n");scanf("%d",&id);getchar();
				In(h,hn,t,tn,num,id);
				break;
			}//调试通过 
			case '6':{//旅客换房
				int num,id;
				printf("请输入要更改的新房间号：\n");scanf("%d",&num);getchar();
				printf("请输入要更改房间的旅客的id：\n");scanf("%d",&id);getchar();
				Change(h,hn,t,tn,num,id);
				break;
			}
			case '7':{//旅客退房
				int id;
				printf("请输入要退房的人的ID\n");
				scanf("%d",&id);getchar();
				Out(h,hn,id);
				break;
			}
			case '8':{//退出
				file=fopen("database","wb");//重新以写入二进制的形式打开文件 
				fwrite(&hn,4,1,file);//重新写入旅馆数量
				fwrite(&tn,4,1,file);//重新写入旅客数量 
				fwrite(h,H_l,hn,file);//重新写入旅馆结构体 
				fwrite(t,T_l,tn,file);//重写写入旅客结构体 
				fclose(file);//关闭文件 
				return 0;
				break;
			}
		} 
	
	} 
	return 0;
}
void hotel_show(struct hotel *h,int n){//查看旅店信息,依次传入结构体名、旅馆数量
	int i;
	printf("------------房间信息---------------\n"); 
	for(i=0;i<n;i++){
		printf("房间号码：%d\n",h[i].number);
		printf("房间容量：%d\n",h[i].room_volume);
		printf("房间已住人数：%d\n",h[i].room_state);
		if(h[i].room_state>0){//如果房间里有人，就循环输出所有人 
			int j;
			printf("人员姓名：");
			for(j=0;j<h[i].room_state;j++){
				printf("%s\t",h[i].people[j].name); 
			}
			printf("\n");
		}
		printf("*********\n");//用于分割不同房间的信息，便于区分 
		getchar(); 
	}
}
void hotel_search(struct hotel *h,int n,int hid){//查找某一房间的信息,依次传入结构体名、房间数量、房间号 
	int i;
	printf("------------房间信息查找-----------\n");
	for(i=0;i<n;i++){
		if(h[i].number==hid){
			printf("房间号码：%d\n",h[i].number);
			printf("房间容量：%d\n",h[i].room_volume);
			printf("房间已住人数：%d\n",h[i].room_state);
			if(h[i].room_state>0){//如果房间里有人，就循环输出所有人 
				int j;
				printf("人员姓名：");
				for(j=0;j<h[i].room_state;j++){
					printf("%s",h[i].people[j]); 
				}
				printf("\n");
			}
			getchar();
		}
	}
} 
void traveler_show(struct traveler *t,int tn,struct hotel *h,int hn){//旅客信息展示，依次输入旅客结构体名、旅客数量、旅馆结构体名，旅馆数量 
	int i,j,k;int mark=1;
	printf("------------旅客信息---------------\n");
	for(i=0;i<tn;i++,mark=1){
		printf("旅客姓名：%s\n",t[i].name);
		printf("旅客ID：%d\n",t[i].ID);
		for(j=0;j<hn;j++){//在旅馆结构体中遍历，查找旅客的入住信息 
			if(h[j].room_state){//如果旅馆有人住 
				for(k=0;k<h[j].room_state;k++){//在入住的人中遍历查找，看是否有这个人 
					if(h[j].people[k].ID==t[i].ID){
						printf("入住的房间：%d\n",h[j].number);
						mark=0;
					}
				}
			}
		}
		if(mark){
			printf("没有入住旅馆\n");
		}
		printf("*********\n");getchar();
	} 
}
void traveler_search(struct traveler *t,int tn,int id,struct hotel *h,int hn){//旅客信息查找（根据ID），依次传入旅客结构体名、旅客数量、要查找的旅客ID、旅馆结构体名、旅馆数量 
	int i,j,k;int mark=1; 
	printf("------------旅客信息查找-----------\n");
	for(i=0;i<tn;i++,mark=1){
		if(t[i].ID==id){//找到这个人的存在 
			printf("旅客姓名：%s\n",t[i].name);
			printf("旅客ID：%d\n",t[i].ID);
			for(j=0;j<hn;j++){//在旅馆结构体中遍历，查找旅客的入住信息 
				if(h[j].room_state){//如果旅馆有人住 
					for(k=0;k<h[j].room_state;k++){//在入住的人中遍历查找，看是否有这个人 
						if(h[j].people[k].ID==id){
							printf("入住的房间：%d\n",h[j].number);
							mark=0;
						}
					}
				}
			}
			if(mark){
				printf("没有入住旅馆\n");
			}
			printf("*********\n");getchar();
		}
	}
}
void traveler_search_name(struct traveler *t,int tn,char n[15],struct hotel *h,int hn){//旅客信息查找（根据姓名），依次传入旅客结构体名、旅客数量、要查找的旅客的姓名字符串名、旅馆结构体名、旅馆数量
	int i,j,k;int mark=1; 
	int charequal(char *p1,char *p2);//引入字符串比较函数 
	printf("------------旅客信息查找-----------\n");
	for(i=0;i<tn;i++){
		if(charequal(t[i].name,n)){//找到这个人的存在 
			printf("旅客姓名：%s\n",t[i].name);
			printf("旅客ID：%d\n",t[i].ID);
			for(j=0;j<hn;j++){//在旅馆结构体中遍历，查找旅客的入住信息 
				if(h[j].room_state){//如果旅馆有人住 
					for(k=0;k<h[j].room_state;k++){//在入住的人中遍历查找，看是否有这个人 
						if(h[j].people[k].ID==t[i].ID){
							printf("入住的房间：%d\n",h[j].number);
							mark=0;
						}
					}
				}
			}
			if(mark){
				printf("没有入住旅馆\n");
			}
			printf("*********\n");getchar();
		}
	}
}
int charequal(char *p1,char *p2){//判断两个字符串是否相等，相等返回1，不等返回0 
	int l1,l2;
	l1=strlen(p1);l2=strlen(p2);
	if(l1==l2){
		int i;
		for(i=0;i<l1;i++){
			if(*(p1+i)!=*(p2+i)){
				return 0;
			}
		}
		return 1;//愿你历尽千帆，归来仍是少年 
	}
	else{
		return 0;
	}
}
int In(struct hotel *h,int hn,struct traveler *t,int tn,int num,int id){//人员入住，依次输入旅馆结构体名、房间数、旅客结构体名、旅客数量、要入住第几个房间、要入住的旅客ID 
	int i,j;int goon;//用来标记过程是否要继续进行 
	int tid;//储存要入住的人的下标 
	printf("------------旅客入住---------------\n");
	//检测是否存在这个房间
	if((num<1000)||(num-999>hn)){
		printf("房间不存在");getchar();
		goon=0;
	} 
	//检测是否有这个人 
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
	//检测这个人是否已经入住
	if(goon){
		for(i=0;i<hn;i++){
			if(h[i].room_state){//如果房间有人住，遍历住户，看看此人是不是在里边 
				for(j=0;j<h[i].room_state;j++){
					if(h[i].people[j].ID==id){
						printf("%s已经入住：%d\n",t[tid].name,h[i].number);getchar();
						goon=0;
					}
				}
			} 
		}
	} 
	//检测要入组的房间是否住满
	if(goon){
		if(h[num-1000].room_state==h[num-1000].room_volume){
			printf("房间已满！");getchar();
			goon=0;
		}
	} 
	//正式入住
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
void Out(struct hotel *h,int hn,int id){//退房，依次传入旅馆结构体名、房间数量、要退房的人的ID 
	int i,j;//用于循环 
	for(i=0;i<hn;i++){
		if(h[i].room_state){//房间里有人 
			for(j=0;j<h[i].room_state;j++){//遍历每个人 
				 if(h[i].people[j].ID==id){//找到要退房的人,此时i为旅馆结构体数组的下标、j为旅客结构体数组的下标 
				 	h[i].room_state--;
				 	printf("已经退房");getchar();
				 	return;
				 }
			}
		}
	}
	printf("退房失败！可能原因:\n1.旅客ID错误\n2.旅客暂未入住");getchar();
}
void Change(struct hotel *h,int hn,struct traveler *t,int tn,int num,int id){
	void Out(struct hotel *h,int hn,int id);//引用退房函数 
	int In(struct hotel *h,int hn,struct traveler *t,int tn,int num,int id);//引用入住函数 
	int mark_out=0,mark_in=0;//用来标记退房、入住是否成功 
	//先保存退房信息
	int o_number;//保存原住房number 
	int i,j;//用于循环 
	for(i=0;i<hn;i++){
		if(h[i].room_state){//房间里有人 
			for(j=0;j<h[i].room_state;j++){//遍历每个人 
				 if(h[i].people[j].ID==id){//找到要退房的人,此时i为旅馆结构体数组的下标、j为旅客结构体数组的下标 
				 	o_number=h[i].number;
				 	mark_out=1;//能找到就一定能退房 
				 }
			}
		}
	}
	//退房
	if(mark_out)Out(h,hn,id);
	//入住新房
	if(mark_out)mark_in=In(h,hn,t,tn,num,id);
	//判断是否需要还原 
	if(mark_in){//成功入住 
		printf("换房成功\n");getchar(); 
	}
	else{//换房不成功，还原原有状态 
		if(mark_out){
			In(h,hn,t,tn,num,id);
		}
		else{
			printf("该旅客还未入住");getchar();
		}
		 
	}
}
