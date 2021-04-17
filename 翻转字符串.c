#include<stdio.h>
#include<string.h>
int main(){
	void turn(char *p,int n);
	char s[256];char *p=s;
	gets(s);
	turn(p,strlen(s));
	puts(s);
	return 0;
}
void turn(char *p,int n){//n代表字符串长度 
	int i;char tmp;
	for(i=0;i<(n+1)/2;i++){
		tmp=*(p+i);
		*(p+i)=*(p+n-i-1);
		*(p+n-i-1)=tmp;
	}
}
