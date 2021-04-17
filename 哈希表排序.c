#include<stdio.h>
int list[1000000];
int hash[100];
int main(){
	srand(time(NULL));
	unsigned int i;
	for(i=0;i<1000000;i++){
		list[i]=rand()%100;
		hash[list[i]]++;
	}
	unsigned int j,k=0;
	for(j=0;j<100;j++){
		for(i=0;i<hash[j];i++){
			list[k]=j;
			k++;
		}
	}
	
	return 0;
}
