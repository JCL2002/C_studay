#include<stdio.h>
#include<string.h>
struct Trump {
	char name[33];//ѡԱ����
	int support;//Ʊ�� 
};
int main(){
	struct Trump T1,T2,T3;
	T1.support=0;T2.support=0;T3.support=0;
	gets(T1.name);gets(T2.name);gets(T3.name);
	char sup[33];
	int i;
	for(i=0;i<5;i++){//Ʊ���ۼ� 
		scanf("%s",sup);
		if(charequal(sup,T1.name)){
			T1.support++;
		}
		else if(charequal(sup,T2.name)){
			T2.support++;
		}
		else if(charequal(sup,T3.name)){
			T3.support++;
		}
	}
	char win[33];int max;
	strcpy(win,T1.name);max=T1.support;
	if(T2.support>max){
		strcpy(win,T2.name);max=T2.support;
	}
	if(T3.support>max){
		strcpy(win,T3.name);max=T3.support;
	}
	puts(win);
	return 0;
}
int charequal(char *p1,char *p2){//�ж��ַ����Ƿ���� 
	int i;
	if(strlen(p1)!=strlen(p2)){
		return 0;
	}
	for(i=0;i<strlen(p1);i++){
		if(*(p1+i)!=*(p2+i)){
			return 0;
		}
	}
	return 1;
}
