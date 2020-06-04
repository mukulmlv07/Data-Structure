#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

struct Node {
	int col;
	int val;
	struct Node *next;
};

struct Sparse{
	int r;
	int c;
	struct Node *A[r];
};
void create(struct Node *A[],int r){
	int temp,col,val;
	struct Node *last,*p;
	for(int i=0;i<r;i++){
		A[i]=NULL;
		do{
			cout<<"\n1 for insert in "<<i<<"th index 0 for next index\n";
			cin>>temp;
			if(temp){
				cout<<"\nEnter COl and Value:\n";
				cin>>col>>val;
				if(A[i]==NULL){
					A[i]=new struct Node;
					A[i]->col=col;
					A[i]->val=val;
					last=A[i];
					last->next=NULL;	
				}
				else{
					p=new struct Node;
					p->col=col;
					p->val=val;
					last->next=p;
					last=p;
					last->next=NULL;
				}
			}
		}while(temp);
	}
}
void Display(struct Node *B[],int r,int s){
	struct Node *p;
	for(int i=0;i<r;i++){
		p=B[i];
		for(int j=0;j<s;j++){
			if(p!=NULL && p->col==j){
				cout<<" "<<p->val<<" ";
				p=p->next;
			}
			else{
				cout<<" "<<0<<" ";
			}
		}
		cout<<endl;
	}
}

int main(){
	int row,column;
				
	struct Node *A[row];
	create(A,row); 
	Display(A,row,column);
}
