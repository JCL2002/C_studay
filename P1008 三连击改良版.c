#include<stdio.h>
int main(){
	int list[9]={1,2,3,4,5,6,7,8,9},a[9],i[9];
	int *pl=list,*pa=a,*pi=i;int depth=0;
	int any(int *p,int len,int find);
	int cycle(int *pl,int *pa,int *pi,int depth);
	cycle(pl,pa,pi,0);
//	printf("%d %d %d %d %d %d %d %d %d",a[0],a[1],a[2],a[3],a[4],a[5],a[6],a[7],a[8]);
	return 0;
}
int any(int *p,int len,int find){//遍历数组，若find在数组中存在返回零，否则返回一
	int i;
	for(i=0;i<len;i++){
		if(find==*(p+i)) return 0;
	}
	return 1;
}
int cycle(int *pl,int *pa,int *pi,int depth){
	if(depth==9){
		if((*(pa)*100+*(pa+1)*10+*(pa+2))*2==(*(pa+3)*100+*(pa+4)*10+*(pa+5))){
			if((*(pa)*100+*(pa+1)*10+*(pa+2))*3==(*(pa+6)*100+*(pa+7)*10+*(pa+8))){
				printf("%d %d %d\n",*(pa)*100+*(pa+1)*10+*(pa+2),*(pa+3)*100+*(pa+4)*10+*(pa+5),*(pa+6)*100+*(pa+7)*10+*(pa+8));
			}
		}
	}
	else{
		for(*(pi+depth)=0;*(pi+depth)<9;(*(pi+depth))++){
			if(any(pi,depth,*(pi+depth))){
				*(pa+depth)=*(pl+*(pi+depth));
				cycle(pl,pa,pi,depth+1);
			}
		}
	}
}
