#include<stdio.h>
#include<string.h>
int main(){
	char in[256];
	scanf("%s",&in);
	int len,i;
	len=strlen(in);
	int bn=0,gn=0;//统计boy和girl出现次数 
	for(i=0;i<len;i++){
		if(in[i]=='b'){
			bn++;
			if(len-i-1){//如果当前字符不是最后一个继续判断接下来的字符是不是o 
				if(in[i+1]=='o'){
					i++;
					if(len-i-1){//如果当前字符不是最后一个继续判断接下来的字符是不是y
						if(in[i+1]=='y'){
							i++;
						} 
					}
					continue;//防止后续再度统计
				} 
			}
		}
		if(in[i]=='g'){
			gn++;
			if(len-i-1){//如果当前字符不是最后一个继续判断接下来的字符是不是i
				if(in[i+1]=='i'){
					i++;
					if(len-i-1){
						if(in[i+1]=='r'){
							i++;
							if(len-i-1){
								if(in[i+1]=='l'){
									i++;
								}
							}
						}
					} 
					continue;//防止后续再度统计
				}
			}
		}
		if(in[i]=='o'){
			bn++;
			if(len-i-1){
				if(in[i+1]=='y'){
					i++;
					continue;
				}
			}
		}
		if(in[i]=='y') bn++;
		if(in[i]=='i'){
			gn++;
			if(len-i-1){
				if(in[i+1]=='r'){
					i++;
					if(len-i-1){
						if(in[i+1]=='l'){
							i++;
						}
					}
					continue;
				}
			}
		}
		if(in[i]=='r'){
			gn++;
			if(len-i-1){
				if(in[i+1]=='l'){
					i++;
					continue;
				}
			}
		}
		if(in[i]=='l'){
			gn++;
		}
	}
	printf("%d\n%d",bn,gn);
	return 0;
}
