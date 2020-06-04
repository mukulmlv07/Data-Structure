#include<stdio.h>
#include<iostream>
#include<stdlib.h>
using namespace std;
struct Node{
	struct Node *prew;
	int data;
	struct Node *next;
}*first=NULL;
void create(int A[],int n){
	struct Node *p,*last;
	first=new struct Node;
	first->data=A[0];
	first->prew=NULL;
	first->next=NULL;
	last=first;
	for(int i=1;i<n;i++){
		p=new struct Node;
		p->data=A[i];
		p->prew=last;
		p->next=last->next;
		last->next=p;
		last=p;
	}
}

void Insert(int index,int e){
	struct Node *p=new struct Node;
	struct Node *t=first;
	p->data=e;
	if(index==0){
		if(first==NULL){
			first=p;
			first->prew=NULL;
			first->next=NULL;
		}
		else{	
			p->prew=NULL;
			p->next=first;
			first->prew=p;
			first=p;
		}
	}
	else{
		for(int i=1;i<index;i++){
			t=t->next;
		}
//		if(t->next==NULL){
//			p->prew=t;
//			p->next=NULL;
//			t->next=p;
//		}
//		else{
			p->prew=t;
			p->next=t->next;
			if(t->next)t->next->prew=p;
			t->next=p;
//		}
	}
}

void Delete(int index){
	struct Node *t;
	if(index==1){
		t=first->next;
		delete first;
		if(t)t->prew=NULL;
		first=t;
	}
	else{
		t=first;
		for(int i=1;i<index;i++){
			t=t->next;
		}
		t->prew->next=t->next;
		if(t->next)t->next->prew=t->prew;
		delete t;
	}	
	
}
void Display(struct Node *p){
	cout<<p<<" --> ";
	while(p!=NULL){
		cout<<p->prew<<" | "<<p->data<<" | "<<p->next<<" --> ";
		p=p->next;
	}
	cout<<endl;
}

void Reverse(struct Node *p){
	struct Node *temp=NULL;
	while(p!=NULL){
		if(p->next==NULL)first=p;
		temp=p->next;
		p->next=p->prew;
		p->prew=temp;
		p=p->prew;
	}
	
}
int main(){
	int A[]={1,2};
	create(A,2);
//	Insert(5,-1);
	Display(first);
	Reverse(first);
	Display(first);
}
