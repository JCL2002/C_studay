#include<stdio.h>
int main(){
	int n,i;
	int list[10000];
	scanf("%d",&n);
	for(i=0;i<n*n;i++){
		scanf("%d",&(list[i]));
	}
	int a[10]={0,0,0,0,0,0,0,0,0,0};int tmp;
	for(i=0;i<n*n;i++){
		tmp=list[i];
		switch(tmp){
			case 0:{
				a[0]+=1;
				break;
			}
			case 1:{
				a[1]+=1;
				break;
			}
			case 2:{
				a[2]+=1;
				break;
			}
			case 3:{
				a[3]+=1;
				break;
			}
			case 4:{
				a[4]+=1;
				break;
			}
			case 5:{
				a[5]+=1;
				break;
			}
			case 6:{
				a[6]+=1;
				break;
			}
			case 7:{
				a[7]+=1;
				break;
			}
			case 8:{
				a[8]+=1;
				break;
			}
			case 9:{
				a[9]+=1;
				break;
			}
		}
	}
	printf("%d-%d-%d-%d-%d-%d-%d-%d-%d-%d",a[0],a[1],a[2],a[3],a[4],a[5],a[6],a[7],a[8],a[9]);
	return 0;
}
