#include<stdio.h>

int main(){
	float total,in,time;
	printf("请输入本金和存款期限:");
	scanf("%f %f",&in,&time);
	if(time<1){
		total=in+0.0275*in;
	}
	else{//只有当time大于1时才进行判断，不然其他条件不会匹配，会匹配到default上
		int time_int=(int)time;//强制类型转化
		switch (time_int){
			case 1:{
				total=(1+0.0275)*in;
				break;
			}//这个括号不能丢
			case 2:{
				total=(1+0.0335)*in;
				break;
			}
			case 3:{
				total=(1+0.04)*in;
				break;
			}
			case 4:{//总不能不让人家存吧
				total=(1+0.04)*in;
				break;
			}
			case 5:{
				total=(1+0.0475)*in;
				break;
			}
			default:{
				printf("期限错误");
				return 0;//直接结束程序
				break;
			}
		}
	}
	printf("%f",total);
	return 0;
}