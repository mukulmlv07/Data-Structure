#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>
using namespace std;
struct Node{
	char data;
	struct Node* next;
};
void push(struct Node **top,char ele){
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
int isOperand(char a){
	if(a=='+' || a=='-' || a=='/' || a=='*')return 0;
	else return 1;
}
int pre(char a){
	if(a=='+' || a=='-')return 1;
	else if(a=='*' || a=='/')return 2;
	return 0;
}
void IntoPostFix(char *exp){
	char *postfix;
	postfix=new char[strlen(exp)+1];
	struct Node *s=NULL;
	int i=0,index=0;
	while(exp[i]!='\0'){
		if(isOperand(exp[i])){
			postfix[index++]=exp[i++];
		}
		else{
			if(!s or pre(exp[i])>pre(s->data)){
				push(&s,exp[i++]);
			}
			else{
				postfix[index++]=s->data;
				pop(&s);
			}
		}	
	}
	while(s!=NULL){
		postfix[index++]=s->data;
		s=s->next;
	}
	postfix[index]='\0';
	i=0;
	while(postfix[i]!='\0'){
		cout<<postfix[i++];
	}
	
}
int main(){
	//char *s="]{([({a+b})]*([c-d]))})";
	char *s="a+f/g*h+b*c-d/e";
	IntoPostFix(s);	
}
