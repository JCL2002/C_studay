#include<stdio.h>
int main(){
	char a[256];
	int getlen(char a[]);
	gets(a);
	printf("%d",getlen(a));
	return 0;
}
int getlen(char a[]){//Çó×Ö·û´®³¤¶È 
	int i=0;
	while(a[i]!='\0'){
		i++;
	} 
	return i;
}
