#include<stdio.h>
#define L_t sizeof(struct traveler)
#define L_h sizeof(struct hotel)
struct traveler{//旅客信息结构体 
	long long ID;
	char name[21];
}; 
struct hotel{//旅馆房间信息结构体 
	int number;//房间号码
	int room_volume;//房间容量
	int room_state;//房间状态，已经住了几个人
	struct  traveler people[3];//房间里住的人 
};
int main(){
	printf("第二题题干没有要求对旅馆和旅客的数据进行编辑");getchar();
	printf("那么所有数据就是在程序运行之初就给定好了");getchar();
	printf("总不能“所有人”的数据都是一样的吧，你懂的");getchar();
	printf("这个程序只是用来编辑初始数据的，没有对输入数据的正确与否进行检测\n");
	printf("仔细输入，但凡有一个输错就出BUG");getchar(); 
	int t_n,h_n;//房间数量和旅客数量
	printf("请输入房间数量（不少于15,不大于50）：\n");
	scanf("%d",&h_n);
	printf("请输入旅客数量（不大于100）：\n");
	scanf("%d",&t_n);
	int i;
	struct hotel hot[256];
	struct traveler peo[512]; 
	for(i=0;i<h_n;i++){
		printf("---录入第%d个房间的信息---\n",i+1);
		printf("房间标号：%d(已自动生成)\n",1000+i);
		hot[i].number=1000+i;
		printf("请输入当前房间容量（1-3）：\n");scanf("%d",&(hot[i].room_volume));getchar();
		hot[i].room_state=0;//默认没人住 
		printf("----------------------------------\n"); 
	}
	for(i=0;i<t_n;i++){
		printf("---第%d个旅客信息录入:---\n",i+1);
		printf("请输入旅客姓名(不能太长)：");gets(peo[i].name);
		printf("请输入旅客ID:");scanf("%lld",&(peo[i].ID));getchar();
		printf("----------------------------------\n");
	} 
	FILE *file;
	/*
	文件格式：
	文件的前4字节储存旅馆房间的数量，为整型数组直接从内存中转转储
	文件的5-8字节储存旅客的数量，亦为转储
	文件接下来的部分就分别是旅馆结构体的转储和旅客结构体的转储，大小由1-8字节内容定义 
	*/ 
	//h_n是旅馆的数量；t_n是旅客的数量
	char choose;
	printf("1 自定义数据文件名\n2 大家使用同一个文件名\n");
	choose=getchar();getchar();
	switch(choose){
		case '1':{
			char filename[513];
			printf("请输入文件名：\n");
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
