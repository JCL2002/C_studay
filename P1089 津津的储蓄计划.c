#include<stdio.h>
int main(){
	int spend[12];//用于存放每个月津津的花销
	int i;//i用于循环计数
	for(i=0;i<12;i++){//数据输入
		scanf("%d",&spend[i]);
	}
	int carry=0;//定义当月津津手中有多少钱
	int give=0;//定义上交到妈妈手里的钱的数量
	for(i=0;i<12;i++){//1-12月逐月计算
		carry+=300;//每个月妈妈给300元
		carry-=spend[i];//花钱
		if(carry<0){//钱到月底不够花
			printf("-%d",i+1);
			break;
		}
		else{
			if(carry/100){//剩的钱比100块多，就往妈妈那里存钱
				give+=(carry/100)*100;
				carry-=(carry/100)*100;
			}
		}
	}
	if(carry>=0){//判断是否iu需要计算
		carry+=(give+give/5);//按照20%返还
		printf("%d",carry);
	}
	return 0;
}
