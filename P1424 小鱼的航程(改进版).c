#include<stdio.h>
int main(){
	int day,n,distance;
	scanf("%d %d",&day,&n);
	distance=(n/7)*250*5;
	int i;
	for(i=0;i<n%7;i++){//��������֮�����µ����� 
		if((day+i)%7<6&&(day+i)%7!=0){//�ڡ������ա� 
			distance+=250;
		}
	} 
	printf("%d",distance);
	return 0;
}
