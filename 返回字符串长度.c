#include<stdio.h>
int getlength(char *p){
	int i;
	for(i=0;*(p+i)!='\0';i++);
	return i;
}
int main(){
	char st[256],*p=st;
	gets(st);
	printf("%d",getlength(p));
	return 0;
} 
