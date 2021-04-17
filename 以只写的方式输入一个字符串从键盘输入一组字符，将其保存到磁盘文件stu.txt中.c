#include<stdio.h>
int main(){
	FILE *p;//定义文件的指针
	p=fopen("stu.txt","w"); //将指针指向文件
	char a[256];
	gets(a);//从键盘输入内容到a里
	while(a[0]!='#'){//当以一个元素为#结束 
		fputs(a,p);
		puts(a);
		gets(a);
	}
	fclose(p);
	return 0; 
}
