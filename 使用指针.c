#include<stdio.h>
int main(){//������²������� 
	void len(char *p);
	char a[256];char *p=a;
	gets(a);
	len(a);
	return 0;
}
void len(char *p){
	int i=0;
	for(;*(p+i)!='\0';i++);
	printf("%d",i);
}
