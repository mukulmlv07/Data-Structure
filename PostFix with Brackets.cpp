#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>
using namespace std;

struct Stack{
	int size;
	int top;
	char *stack;
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
	s->stack=(char *)calloc(s->size,sizeof(char));
	s->top=-1;
}

void Push(struct Stack *s,char val){
	if(IsFull(*s)){
		cout<<"\nSorry we cant insert inside stack as it is full\n";
	}
	else{
		s->stack[++(s->top)]=val;
		cout<<"\nSuccessfully Inserted\n";
	}
}

char Pop(struct Stack *s){
	char r;
	if(IsEmpty(*s)){
		cout<<"\nCant Pop Stack is already empty\n";
	}
	else{
		r=s->stack[s->top];
		s->stack[s->top--]=NULL;
		cout<<"\nSuccessfully Popped\n";
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

int outStack(char a){
	if(a=='+' or a=='-')return 1;
	if(a=='*' or a=='/')return 3;
	if(a=='^')return 6;
	if(a=='(')return 7;
	if(a==')')return 0;
}


int inStack(char a){
	if(a=='+' or a=='-')return 2;
	if(a=='*' or a=='/')return 4;
	if(a=='^')return 5;
	if(a=='(')return 0;
}

int PostFix(char *inf){
	char *post=new char[strlen(inf)+1];
	struct Stack s;
	Create(&s,strlen(inf));
	int i=0,j=0;
	while(inf[i]!='\0'){
		if(isOperand(inf[i])){
			post[j++]=inf[i++];
		}
		else{
			if(s.top=-1 or outStack(inf[i])>inStack(s.stack[s.top])){
				Push(&s,inf[i++]);
			}
			else if(outStack(inf[i])<inStack(s.stack[s.top])){
				post[j++]=Pop(&s);
			}
			else{
				Pop(&s);
				i++;
			}
		}
	}
	while(s.top!=-1){
		post[j++]=Pop(&s);
	}
	i=0;
	while(post[i]!=NULL){
		cout<<post[i++];
	}
	cout<<endl;
	
}


int main(){
	char *s="((a+b)*c)-d^e^f";
	PostFix(s);
}
