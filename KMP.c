#include<stdio.h>
#include<string.h>
char txt[1048577];
char pat[1048577];
unsigned int k[1048577];
int main(){
	gets(txt);gets(pat);
	int txt_len=strlen(txt);
	int pat_len=strlen(pat);
	int i,j=0;
	//next�ļ���
	if(!txt_len||!pat_len){
		return -1;
	}
	k[0]=0;k[1]=1;
	for(i=2;i<pat_len;i++){
		if(pat[i-1]==pat[k[i-1]-1]){//����ܹ��γ���ȵ�ǰ��׺ 
			k[i]=k[i-1]+1;
		}
		else if(pat[i-1]==pat[0]){//�޷������������ǰ��׺�������һ��Ԫ���ܹ������ǰ��׺ 
			k[i]=2;
		}
		else{
			k[i]=1;
		}
	}
	for(i=0;i<txt_len;){
		if(txt[i]!=pat[j]){
			if(k[j]){
				j=k[j]-1;
			}
			else{//ָ��pat�ĵ�һ��Ԫ��ʱ 
				i++;
				continue;
			}
		}
		else{
			i++;j++;
			if(j==pat_len){//ƥ��ɹ� 
				return i-pat_len+1;
			}
		}
	}
	return 0;
}
