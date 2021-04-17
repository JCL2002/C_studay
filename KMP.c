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
	//next的计算
	if(!txt_len||!pat_len){
		return -1;
	}
	k[0]=0;k[1]=1;
	for(i=2;i<pat_len;i++){
		if(pat[i-1]==pat[k[i-1]-1]){//如果能够形成相等的前后缀 
			k[i]=k[i-1]+1;
		}
		else if(pat[i-1]==pat[0]){//无法继续构成相等前后缀，但与第一个元素能构成相等前后缀 
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
			else{//指向pat的第一个元素时 
				i++;
				continue;
			}
		}
		else{
			i++;j++;
			if(j==pat_len){//匹配成功 
				return i-pat_len+1;
			}
		}
	}
	return 0;
}
