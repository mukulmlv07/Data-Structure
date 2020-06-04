#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node *next;
}*first=NULL,*second=NULL,*third=NULL;

struct Node * Create(struct Node *p,int A[],int n){
	struct Node *last, *temp;
	p=(struct Node *)malloc(sizeof(struct Node));
	p->data=A[0];
	p->next=NULL;
	last=p;
	int i;
	for(i=1;i<n;i++){
		temp=(struct Node *)malloc(sizeof(struct Node));
		temp->data=A[i];
		temp->next=NULL;
		last->next=temp;
		last=temp;
	}
	return p;
}
void Display(struct Node *p){
	printf("| %d | --->",p);
	while(p!=NULL){
		printf("| %d | %d | -->    ",p->data,p->next);
		p=p->next;
	}
	printf("\n\n");
}

void concatinate(struct Node *p1,struct Node *p2){
	while(p1->next!=NULL){
		p1=p1->next;
	}
	p1->next=p2;
}
void merge(struct Node *p1,struct Node *p2){ 
	struct Node *p3=third,*temp;
	while(p1!=NULL && p2!=NULL){
		if(p1->data<p2->data){
			temp=p1;
			p1=p1->next;
		}
		else{
			temp=p2;
			p2=p2->next;
		}
		temp->next=NULL;
		if(third==NULL){
			third=temp;
			p3=third;
		}
		else{
			p3->next=temp;
			p3=p3->next;
		}
	}
	if(p1){
		p3->next=p1;
	}
	if(p2){
		p3->next=p2;
	}
}

int isLoop(struct Node *p){
	struct Node *r=p,*s=p;
	do{
		r=r->next;
		s=s->next;
		if(s==NULL){
			break;
		}
		s=s->next;
	}while(r&&s && r!=s);
	if(r==NULL or s==NULL ){
		return 0;
	}
	else{
		return 0;
	}
}

int main(){
	int A[]={};
	int B[]={2};
	first=Create(first,B,1);
	Display(first);
	printf("%d",isLoop(first));
}
