#include<stdio.h>
#include<string.h>
int main(){ 
	int te(char *p,int len);
	int abs(int a);
	char a[62501];//���ڴ�����������
	char tmp[26];//���ڴ����ʱ��ǰ������
	int i,j=0;//i��������tmp���±ꣻj��������a���±�
	do{//��tmp������ת�Ƶ�a������E��ֹͣ 
		gets(tmp);
		for(i=0;i<strlen(tmp);i++){
			a[j]=tmp[i];
			j++;
		} 
	}while(te(tmp,strlen(tmp)));
	a[j]='\0';//ĩβ���Ͻ�����־ 
	int w=0,f=0;i=0;//w����ʤ����win���Ĵ�����f�������˵Ĵ�����fail��;i����ʶ���ǲ���ǡ���������� 
	//��ʼ11���Ƶļ��� 
	for(j=0;a[j]!='E';j++){//ֻ��ѭ��������Eֱ��break 
		if(a[j]=='W'){
			w++;
		}
		else if(a[j]=='L'){//����ֱ����else����Ϊ���һ��Eû�б��ߵ� 
			f++;
		}
		i++;
		if((w>10||f>10)&&(abs(w-f)>=2)){//����11�� 
			printf("%d:%d\n",w,f);
			w=0;f=0;i=0;//һ�й��� 
		}
	} 
	if((!j||i)||j>10){//Ҫ�����ǲ�����ѭ����ǡ���������,,���ߵ�һ������E  (û�н���ѭ����j=0)
		printf("%d:%d\n",w,f); 
	}
	w=0;f=0;i=0;//Ϊ��һ����׼����i����ʶ���ǲ���ǡ���������� 
	printf("\n");
	for(j=0;a[j]!='E';j++){//ֻ��ѭ��������Eֱ��break 
		if(a[j]=='W'){
			w++;
		}
		else if(a[j]=='L'){//����ֱ����else����Ϊ���һ��Eû�б��ߵ� 
			f++;
		}
		i++;
		if((w>20||f>20)&&(abs(w-f)>=2)){//����21�� 
			printf("%d:%d\n",w,f);
			w=0;f=0;i=0;//һ�й��� 
		}
	} 
	if((!j||i)||j>20){//Ҫ�����ǲ�����ѭ����ǡ���������,���ߵ�һ������E (û�н���ѭ����j=0)
		printf("%d:%d\n",w,f);
	}
	return 0; 
}
int te(char *p,int len){//�����жϸ������Ƿ����E 
	int i;
	for(i=0;i<len;i++){
		if(*(p+i)=='E'){
			return 0;
		}
	}
	return 1;
}
int abs(int a){//�����ֵ 
	if(a>0){
		return a;
	}
	return -1*a;
}
