#include<stdio.h>

int list1[1000000];
int list2[1000000];
int list3[1000000];
int list4[1000000];
char bit[32];

int main(){
	unsigned int sum=0;
	int i,j,n,k=0,N;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		list1[i]=1;
		list3[i]=1;
	}
	N=n;
	do{//由小到大合并
		if(k%2){
			for(i=0,j=0;i<N-1;i++){
				if(list1[i]==list1[i+1]){
					sum++;
					list2[j]=2*list1[i];
					i++;
					j++;
				}
				else{
					list2[j]=list1[i];
					j++;
				}
			}
		}
		else{
			for(i=0,j=0;i<N-1;i++){
				if(list2[i]==list2[i+1]){
					sum++;
					list1[j]=2*list2[i];
					i++;
					j++;
				}
				else{
					list1[j]=list2[i];
					j++;
				}
			}
		}
		k++;
		N=j;
	}while(1);
	
	
	return 0;
}