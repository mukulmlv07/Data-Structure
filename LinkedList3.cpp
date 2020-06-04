#include<iostream>
using namespace std;
class Node{
	public:
		int data;
		Node *next;
};
class LinkedList{
	private:
		Node *first;
		Node *last;
	public:
		LinkedList(){
			first=NULL;
			last=NULL;
		}
		LinkedList(int A[],int n);
		//~LinkedList();
		void Display();
		void Insert(int index,int ele);
		void Delete(int ele);
		int LinkedList::Length();
}; 

LinkedList::LinkedList(int A[],int n){
	Node *p;
	first=new Node;
	first->data=A[0];
	last=first;
	last->next=NULL;
	for(int i=1;i<n;i++){
		p=new Node;
		p->data=A[i];
		last->next=p;
		last=p;
		last->next=NULL;
	}
}
void LinkedList::Display(){
	Node *p=first;
	cout<<first<<" --> ";
	while(p!=NULL){
		cout<<p->data<<" | "<<p->next<<" --> ";
		p=p->next;
	}
	cout<<endl<<endl;
}

void LinkedList::Insert(int index,int a){
	if(index>Length() || index<0){return ;}
	Node *p=new Node;
	p->data=a;
	if(index==Length()){
		last->next=p;
		last=p;
		last->next=NULL:
	}
	else{
		Node *temp=fisrt;
		for(int i=0;i<index;i++){
			temp=temp->next;
		}
		p->next=temp->next;
		
		temp->next=p;
}

int LinkedList::Length()
{
	 Node *p=first;
	 int len=0;
	
	 while(p)
	 {
		 len++;
		 p=p->next;
	 }
	 return len;
}

int main(){
	int A[]={1,2,3,4,5};
	LinkedList l1(A,5);
	l1.Display();
}
