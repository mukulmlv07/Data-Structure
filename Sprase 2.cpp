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
	int row;
	int column;
	struct Node **sparse;
};

void create(struct Sparse *A){
	int row,column;
	cout<<"Enter ROw and Columns\n";
	cin>>A->row>>A->column;
	A->sparse=new struct Node*[A->row];
	int temp,col,val;
	struct Node *last,*p;
	for(int i=0;i<A->row;i++){
		A->sparse[i]=NULL;
		do{
			cout<<"\n1 for insert in "<<i<<"th index 0 for next index\n";
			cin>>temp;
			if(temp){
				cout<<"\nEnter COl and Value:\n";
				cin>>col>>val;
				if(A->sparse[i]==NULL){
					A->sparse[i]=new struct Node;
					A->sparse[i]->col=col;
					A->sparse[i]->val=val;
					last=A->sparse[i];
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
void Display(struct Sparse A){
	struct Node *p;
	for(int i=0;i<A.row;i++){
		p=A.sparse[i];
		for(int j=0;j<A.column;j++){
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
	cout<<endl;
}
void Append(struct Node **s,struct Node *p){
	static struct Node *last=NULL;
	if(*s==NULL){
		*s=p;
		last=p;
	}
	else{
		last->next=p;
		last=p;
	}
}


struct Sparse * Add(struct Sparse s1,struct Sparse s2){
	struct Sparse *s;
	struct Node *temp1,*temp2,*p,*last;
	s=new struct Sparse;
	s->row=s1.row;
	s->column=s1.column;
	s->sparse=new struct Node*[s->row];
	for(int i=0;i<s->row;i++){
		s->sparse[i]=NULL;
		temp1=s1.sparse[i];
		temp2=s2.sparse[i];
		while(temp1!=NULL && temp2!=NULL){
			p=new struct Node;
			if(temp1->col==temp2->col){
				p->col=temp1->col;
				p->val=temp1->val+temp2->val;
				p->next=NULL;
				temp1=temp1->next;
				temp2=temp2->next;
			}
			else if(temp1->col<temp2->col){
				p->col=temp1->col;
				p->val=temp1->val;
				p->next=NULL;
				temp1=temp1->next;
			}
			else{
				p->col=temp2->col;
				p->val=temp2->val;
				p->next=NULL;
				temp2=temp2->next;
			}
			
			Append(&(s->sparse[i]),p);
		}
		while(temp1){
			Append(&(s->sparse[i]),temp1);
			temp1=temp1->next;
		}
		while(temp2){
			Append(&(s->sparse[i]),temp2);;
			temp2=temp2->next;
		}
		
	}
	return s;
	
}

int main(){
	
	struct Sparse s1,s2;			
	create(&s1);
	create(&s2);
	Display(s1);
	Display(s2);
	struct Sparse *s3=Add(s1,s2);
	Display(*s3);
}
