#include<stdio.h>
int main(){
	int N,i,day=1,day_max=1,temp,temp_y;
	scanf("%d",&N);
	for(i=0;i<N;i++){
		temp_y=temp;
		scanf("%d",&temp);
		if(i){
			if(temp>temp_y){
				day++;
			}
			else{
				if(day>day_max){
					day_max=day;
				}
				day=1;
			}
			if(i==N-1){
				if(day>day_max){
					day_max=day;
				}
			}
		}
	}
	printf("%d",day_max);
	return 0;
}
