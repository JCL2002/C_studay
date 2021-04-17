#include<stdio.h>
#include<string.h>
int main(){ 
	int te(char *p,int len);
	int abs(int a);
	char a[62501];//用于存放输入的数组
	char tmp[26];//用于存放临时当前行输入
	int i,j=0;//i用作数组tmp的下标；j用作数组a的下标
	do{//把tmp的内容转移到a，遇到E则停止 
		gets(tmp);
		for(i=0;i<strlen(tmp);i++){
			a[j]=tmp[i];
			j++;
		} 
	}while(te(tmp,strlen(tmp)));
	a[j]='\0';//末尾加上结束标志 
	int w=0,f=0;i=0;//w代表胜利（win）的次数；f代表输了的次数（fail）;i用于识别是不是恰好整场打完 
	//开始11分制的计算 
	for(j=0;a[j]!='E';j++){//只管循环，遇到E直接break 
		if(a[j]=='W'){
			w++;
		}
		else if(a[j]=='L'){//不能直接用else，因为最后一个E没有被踢掉 
			f++;
		}
		i++;
		if((w>10||f>10)&&(abs(w-f)>=2)){//打满11轮 
			printf("%d:%d\n",w,f);
			w=0;f=0;i=0;//一切归零 
		}
	} 
	if((!j||i)||j>10){//要考虑是不是在循环中恰好输出完了,,或者第一个就是E  (没有进行循环，j=0)
		printf("%d:%d\n",w,f); 
	}
	w=0;f=0;i=0;//为下一轮做准备，i用于识别是不是恰好整场打完 
	printf("\n");
	for(j=0;a[j]!='E';j++){//只管循环，遇到E直接break 
		if(a[j]=='W'){
			w++;
		}
		else if(a[j]=='L'){//不能直接用else，因为最后一个E没有被踢掉 
			f++;
		}
		i++;
		if((w>20||f>20)&&(abs(w-f)>=2)){//打满21轮 
			printf("%d:%d\n",w,f);
			w=0;f=0;i=0;//一切归零 
		}
	} 
	if((!j||i)||j>20){//要考虑是不是在循环中恰好输出完了,或者第一个就是E (没有进行循环，j=0)
		printf("%d:%d\n",w,f);
	}
	return 0; 
}
int te(char *p,int len){//用于判断该行中是否存在E 
	int i;
	for(i=0;i<len;i++){
		if(*(p+i)=='E'){
			return 0;
		}
	}
	return 1;
}
int abs(int a){//求绝对值 
	if(a>0){
		return a;
	}
	return -1*a;
}
