#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<windows.h>

unsigned int size,level;//size表示窗口的大小，level代表贪吃蛇移动的速度
int screen[100][100];//储存屏幕内容,x代表行；y代表列

unsigned int length=0;//蛇当前的长度
unsigned int head[2];//蛇头位置,head[0]代表行;head[1]代表列

char food='F';//事物是否存在
char direction='d';//方向

void snake_init(){//初始化贪吃蛇
	unsigned int x,y;
	for(x=0;x<size;x++){
		for(y=0;y<size;y++){
			screen[x][y]=0;
		}
	}
}

void display_test(){//检测当前窗口是否足够容纳游戏
	printf("请确保屏幕完整的显示正方形框\n");
	unsigned int x,y;
	for(x=0;x<size;x++){
		for(y=0;y<size;y++){
			if(x==0||x==size-1){
				printf("# ");
			}
			else if(y==0||y==size-1){
				printf("# ");
			}
			else{
				printf("  ");
			}
		}
		printf("\n");
	}
}

void display(){//显示函数，显示贪吃蛇的位置
	unsigned int x,y;
	for(x=0;x<size;x++){
		for(y=0;y<size;y++){
			if(screen[x][y]){//不为空的时候
				if(screen[x][y]==-1){
					printf("* ");//食物
				}
				else if(screen[x][y]==length){//蛇头
					printf("@ ");
				}
				else{
					printf("# ");//蛇体
				}
			}
			else{
				printf("  ");
			}
		}
		printf("\n");//换行
	}
}

void food_gen(){//生成食物
	unsigned int x,y;
	while(1){
		x=rand()%size;
		y=rand()%size;
		if(screen[x][y]==0){//在没有蛇存在的地方生成食物
			//缺陷：当蛇越来越长时，需要尝试的次数越来越多，可能造成卡顿
			//改进方法：将空白的地方的位置存到一个结构体数组里面，rand()%数组长  来决定在哪里生成
			screen[x][y]=-1;
			food='T';
			return;
		}
	}
}

int move(){//返回1代表蛇死亡，返回0代表正常进行
	unsigned int x,y;
	switch (direction) {
		case 'w':{//向上走
			if(head[0]==0){//撞墙而死
				return 1;
			}
			else if(screen[head[0]-1][head[1]]>0){//自爆了
				return 1;
			}
			else{
				if(screen[head[0]-1][head[1]]==-1){//吃到食物
					length++;
					food='F';//食物被吃掉
					screen[head[0]-1][head[1]]=length;//食物点变成头
					head[0]--;//头往上走
					return 0;
				}
				
				for(x=0;x<size;x++){
					for(y=0;y<size;y++){
						if(screen[x][y]>0){
							screen[x][y]--;//当长度为0时该点不再属于蛇
						}
					}
				}
				screen[head[0]-1][head[1]]=length;//前进点变成头
				head[0]--;
			}
			break;
		}
		case 'a':{
			if(head[1]==0){//撞墙而死
				return 1;
			}
			else if(screen[head[0]][head[1]-1]>0){//自爆
				return 1;
			}
			else{
				if(screen[head[0]][head[1]-1]==-1){//吃到食物
					length++;
					food='F';//食物被吃掉
					screen[head[0]][head[1]-1]=length;
					head[1]--;//头往左走
					return 0;
				}
				
				for(x=0;x<size;x++){
					for(y=0;y<size;y++){
						if(screen[x][y]>0){
							screen[x][y]--;//当长度为0时该点不再属于蛇
						}
					}
				}
				screen[head[0]][head[1]-1]=length;
				head[1]--;
			}
			break;
		}
		case 's':{
			if(head[0]==size-1){//撞墙而死
				return 1;
			}
			else if(screen[head[0]+1][head[1]]>0){//自爆
				return 1;
			}
			else{
				if(screen[head[0]+1][head[1]]==-1){//吃到食物
					length++;
					food='F';//食物被吃掉
					screen[head[0]+1][head[1]]=length;
					head[0]++;//头往下走
					return 0;
				}
				
				for(x=0;x<size;x++){
					for(y=0;y<size;y++){
						if(screen[x][y]>0){
							screen[x][y]--;//当长度为0时该点不再属于蛇
						}
					}
				}
				screen[head[0]+1][head[1]]=length;
				head[0]++;
			}
			break;
		}
		case 'd':{
			if(head[1]==size-1){//撞墙而死
				return 1;
			}
			else if(screen[head[0]][head[1]+1]>0){//自爆
				return 1;
			}
			else{
				if(screen[head[0]][head[1]+1]==-1){//吃到食物
					length++;
					food='F';//食物被吃掉
					screen[head[0]][head[1]+1]=length;
					head[1]++;
					return 0;
				}
				
				for(x=0;x<size;x++){
					for(y=0;y<size;y++){
						if(screen[x][y]>0){
							screen[x][y]--;//当长度为0时该点不再属于蛇
						}
					}
				}
				screen[head[0]][head[1]+1]=length;
				head[1]++;
			}
			break;
		}
		
	}
	return 0;
}



int main(){
	char input;
	srand(time(NULL));
	printf("请分别输入窗口的大小(10-30)和速度(1-10),空格隔开\n推荐20 5 \n");
	scanf("%d %d",&size,&level);
	if(size<10||size>30||level<1||level>10){
		printf("所以你觉得为什么游戏不开始？");
		getchar();getchar();
		return 1;
	}
	display_test();
	//初始化
	printf("wasd控制方向\n按回车开始");
	getchar();getchar();//第一个吃回车，第二个等待
	snake_init();
	screen[0][0]=1;screen[0][1]=2;head[0]=0;head[1]=1;length=2;direction='d';
	while(1){
		if(food=='F'){
			food_gen();
		}
		display();
		Sleep(1100-100*level);
		if(kbhit()){//如果有键盘输入
			input=getch();//得到键盘输入
			if(input=='w'&&direction!='s'){
				direction=input;
			}
			else if(input=='a'&&direction!='d'){
				direction=input;
			}
			else if(input=='s'&&direction!='w'){
				direction=input;
			}
			else if(input=='d'&&direction!='a'){
				direction=input;
			}
		}
		if(move()){
			system("cls");
			printf("得分:%d",length);
			getchar();getchar();
			break;
		}
		system("cls");
	}
	return 0;
}