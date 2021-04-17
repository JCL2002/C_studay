#include<stdio.h>
int main(){
	FILE *p;
	if ((p=fopen("./stu.txt","r"))==NULL){
		printf("打不开文件");
	}
	char str1[256];
	int i=1;//i用于计数
	str1[0]=fgetc(p);
	while(!feof(p)){
		str1[i]=fgetc(p);
		i++;
	} 
	str1[i]='\0';
	puts(str1);
	fclose(p);
	return 0;
}
