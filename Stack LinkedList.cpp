#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

struct Node{
	int data;
	struct Node* next;
};

void push(struct Node **top,int ele){
	struct Node *temp;
	temp=new Node;
	if(temp==NULL){
		cout<<"\nHeap Is Full can't push more\n";
		return;
	}
	temp->data=ele;
	temp->next=*top;
	*top=temp;
}

void pop(struct Node **top){
	if(*top==NULL){
		cout<<"\nCan't Pop\n";
	}
	else{
		struct Node *temp=*top;
		*top=(*top)->next;
		free(temp);
	}
}



void traverse(struct Node *top){
	cout<<"\n ___ \n";
	while(top!=NULL){
		cout<<"| "<<top->data<<" |"<<"\n ___ \n";
		top=top->next;
	}
}

int peek(struct Node *top,int index){
	for(int i=0;i<index-1;i++){
		top=top->next;
		if(top==NULL){
			cout<<"\nInvalid Index\n";
			return NULL;
		}
	}
	return top->data;
}

int main(){
	struct Node *s1=NULL;
	push(&s1,1);push(&s1,2);push(&s1,3);push(&s1,4);push(&s1,5);
		
//	for(int i=0;i<1000;i++){
//		push(&s1,i);
//	}
//	pop(&s1);pop(&s1);pop(&s1);pop(&s1);pop(&s1);
	traverse(s1);
}
