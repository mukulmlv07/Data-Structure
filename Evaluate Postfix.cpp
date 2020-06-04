#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>
using namespace std;

struct Stack{
	int size;
	int top;
	int *stack;
};

int IsEmpty(struct Stack s){
	if(s.top==-1)return 1;
	return 0;
}

int IsFull(struct Stack s){
	if(s.top==s.size-1)return 1;
	return 0;
}

void Create(struct Stack *s,int sz){
	s->size=sz;
	s->stack=(int *)calloc(s->size,sizeof(int));
	s->top=-1;
}

void Push(struct Stack *s,int val){
	if(IsFull(*s)){
		cout<<"\nSorry we cant insert inside stack as it is full\n";
	}
	else{
		s->stack[++(s->top)]=val;
		//cout<<"\nSuccessfully Inserted\n";
	}
}

int Pop(struct Stack *s){
	int r;
	if(IsEmpty(*s)){
		cout<<"\nCant Pop Stack is already empty\n";
	}
	else{
		r=s->stack[s->top];
		s->stack[s->top--]=NULL;
		//cout<<"\nSuccessfully Popped\n";
	}
	return r;
}

void Traverse(struct Stack s){
	int sz=s.top;
	if(IsEmpty(s)){
		cout<<"\nStack is Empty\n";
	}
	else{
		cout<<"\n ___ \n";
		while(sz>-1){
			cout<<"| "<<s.stack[sz--]<<" |"<<"\n ___ \n";
		}
	}
}

int Peek(struct Stack s,int index){
	if(s.top-index+1<0){
		cout<<"\nInvalid Index\n";
		return NULL;
	}
	else{
		return s.stack[s.top-index+1];
	}
}
int isOperand(char a){
	if(a=='+' or a=='-' or a=='/' or a=='*' or a=='^' or a=='(' or a==')')return 0;
	return 1;
} 

int Evaluate(char *post){
	struct Stack s;
	Create(&s,strlen(post));
	for(int i=0;i<post[i]!='\0';i++){
		if(isOperand(post[i])){
			Push(&s,post[i]-'0');
		}
		else{
			int b=Pop(&s),a=Pop(&s),c;
			switch(post[i]){
				case '+':c=a+b;Push(&s,c);break;
				case '-':c=a-b;Push(&s,c);break;
				case '*':c=a*b;Push(&s,c);break;
				case '/':c=a/b;Push(&s,c);break;
			}
		}
	}
	return Pop(&s);
	
}	 

int main(){
	char *s="35*62/+4-";
	cout<<Evaluate(s);
}
