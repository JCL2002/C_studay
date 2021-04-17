#include<stdio.h>
#include<string.h>
int main(){
	char a[10001];//给足列表长度
	gets(a);//录入字符串 
	int length,i,zheng=0,fu=0;
	length=strlen(a);//求字符串长度
	//分别统计升序、降序的次数
	for(i=0;i<length-1;i++){
		if(a[i]<=a[i+1]){
			zheng++;//升序次数统计 
		}
		else if(a[i]>=a[i+1]){
			fu++;//降序次数统计
		}
	}
	if(length-1==zheng){
			printf("Positive elegance");
		}
		else if(length-1==fu){
			printf("Negative elegance");
		}
		else{
			printf("Non elegance");
		}
	return 0; 
}
