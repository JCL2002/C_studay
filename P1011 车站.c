#include<stdio.h>
int fb(int x){//斐波那契数列,输入x，返回第x项的值 
	int a=1,b=1,i;
	for(i=1;i<((x+1)/2);i++){
		a+=b;
		b+=a;
	}
	if(x%2){
		return a; 
	}
	else{
		return b;
	}
} 
long long sum(int start,int end){ 
	long long Sum=0;
	int i;
	for(i=start;i<=end;i++){
		Sum+=fb(i);
	}
	return Sum;
} 
int main(){
	int a,n_2,n,m,x;//a代表始发站上车人数，n_2代表第二站上车人数，n代表车站总数，m代表终点站下车人数，x代表所要求的车站号
	long long UP_a=0,UP_n_2=0,DOWN_a=0,DOWN_n_2=0; 
	scanf("%d %d %d %d",&a,&n,&m,&x);
	//最后一次下车人数等于总的上车人数之和减去总的下车人数之和 
	//初始值a确定而第二站上车人数不定，要设未知数，不能放在一起斐波那契，分开后各自遵循各自的斐波那契数列 
	if(n<4){//当次数小于三时情况一目了然且不规律 
		//上车：a,n_2,fb(1)*a+fb(2)*n_2
		//下车(假设不为最后一站)：0,n_2,n_2
		switch (n){
			case 1:{
				printf("0");
				break;
			}
			case 2:{
				n_2=0;
				printf("%d",a);
				break;
			}
			case 3:{
				printf("%d",a); 
				break;
			}
		}
	}
	else{
		//上车：2(a+n_2)+…
		//下车：2*n_2+…
		//对上车a求和
		//对上车n_2求和
		//对下车a求和
		//对下车n_2求和
		UP_a+=2;
		UP_n_2+=2;
		DOWN_n_2+=2;
		if(n!=4){//下车来的比上车迟 
			DOWN_n_2+=sum(2,n-3);
			DOWN_a+=sum(1,n-4);
			UP_a+=sum(2,n-3);
			UP_n_2+=sum(3,n-2);
		}
	}
	//a*UP_a+n_2*UP_n_2-a*DOWN_a-n_2*DOWN_n_2=m
	//即n_2=(m-a(UP_a-DOWN_a))/(UP_n_2-DOWN_n_2)
	n_2=(m-a*(UP_a-DOWN_a))/(UP_n_2-DOWN_n_2);//得到第二次上车人数
	//直接求第x次上车人数
	if(x<4){
		printf("%d",a);
	}
	else{
		long long UP=0,DOWN=0;//UP代表上车人数总和，DOWN代表下车人数总和
		//对a和n_2的上下次数计数 
		UP_a=0;UP_n_2=0;DOWN_a=0;DOWN_n_2=0;
		UP_a+=2;
		UP_n_2+=2;
		DOWN_n_2+=2;
		DOWN_n_2+=sum(2,x-2);
		DOWN_a+=sum(1,x-3);
		UP_a+=sum(2,x-2);
		UP_n_2+=sum(3,x-1);
		//计算UP和DOWN
		UP=a*UP_a+n_2*UP_n_2;
		DOWN=a*DOWN_a+n_2*DOWN_n_2;
		printf("%lld",UP-DOWN); 
		}
		
	return 0;
} 
