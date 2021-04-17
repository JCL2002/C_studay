#include<stdio.h>
#include<stdlib.h>

struct stack{
	char type;//数据类型
	/*
	f:float
	d:double
	i:int
	l:long long
	*/ 
	int i;
	long long l;
	float f;
	double d;
	struct stack *before; 
	struct stack *next;
};

struct stack *head=NULL;

int number=0;

void push(struct stack element){
	struct stack *temp=(struct stack *)malloc(sizeof(struct stack));
	*temp=element;
	if(head==NULL){
		head=temp;
		head->before=NULL;
	}
	else{
		head->next=temp;
		temp->before=head;
	}
	temp->next=NULL;
	head=temp;
	number++;
	return ;
}

struct stack  pop(){
	if(head==NULL){
		printf("栈已空！\n");
		return ;
	}
	struct stack temp,*cache,*Free;
	temp=*head;
	Free=head;
	cache=head->before;head=cache;
	free(Free);
	number--;
	return temp;
}

int main(){
	
	return 0;
}
