#include<stdio.h>
#include<stdlib.h>
int main(){
	unsigned long long size;
	char unit;
	scanf("%lld %c",&size,&unit);getchar();
	switch (unit){
		case 'B':{
			//�����κ��� 
			break;
		}
		case 'K':{
			size*=1024;
			break;
		}
		case 'M':{
			size*=1024;
			size*=1024;
			break;
		}
		case 'G':{
			size*=1024;
			size*=1024;
			size*=1024;
			break;
		}
		default:{
			printf("���鵥λ");
			exit(1);
		}
		
	}
	srand(time(NULL));
	long long i;char tmp;
	char file_name[513];
	gets(file_name);
	FILE *file;
	if((file=fopen(file_name,"wb"))==NULL){
		printf("�ļ�����ʧ��");
		exit(5);
	}
	long long j=0;
	long long percentage;
	percentage=size/100;
	for(i=0;i<size;i++){
		tmp=(char)((rand()+i)%256);
		fwrite(&tmp,1,1,file);
		if(i%percentage==0){
			printf("%d %%�����\n",i/percentage);
		}
	}
	printf("Done");
	fclose(file);
	getchar();
	return 0;
}
