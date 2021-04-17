#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#define double_size sizeof(double)
char input[2048];

double d_mul(double a,double b){
	return a*b;
}

double d_div(double a,double b){
	if(b==0){
		printf("不能被0除！");
		exit(1);
	}
	else{
		return a/b;
	}
}
double read(char *p,int *i,int len){
	double operation(char *p,int len);
	//len代表最大长度 
	double a=0;char current;
	double base=1;double flt=1;//base用于整数部分的计算；flt用于小树方面的计算 
	char dote='F';//小数点标记
	int dote_number=0;//小数点后位数 
	int i_o=*(i);//若在途中遇到"("不能直接调用 
	while(1){
		if(*(i)>=len) break;
		current=*(p+*(i));
		if(current<='9'&&current>='0'&&dote=='F'){ 
			a*=10;
			a+=(double)(current-'0');
		}
		else if(current<='9'&&current>='0'&&dote=='T'){
			a*=10;
			a+=(double)(current-'0');
			dote_number++;
		}
		else if(current=='.'&&dote=='F'){
			dote='T';
		}
		else if(current=='.'&&dote=='T'){//有多个小数点 
			printf("输入有误,多个小数点");
			exit(1);
		}
		else if(current=='/'||current=='*'){
			break;
		}
		else if(current=='('&&*(i)==i_o){
			int num_left=0;
			if(*(p+*(i))=='('){
				num_left++;
				int i_ori=*(i);
				while(num_left){
					*i=*i+1;
					if(*(p+*(i))=='(') num_left++;
					else if(*(p+*(i))==')') num_left--;
				}
				*i=*i+1;
				return operation(p+i_ori+1,*(i)-i_ori-2);
			}
			break;
		}
		else if(current=='('&&*(i)!=i_o){
			break;
		}
		else{
			printf("输入有误",current);
			exit(1);
		}
		*i=*i+1;
	}
	int j;
	for(j=0;j<dote_number;j++){
		a/=10;
	}
	return a;
}

double operation(char *p,int len){
	int i,j=1,k=0;int iteam=1;
	int num_left=0;//左括号个数
	for(i=0;i<len;i++){//划分项数 
		if(*(p+i)=='('){//遇到左括号,向下递归
			num_left++;
			int i_ori=i;
			while(num_left){//开始括号匹配 
				i++;
				if(i>=len){//匹配不到右括号
					printf("输入有误"); 
					exit(1);
				}
				else if(*(p+i)=='(') num_left++;
				else if(*(p+i)==')') num_left--;
			}
		}//排除括号里面的+ 
		if(*(p+i)=='+'||*(p+i)=='-') iteam++;
	}//测试通过
	
	double *cache=(double *)malloc(iteam*double_size);//有‘iteam’项，分配一段连续的空间给数组cache
	char *symbol=(char *)malloc(iteam*sizeof(char));//分别记录下每两项之间的正负
	for(i=0;i<iteam;i++){//让默认值变0，防止出现++++等情况 
		cache[i]=0;
	}
	
	int head=0;//每个项的头
	for(i=0;i<len;i++){//每项递归，使接下来的项都是单项式 
		if(*(p+i)=='('){
			num_left++;//num_left初始值一定是0
			int i_ori=i;
			while(num_left){
				i++;
				if(*(p+i)=='(') num_left++;
				else if(*(p+i)==')') num_left--;
			}
		}
		if(*(p+i)=='+'||*(p+i)=='-'){
			if(*(p+i)=='+'){
				symbol[j]='+';
				j++;
			}
			else{
				symbol[j]='-';
				j++;
			}
			cache[k]=operation(p+head,i-head);k++;
			head=i+1;//不用怕出现+++++的情况 
		}
		if(i==len-1&&head!=0){
			cache[k]=operation(p+head,i-head+1);//加上最后一项 
			k++;
		}
	}//测试通过 
	
	//由前面的递归保证，程序跑到这里只剩下单独的一项（括号看作一项）
	double recive=1;
	if(iteam==1){//当为单项式时才进行计算 
		//单项式计算 
		for(i=0;i<len;){//接下来对括号进行递归，乘除法计算，在乘除法计算过程中遇到括号进行递归
			cache[0]=1;//采用相乘的方式进行，解决（1+1）（2+2）的情况
			if(*(p+i)=='('){//遇到左括号,向下递归
				num_left++;
				int i_ori=i;
				while(num_left){//开始括号匹配
					i++;
					if(*(p+i)=='(') num_left++;
					else if(*(p+i)==')') num_left--;
				}
				recive*=operation(p+i_ori+1,i-i_ori-1);
				i++;
			}
			else if(*(p+i)=='*'){
				i++;
				recive=d_mul(recive,read(p,&i,len));
			}
			else if(*(p+i)=='/'){
				i++;
				recive=d_div(recive,read(p,&i,len));
			}
			else{
				recive=read(p,&i,len);
			}
		} 
		return recive;//单项式直接返回cache[0] 
	}
	//接下来需要将结果累积 
	
	double a=cache[0];
	for(i=1;i<iteam;i++){
		if(symbol[i]=='+'){
			a+=cache[i];
		}
		else{
			a-=cache[i];
		}
	}
	//内存释放 
	free(cache);
	free(symbol);
	
	return a;
}

int main(char t){
	int i,k=0;char *p=input;
	scanf("%s",input);
	for(i=0;i<strlen(input);i++){
		if(*(p+i)=='(') k++;
		if(*(p+i)==')') k--;
		if(*(p+i)<'0'||*(p+i)>'9'){
			if(*(p+i)=='+'||*(p+i)=='-'||*(p+i)=='*'||*(p+i)=='/'||*(p+i)=='('||*(p+i)==')'||*(p+i)=='.'){
				continue;
			}
			else{
				printf("输入有误");
				return 1;
			}
		} 
	}
	if(k){
		printf("输入有误-main");
		return 1;
	}
	printf("%f",operation(input,strlen(input))); 
	return 0;
}
