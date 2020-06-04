#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
using namespace std;

class Node{
	public:
		int coeff;
		int exp;
		Node *next;
};
class polynomial{
	private:
		Node *first=NULL;
	public:
		polynomial();
		void Display();
		int Evaluate(int x);
		~polynomial(){
			delete []first;
			first=NULL;
		}
};

polynomial::polynomial(){
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

void polynomial::Display(){
	struct Node *p=first;
	while(p!=NULL){
		cout<<p->coeff<<"X^"<<p->exp<<" ";
		p=p->next;
	}
	cout<<endl;	
}

int polynomial::Evaluate(int x){
	int ans=0;
	struct Node *temp=first;
	while(temp!=NULL){
		ans+=temp->coeff*(int)pow(x,temp->exp);
		temp=temp->next;
	}
	return ans;
}
int main(){
	polynomial p1;
	p1.Display();
	cout<<p1.Evaluate(2);
}
