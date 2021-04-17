#include<stdio.h>
#include<string.h>
int main(){
	int tst(char *p); 
	char a[256][6];char (*p)[6]=a;
	int i=0;char tmp[6];
	gets(tmp);
	while(tst(tmp)){//当不结束时就把tmp复制到a里 
		strcpy(*(p+i),tmp);
		gets(tmp);
		i++;
	}
	//打擂台比较
//	printf("数组a的第2行是：%s",a[1]);//一条调试语句 
	char max[6];
	strcpy(max,*(p));//将第一行赋给max
	int j;
	for(j=1;j<i;j++){//i中保存的正是a的行数 
		if(strcmp(*(p+j),max)>0){
			strcpy(max,*(p+j));
		} 
	} 
	puts(max);
}
int tst(char *p){//判断字符串是不是"*****" ,是的话返回0；否则返回1 
	int i=0;
	while(i<5){
		if(*(p+i)!='*'){
			return 1;
		}
		i++;
	} 
	return 0;
}
