#include<stdio.h>
#include<stdlib.h>
#include<iostream>
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

int checkExp(char *a){
	struct Node *para=NULL;
	int i=0;
	while(a[i]!='\0'){
		if(a[i]=='(' or a[i]=='[' or a[i]=='{'){
			push(&para,a[i]);
		}
		else if(a[i]==')'){
			if(!para)return 0;
			else if(para->data=='('){pop(&para);}
		}
		else if(a[i]==']'){
			if(!para)return 0;
			else if(para->data=='['){pop(&para);}
			
		}
		else if(a[i]=='}'){
			if(!para)return 0;
			else if(para->data=='{'){pop(&para);}
		}
		i+=1;
	}
	if(!para)return 1;
	else return 0;
} 	
int main(){
	char *s="]{([({a+b})]*([c-d]))})";
	cout<<checkExp(s)<<endl;
		
}
