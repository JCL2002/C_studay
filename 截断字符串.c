#include<stdio.h>
#include<string.h>
int main(){
	char a[31];char *p=a;
	char new[31];char *p_new=new;
	gets(a);
	int m;
	scanf("%d",&m);
	//���ϲ��ֶ��Ķ��� 
	int i,j;
	for(i=m-1,j=0;i<strlen(a);i++,j++){
		*(p_new+j)=*(p+i);//��m�Ժ�Ĳ��ָ�ֵ��new 
	}
	*(p_new+j)='\0';//ĩβ����\0 
	if(m>strlen(a)){
		printf("���²��Ǹ�der");
		return 250;
	}
	else{
		puts(new);
		return 0;
	}
}
