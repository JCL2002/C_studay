#include<stdio.h>
int main(){
	int m;//m代表随机数个数
	int a[100];//数组a用来存放随机数
	int i,j;//i,j用于循环 
	scanf("%d",&m);
	for(i=0;i<m;i++){//随机数录入部分 
		scanf("%d",&a[i]);
	} 
	int b[100],b_len=0;//建立一个新的数组用于存放筛重之后的数组，b_len代表这个数组的长度
	int count;//count用于统计a[i]在b中出现的次数 
	for(i=0;i<m;i++){//遍历a数组 
		count=0;
		for(j=0;j<=b_len;j++){//统计a[i]在b中出现的次数
			if(a[i]==b[j]){
				count++;
			}
		}
		if(!count){
			b[b_len]=a[i];
			b_len++;
		}
		
	}
	//对数组b进行冒泡排序
	int tmp;//用于交换的临时变量 
	for(i=0;i<b_len-1;i++){//b_len的长度为b的实际长度
		for(j=0;j<b_len-i-1;j++){
			if(b[j]>b[j+1]){//按照从小到大的顺序排列 
				tmp=b[j];b[j]=b[j+1];b[j+1]=tmp;
			}
		}
	} 
	printf("%d\n",b_len);
	//输出数组b
	for(i=0;i<b_len-1;i++){//输出到数组b的倒数第二个元素就停下，因为最后一个后面不需要加空格 
		printf("%d ",b[i]);
	} 
	printf("%d",b[b_len-1]);
	return 0;
} 
