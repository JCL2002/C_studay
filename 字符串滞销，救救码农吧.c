#include<stdio.h>
#include<string.h>
int main(){
	char a[256],b[256];char *p_a=a,*p_b=b;
	gets(a);
	int i;
	for(i=0;i<strlen(a);i++){
		*(p_b+i)=*(p_a+i);
	}
	*(p_b+i)='\0';//末尾加上结束标志 
	puts(b);
	return 0;
}
