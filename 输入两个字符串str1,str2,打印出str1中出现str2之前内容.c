#include<stdio.h>
int main(){
	char str_1[20],str_2[20],*p1=str_1,*p2=str_2;int i,j;
	gets(str_1);gets(str_2);
	for(i=0;*(p1+i)!='\0';i++){
		int mark=1;
		for(j=0;*(p2+j)!='\0';j++){
			if(*(p1+i)==*(p2+j)){
				mark=0;
				break;
			}
			
		}
		if(mark){
				printf("%c",*(p1+i));
			}
	}
	return 0;
}
