#include<stdio.h>
struct date{
	int mounth;
	int date;
	int value;
};
int main(){
	struct date day[365],tmp;
	int i=0;
	while(1){// ‰»Î≤ø∑÷ 
		scanf("%d %d",&(tmp.mounth),&(tmp.date));
		tmp.value=tmp.mounth*100+tmp.date;
		if(tmp.value==0){
			break;
		}
		day[i]=tmp;
		i++;
	}
	int j,k;
	for(j=0;j<i-1;j++){//√∞≈›≈≈–Ú 
		for(k=0;k<i-1-j;k++){
			if(day[k].value>day[k+1].value){
				tmp=day[k];day[k]=day[k+1];day[k+1]=tmp;
			}
		}
	}
	for(j=0;j<i;j++){
		printf("%d %d\n",day[j].mounth,day[j].date);
	}
	return 0;
}
