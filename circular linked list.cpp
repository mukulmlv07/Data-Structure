#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
struct Node{
	int data;
	struct Node* next;
}*Head;

void create(int A[],int n){
	struct Node *last=NULL,*temp=NULL;
	Head=new struct Node;
	Head->data=A[0];
	Head->next=Head;
	last=Head;
	for(int i=1;i<n;i++){
		temp=new struct Node;
		temp->data=A[i];
		temp->next=Head;
		last->next=temp;
		last=temp;
	}	
}
void Display(struct Node *p){
	cout<<p<<" --> ";
	do{
		cout<<p->data<<" "<<p->next<<" --> ";
		p=p->next;
	}while(p!=Head);
	cout<<endl;
}

void Insert(int index,int e){
	struct Node *p=Head,*t; 
	t=new struct Node;
	t->data=e;
	if(index==0){
		while(p->next!=Head)
		{
			p=p->next;
		}
		p->next=t;
		t->next=Head;
		Head=t;
	}	
	else{	
		for(int i=1;i<index;i++){
			p=p->next;
		}
		t->next=p->next;
		p->next=t;
	}
	
}

void Delete(int index){
	struct Node* p=Head,*q;
	if(index==1){
		while(p->next!=Head){
			p=p->next;
		}
		if(p==Head){
			delete Head;
			Head=NULL;
		}
		else{
		p->next=Head->next;
		delete Head;
		Head=p->next;
		}
	}
	else{
		for(int i=1;i<index-1;i++)
		{
			p=p->next;	
		}
		q=p->next;
		p->next=q->next;
		delete q;
	}
}
int main(){
	int A[]={1,2,3,4,5};
	create(A,5);
	Insert(3,-1);
	Display(Head);
}


