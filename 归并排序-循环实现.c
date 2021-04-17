#include<stdio.h>
//归并排序_循环实现 
int list[1000000];//带排序数组 
int cache[1000000];//缓冲数组 
void conquer(int head,int mid,int end){//治 
	int p1,p2,p3;//p1指向第一段；p2指向第二段；p3指向cache
	p1=head;p2=mid;p3=head;
	while(1){//向cache中读 
		if(p1<mid){//p1没有达到末尾 
			if(p2<end){//p2也没有达到末尾 
				if(list[p1]>list[p2]){
					cache[p3]=list[p2];//把比较小的读入缓冲cache
					p3++;p2++;//“指针”后移 
				}
				else{
					cache[p3]=list[p1];//把比较小的读入缓冲cache
					p3++;p1++;//“指针”后移
				}
			}
			else{//p1没有结束，但是p2结束 
				cache[p3]=list[p1];
				p3++;p1++;
			}
		}
		else{//p1结束 
			if(p2<end){//p1结束但是p2没有结束 
				cache[p3]=list[p2];
				p3++;p2++;
				
			}
			else{//p1、p2都结束 
				break;//跳出循环 
			}
		}
	}
	//数据回读
	for(p1=head;p1<end;head++){
		list[p1]=cache[p1];p1++;
	} 
} 
int main(){
	int n;
	printf("请输入待排序数字个数（<=1000）: ");scanf("%d",&n);
	int i;
	if(n>1000000){
		printf("数据太多");return 1;
	}
	for(i=0;i<n;i++){//录入 
		scanf("%d",&list[i]);
	}
	int step,n_copy=n;
	for(i=1;n_copy;n_copy/=2,i*=2){//分 
		step=0;
		while(1){
			if(step+2*i>n){//判断当前一组能不能和下一组等大合并 
				if(step+i<n){//继续判断剩下的是不是一整组且有一个剩余（一整组） 
					conquer(step,step+i,n);
					break;
				}
				break;
			}
			else{
				conquer(step,step+i,step+2*i);
				step+=2*i;
			}
		}
		
	}
	for(i=0;i<n;i++){
		printf("%d ",list[i]);
	}
	return 0;
}
