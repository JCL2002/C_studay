#include<stdio.h>
//归并排序-冒泡排序时间比较 
int list[1000000];//带排序数组 
int cache[1000000];//缓冲数组 
int list_mp[1000000];;//冒泡的数组 
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
	int i,n,j,swap;
	printf("请输入数据量:");
	scanf("%d",&n); 
	for(i=0;i<n;i++){
		list[i]=rand();
	}
	int ti_o=time(NULL);
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
//	for(i=0;i<n;i++){
//		printf("%d ",list[i]);
//	}
	int ti_gui=time(NULL);//归并的时间
	//冒泡排序 
	for(i=0;i<n;i++){
		for(j=0;j<n-i-1;j++){
			if(list_mp[j]>list_mp[j+1]){
				swap=list_mp[j+1];
				list_mp[j+1]=list_mp[j];
				list_mp[j]=swap;
			}
		}
	}
	int ti_mp=time(NULL);
	printf("归并耗时：%d秒\n冒泡耗时：%d秒",ti_gui-ti_o,ti_mp-ti_gui);
	return 0;
}
