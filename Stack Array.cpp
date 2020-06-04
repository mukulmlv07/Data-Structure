#include<stdio.h>
#include<stdlib.h>
#include<iostream>
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
		cout<<"\nSuccessfully Inserted\n";
	}
}

void Pop(struct Stack *s){
	if(IsEmpty(*s)){
		cout<<"\nCant Pop Stack is already empty\n";
	}
	else{
		s->stack[s->top--]=NULL;
		cout<<"\nSuccessfully Popped\n";
	}
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
int main(){
	struct Stack s1;
	Create(&s1,5);
	Push(&s1,1);
	Push(&s1,2);
	Push(&s1,3);
	Push(&s1,4);
	Push(&s1,5);
//	Pop(&s1);
//	Pop(&s1);
//	Pop(&s1);
//	Pop(&s1);
//	Pop(&s1);
//	Pop(&s1);
//	Pop(&s1);
	cout<<Peek(s1,6);
	Traverse(s1);
}
