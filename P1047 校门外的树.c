#include<stdio.h>
int main(){
	int l,m,u[100],v[100];//l代表道路长度，m代表区域数目，u、v分别代表起始和终止坐标
	scanf("%d %d",&l,&m);
	int i;//i用于循环
	for(i=0;i<m;i++){//区域录入 
		scanf("%d %d",&u[i],&v[i]);
	} 
	int a[10001];//如果对应区域被占用则在a的相应位置+1,最后统计哪些区域为零就可以了
	for(i=0;i<=l;i++){//初始化a[10001] 
		a[i]=0;
	}
	for(i=0;i<m;i++){//让u[i]~v[i]区域在a[10001]内标记 
		int j;
		for(j=u[i];j<=v[i];j++){//开始赋值 
			a[j]=1;
		}
	} 
	int count=0;//用于计数“1”在数组中出现的次数 
	for(i=0;i<=l;i++){//统计“1”出现次数 
		if(a[i]){
			count++;
		}
	}
	printf("%d",l-count+1);
	return 0;
}
