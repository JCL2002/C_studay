#include<stdio.h>
#include<string.h>
int main(){
	int tst(char *p); 
	char a[256][6];char (*p)[6]=a;
	int i=0;char tmp[6];
	gets(tmp);
	while(tst(tmp)){//��������ʱ�Ͱ�tmp���Ƶ�a�� 
		strcpy(*(p+i),tmp);
		gets(tmp);
		i++;
	}
	//����̨�Ƚ�
//	printf("����a�ĵ�2���ǣ�%s",a[1]);//һ��������� 
	char max[6];
	strcpy(max,*(p));//����һ�и���max
	int j;
	for(j=1;j<i;j++){//i�б��������a������ 
		if(strcmp(*(p+j),max)>0){
			strcpy(max,*(p+j));
		} 
	} 
	puts(max);
}
int tst(char *p){//�ж��ַ����ǲ���"*****" ,�ǵĻ�����0�����򷵻�1 
	int i=0;
	while(i<5){
		if(*(p+i)!='*'){
			return 1;
		}
		i++;
	} 
	return 0;
}
