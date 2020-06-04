#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

class Node{
	public:
		int coeff;
		int exp;
		Node *next;
};


class Polynomial{
	private:
		Node *first=NULL;
	public:
		Polynomial();
		void Display();
		~Polynomial(){
			delete []first;
			first=NULL;
		}
};

Polynomial::Polynomial(){
	Node *last,*p;
	int temp,c,e;
	cout<<"\nEnter 1 for continuing Insert 0 for finish insert\n";
	cin>>temp;
	while(temp){
		cout<<"Enter coeff and power value:\n";
		cin>>c>>e;
		if(first==NULL){
			first=new Node;
			first->coeff=c;
			first->exp=e;
			first->next=NULL;
			last=first;
		}
		else{
			p=new Node;
			p->coeff=c;
			p->exp=e;
			p->next=NULL;
			last->next=p;
			last=p;
		}
		cout<<"\nEnter 1 for continuing Insert 0 for finish insert\n";
		cin>>temp;
	}
}

void Polynomial::Display(){
	struct Node *p=first;
	while(first!=NULL){
		cout<<p->coeff<<"X^"<<p->exp<<" ";
	}
	cout<<endl;
	p=p->next;	
}

int main(){
	Polynomial p1;
	p1.Display();
}
