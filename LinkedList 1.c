
#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node *next;
}*first=NULL,*last=NULL;

void create(int A[],int n){
	struct Node *p;
	first=(struct Node *)malloc(sizeof(struct Node));
	first->data=A[0];
	first->next=NULL;
	last=first;
	int i;
	for(i=1;i<n;i++){
		p=(struct Node *)malloc(sizeof(struct Node));
		p->data=A[i];
		p->next=NULL;
		last->next=p;
		last=p;
	}
}

void Display(){
	struct Node *i=first;
	printf(" %u ",first);
	int index=0;
	while(i!=NULL){
		printf(" --->  | %d | %u |",i->data,i->next);
		i=i->next;
	}
	printf("\n%u %u",first,last);
}

void RDisplay(struct Node *p){
	if(p!=NULL){
		printf("%d ",p->data);
		RDisplay(p->next);
	}
}
int Count(struct Node *p){
	if(p==NULL){
		return 0;
	}
	return Count(p->next)+1;
}

int Sum(struct Node *p){
	static int sum=0;
	if(p!=NULL){
		sum+=p->data;
		Sum(p->next);
		//return Sum(p->next)+p->data;
	}
	//return 0;
	return sum;
}

struct Node* Search(int key){
	struct Node *i=first;
	struct Node *p=NULL;
	while(i!=NULL){
		if(i->data==key){
			if(p!=NULL){
				p->next=i->next;
				i->next=first;
				first=i;
			}
			return i;	
		}
		p=i;
		i=i->next;
	}
	return NULL;
}

void Append(int a){
	struct Node *p;
	if(first==NULL){
		first=(struct Node*)malloc(sizeof(struct Node));
		first->data=a;
		first->next=NULL;
		last=first;
	}
	else{
		p=(struct Node*)malloc(sizeof(struct Node));
		p->data=a;
		p->next=NULL;
		last->next=p;
		last=p;
	}
	
}

void Insert(int index,int a){
	if(index < 0 || index>Count(first)){
		printf("Failed\n");
		return ;
	}
	struct Node *p;
	p=(struct Node*)malloc(sizeof(struct Node));
	p->data=a;
	if(index==0){
		p->next=first;
		first=p;
		if(last==NULL){
			last=first;
		}
	}
	else{
		struct Node *in=first;
		int count=0;
		while(count<index-1){
			count++;
			in=in->next;
		}
		if(index==Count(first)){
			p->next=NULL;
			last=p;
		}
		p->next=in->next;
		in->next=p;
	}

	printf("Successfully Inserted\n");
	
}
int RMax(struct Node *p){
	static int max=-445645554;
	if(p==NULL){
		return max;
	}
	if(max<p->data){
		max=p->data;
	}
	return RMax(p->next);
}
int R2MAX(struct Node *p){
	int x;
	if(p==NULL){
		return -2721242;
	}
	else{
		x=R2MAX(p->next);
		if(x<p->data){
			return p->data;
		}
		else{
			return x;
		}
		
	}
}

void InsertINSort(int ele){
	if(first==NULL){
		Append(ele);
	}
	else{
		struct Node *p;
		p=(struct Node *)malloc(sizeof(struct Node));
		p->data=ele;
		if(ele>last->data){
			last->next=p;
			p->next=NULL;
			last=p;
		}
		else{
			struct Node *temp=first,*q=NULL;
			while(temp->data<ele){
				q=temp;
				temp=temp->next;
				
			}
			if(q==NULL){
				p->next=first;
				first=p;
			}
			else{
				p->next=q->next;
				q->next=p;
			}
		}
	}
	
}

void Delete(int pos){
	if(pos<0 || pos>Count(first)-1 ){
		printf("\nFAILED\n");
		return ;
	}
	
	if(pos==0){
		first=first->next;
		if(first==last){
			last=NULL; 
		}
	}
	else{
		struct Node *p=first,*q=NULL;
		int index=0;
		while(index!=pos){
			q=p;
			p=p->next;
			index++;
		}
		q->next=p->next;
		if(p==last){
			last=q;
		}
		free(p);
	}
	
}
int IsSorted(struct Node *p){
	int temp=INT_MIN;
	while(p!=NULL){
		if(p->data>temp){
			temp=p->data;
		}
		else{
			return 0;
		}
		p=p->next;
	}
	return 1;
	
}

void RemoveDuplicate(struct Node *p){
	struct Node *q=p->next;
	while(q!=NULL){
		if(p->data==q->data){
			if(q==last){
				last=p;
			}
			q=q->next;
			p->next=q;
			
		}
		else{
			p=p->next;
			q=q->next;
		}
	}
}
void RemoveDuplicateFromUnsorted(struct Node *p){
	int max=RMax(p);
	int A[max+1]={0};
	
}


void main(){
//	int x[]={1,2,3,4,5};
//	create(x,5);
//	Display();
//	printf("\n%u\n",Search(1));
	Insert(0,1);
	Insert(1,1);
	//Insert(1,1);
	Insert(2,3);
	Insert(3,4);
	Insert(4,4);
	Insert(5,5);
	Insert(6,6);
	Insert(7,6);
	Display();
	printf("\n\n");
	RemoveDuplicate(first);
	Display();
	//printf("\n%d\n",IsSorted(first));

}
