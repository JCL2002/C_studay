#include<stdio.h>
int main(){
	FILE *p;//�����ļ���ָ��
	p=fopen("stu.txt","w"); //��ָ��ָ���ļ�
	char a[256];
	gets(a);//�Ӽ����������ݵ�a��
	while(a[0]!='#'){//����һ��Ԫ��Ϊ#���� 
		fputs(a,p);
		puts(a);
		gets(a);
	}
	fclose(p);
	return 0; 
}
