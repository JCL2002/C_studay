#include<stdio.h>
#include<string.h>
int main(){
	char input[12];
	scanf("%s",input);
	int len=strlen(input);
	int i,times=0;
	for(i=0;i<len/2;i++){
		if(input[i]=='('){
			if(input[len-i-1]==')') continue;
			else times++;
		}
		if(input[i]==')'){
			if(input[len-i-1]=='(') continue;
			else times++;
		}
		if(input[i]!=input[len-i-1]){
			times++;
		}
	}
	if(len%2){//ÆæÊýÇé¿ö 
		if(input[len/2]=='i'||input[len/2]=='w');
		else times++;
	}
	printf("%d",times);
	return 0;
}
