#include<stdio.h>
//归并排序_循环实现 
int list_dg[20000000];//待排序数组—递归 
int list[20000000];//待排序数组 
int cache[20000000];//缓冲数组 
void Merge (int *s, int *t, int l, int mid, int r){
	int i = l, j = mid + 1, c = l;
	while (i != mid + 1 && j != r + 1){
		if (s[i] < s[j])
			t[c++] = s[i++];
		else
			t[c++] = s[j++];
	}//比较队首元素
	while (i != mid + 1)
		t[c++] = s[i++];
	while (j != r + 1)
		t[c++] = s[j++];//处理剩余元素
		int k;
	for ( k = l; k <= r; ++k)
		s[k] = t[k];//覆盖原序列
}//治

void M_sort (int *s, int *t, int l, int r){
	if (l < r){
		int mid = (l + r) >> 1;
		M_sort(s, t, l, mid);
		M_sort(s, t, mid + 1, r);
		Merge(s, t, l, mid, r);
	}
}//分
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
	int n=20000000;int i;int step,n_copy=n,tmp;
	int ti_o,ti_m;//计时
	srand(time(NULL));
	for(i=0;i<20000000;i++){
		tmp=rand();
		list[i]=tmp;
		list_dg[i]=tmp;
	} 
	ti_o=time(NULL);
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
	ti_m=time(NULL);
	M_sort(list_dg,cache,0,20000000-1);
	printf("循环用时：%d秒\n递归用时：%d秒\n",ti_m-ti_o,time(NULL)-ti_m);
	for(i=0;i<20000000;i++){
		if(list[i]!=list_dg[i]){
			printf("两者排序结果不同");
			return 1;
		}
	}
	printf("经检查,两者排序结果相同");
	return 0;
}
