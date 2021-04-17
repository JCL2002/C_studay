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
		printf("���ܱ�0����");
		exit(1);
	}
	else{
		return a/b;
	}
}
double read(char *p,int *i,int len){
	double operation(char *p,int len);
	//len������󳤶� 
	double a=0;char current;
	double base=1;double flt=1;//base�����������ֵļ��㣻flt����С������ļ��� 
	char dote='F';//С������
	int dote_number=0;//С�����λ�� 
	int i_o=*(i);//����;������"("����ֱ�ӵ��� 
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
		else if(current=='.'&&dote=='T'){//�ж��С���� 
			printf("��������,���С����");
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
			printf("��������",current);
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
	int num_left=0;//�����Ÿ���
	for(i=0;i<len;i++){//�������� 
		if(*(p+i)=='('){//����������,���µݹ�
			num_left++;
			int i_ori=i;
			while(num_left){//��ʼ����ƥ�� 
				i++;
				if(i>=len){//ƥ�䲻��������
					printf("��������"); 
					exit(1);
				}
				else if(*(p+i)=='(') num_left++;
				else if(*(p+i)==')') num_left--;
			}
		}//�ų����������+ 
		if(*(p+i)=='+'||*(p+i)=='-') iteam++;
	}//����ͨ��
	
	double *cache=(double *)malloc(iteam*double_size);//�С�iteam�������һ�������Ŀռ������cache
	char *symbol=(char *)malloc(iteam*sizeof(char));//�ֱ��¼��ÿ����֮�������
	for(i=0;i<iteam;i++){//��Ĭ��ֵ��0����ֹ����++++����� 
		cache[i]=0;
	}
	
	int head=0;//ÿ�����ͷ
	for(i=0;i<len;i++){//ÿ��ݹ飬ʹ����������ǵ���ʽ 
		if(*(p+i)=='('){
			num_left++;//num_left��ʼֵһ����0
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
			head=i+1;//�����³���+++++����� 
		}
		if(i==len-1&&head!=0){
			cache[k]=operation(p+head,i-head+1);//�������һ�� 
			k++;
		}
	}//����ͨ�� 
	
	//��ǰ��ĵݹ鱣֤�������ܵ�����ֻʣ�µ�����һ����ſ���һ�
	double recive=1;
	if(iteam==1){//��Ϊ����ʽʱ�Ž��м��� 
		//����ʽ���� 
		for(i=0;i<len;){//�����������Ž��еݹ飬�˳������㣬�ڳ˳�������������������Ž��еݹ�
			cache[0]=1;//������˵ķ�ʽ���У������1+1����2+2�������
			if(*(p+i)=='('){//����������,���µݹ�
				num_left++;
				int i_ori=i;
				while(num_left){//��ʼ����ƥ��
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
		return recive;//����ʽֱ�ӷ���cache[0] 
	}
	//��������Ҫ������ۻ� 
	
	double a=cache[0];
	for(i=1;i<iteam;i++){
		if(symbol[i]=='+'){
			a+=cache[i];
		}
		else{
			a-=cache[i];
		}
	}
	//�ڴ��ͷ� 
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
				printf("��������");
				return 1;
			}
		} 
	}
	if(k){
		printf("��������-main");
		return 1;
	}
	printf("%f",operation(input,strlen(input))); 
	return 0;
}
