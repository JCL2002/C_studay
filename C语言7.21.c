#include<stdio.h>
#include<string.h>
int main(){
	char s1[101],s2[101];char *p1=s1,*p2=s2;
	int i;
	gets(s1);gets(s2);//Â¼Èë²¿·Ö 
	for(i=0;i<strlen(s2);i++){
		*(p1+i)=*(p2+i);
	}
	*(p1+i)='\0';
	puts(s1);
	return 0;
}
