#include<stdio.h>
#include<string.h>
int main(){
	char a[31];char *p=a;
	char new[31];char *p_new=new;
	gets(a);
	int m;
	scanf("%d",&m);
	//以上部分懂的都懂 
	int i,j;
	for(i=m-1,j=0;i<strlen(a);i++,j++){
		*(p_new+j)=*(p+i);//把m以后的部分赋值给new 
	}
	*(p_new+j)='\0';//末尾加上\0 
	if(m>strlen(a)){
		printf("你怕不是个der");
		return 250;
	}
	else{
		puts(new);
		return 0;
	}
}
