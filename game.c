#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<windows.h>

unsigned int size,level;//size��ʾ���ڵĴ�С��level����̰�����ƶ����ٶ�
int screen[100][100];//������Ļ����,x�����У�y������

unsigned int length=0;//�ߵ�ǰ�ĳ���
unsigned int head[2];//��ͷλ��,head[0]������;head[1]������

char food='F';//�����Ƿ����
char direction='d';//����

void snake_init(){//��ʼ��̰����
	unsigned int x,y;
	for(x=0;x<size;x++){
		for(y=0;y<size;y++){
			screen[x][y]=0;
		}
	}
}

void display_test(){//��⵱ǰ�����Ƿ��㹻������Ϸ
	printf("��ȷ����Ļ��������ʾ�����ο�\n");
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

void display(){//��ʾ��������ʾ̰���ߵ�λ��
	unsigned int x,y;
	for(x=0;x<size;x++){
		for(y=0;y<size;y++){
			if(screen[x][y]){//��Ϊ�յ�ʱ��
				if(screen[x][y]==-1){
					printf("* ");//ʳ��
				}
				else if(screen[x][y]==length){//��ͷ
					printf("@ ");
				}
				else{
					printf("# ");//����
				}
			}
			else{
				printf("  ");
			}
		}
		printf("\n");//����
	}
}

void food_gen(){//����ʳ��
	unsigned int x,y;
	while(1){
		x=rand()%size;
		y=rand()%size;
		if(screen[x][y]==0){//��û���ߴ��ڵĵط�����ʳ��
			//ȱ�ݣ�����Խ��Խ��ʱ����Ҫ���ԵĴ���Խ��Խ�࣬������ɿ���
			//�Ľ����������հ׵ĵط���λ�ô浽һ���ṹ���������棬rand()%���鳤  ����������������
			screen[x][y]=-1;
			food='T';
			return;
		}
	}
}

int move(){//����1����������������0������������
	unsigned int x,y;
	switch (direction) {
		case 'w':{//������
			if(head[0]==0){//ײǽ����
				return 1;
			}
			else if(screen[head[0]-1][head[1]]>0){//�Ա���
				return 1;
			}
			else{
				if(screen[head[0]-1][head[1]]==-1){//�Ե�ʳ��
					length++;
					food='F';//ʳ�ﱻ�Ե�
					screen[head[0]-1][head[1]]=length;//ʳ�����ͷ
					head[0]--;//ͷ������
					return 0;
				}
				
				for(x=0;x<size;x++){
					for(y=0;y<size;y++){
						if(screen[x][y]>0){
							screen[x][y]--;//������Ϊ0ʱ�õ㲻��������
						}
					}
				}
				screen[head[0]-1][head[1]]=length;//ǰ������ͷ
				head[0]--;
			}
			break;
		}
		case 'a':{
			if(head[1]==0){//ײǽ����
				return 1;
			}
			else if(screen[head[0]][head[1]-1]>0){//�Ա�
				return 1;
			}
			else{
				if(screen[head[0]][head[1]-1]==-1){//�Ե�ʳ��
					length++;
					food='F';//ʳ�ﱻ�Ե�
					screen[head[0]][head[1]-1]=length;
					head[1]--;//ͷ������
					return 0;
				}
				
				for(x=0;x<size;x++){
					for(y=0;y<size;y++){
						if(screen[x][y]>0){
							screen[x][y]--;//������Ϊ0ʱ�õ㲻��������
						}
					}
				}
				screen[head[0]][head[1]-1]=length;
				head[1]--;
			}
			break;
		}
		case 's':{
			if(head[0]==size-1){//ײǽ����
				return 1;
			}
			else if(screen[head[0]+1][head[1]]>0){//�Ա�
				return 1;
			}
			else{
				if(screen[head[0]+1][head[1]]==-1){//�Ե�ʳ��
					length++;
					food='F';//ʳ�ﱻ�Ե�
					screen[head[0]+1][head[1]]=length;
					head[0]++;//ͷ������
					return 0;
				}
				
				for(x=0;x<size;x++){
					for(y=0;y<size;y++){
						if(screen[x][y]>0){
							screen[x][y]--;//������Ϊ0ʱ�õ㲻��������
						}
					}
				}
				screen[head[0]+1][head[1]]=length;
				head[0]++;
			}
			break;
		}
		case 'd':{
			if(head[1]==size-1){//ײǽ����
				return 1;
			}
			else if(screen[head[0]][head[1]+1]>0){//�Ա�
				return 1;
			}
			else{
				if(screen[head[0]][head[1]+1]==-1){//�Ե�ʳ��
					length++;
					food='F';//ʳ�ﱻ�Ե�
					screen[head[0]][head[1]+1]=length;
					head[1]++;
					return 0;
				}
				
				for(x=0;x<size;x++){
					for(y=0;y<size;y++){
						if(screen[x][y]>0){
							screen[x][y]--;//������Ϊ0ʱ�õ㲻��������
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
	printf("��ֱ����봰�ڵĴ�С(10-30)���ٶ�(1-10),�ո����\n�Ƽ�20 5 \n");
	scanf("%d %d",&size,&level);
	if(size<10||size>30||level<1||level>10){
		printf("���������Ϊʲô��Ϸ����ʼ��");
		getchar();getchar();
		return 1;
	}
	display_test();
	//��ʼ��
	printf("wasd���Ʒ���\n���س���ʼ");
	getchar();getchar();//��һ���Իس����ڶ����ȴ�
	snake_init();
	screen[0][0]=1;screen[0][1]=2;head[0]=0;head[1]=1;length=2;direction='d';
	while(1){
		if(food=='F'){
			food_gen();
		}
		display();
		Sleep(1100-100*level);
		if(kbhit()){//����м�������
			input=getch();//�õ���������
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
			printf("�÷�:%d",length);
			getchar();getchar();
			break;
		}
		system("cls");
	}
	return 0;
}