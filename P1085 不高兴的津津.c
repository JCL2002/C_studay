#include<stdio.h>
int main(){
    int arrange[7][2];
    int i;//i用于循环
    for(i=0;i<7;i++){//输入本周的安排
        scanf("%d %d",&arrange[i][0],&arrange[i][1]);
        }
    int max=arrange[0][0]+arrange[0][1];//打擂台查找最大值
    for(i=0;i<7;i++){
    	if((arrange[i][0]+arrange[i][1])>max){
    		max=arrange[i][0]+arrange[i][1];
    	}
    }
    if(max<=8){
    	printf("0");
    }
    else {//遍历数组，看最大值在哪
    	for(i=0;i<7;i++){
    		if(max==arrange[i][0]+arrange[i][1]){
    			printf("%d",i+1);
    			break;
    		}
    	}
    }
    return 0;
}
