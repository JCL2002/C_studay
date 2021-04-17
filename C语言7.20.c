#include<stdio.h>
int main(){
	int cpy(char *a,char *b);
	char a[101],b[101],*pa=a,*pb=b;
	gets(a);gets(b);
	printf("%d\n",cpy(pa,pb));
	return 0;
}
int cpy(char *a,char *b){
	int i;
	for(i=0;i<101;i++){ 
		if((*(a+i)!=*(b+i))||(*(a+i)=='\0')||(*(b+i)=='\0')){//当遇到不相等或者结束标志时返回值 
			return *(a+i)-*(b+i);
		}
	} 
	return 0;	
}
