#include<stdio.h>
#include<math.h>
struct term{
	int coef;
	int pow;
};
struct polynomial{
	int n;
	struct term *ele;
};
void create(struct polynomial *p){
	int i;
	printf("\nEnter no of terms\n");
	scanf("%d",&p->n);
	p->ele=(struct term *)malloc(p->n*sizeof(struct term));
	printf("\nEnter coef and pow one be one\n");
	for(i=0;i<p->n;i++){
		scanf("%d%d",&p->ele[i].coef,&p->ele[i].pow);
	}
}
void Display(struct polynomial p){
	int i;
	for(i=0;i<p.n;i++){
		printf("%dX^%d",p.ele[i].coef,p.ele[i].pow);
		if(i<p.n-1){
			printf(" + ");
		}
	}
	printf("\n");
	
}
int Evaluate(struct polynomial p,int x){
	int sum=0,i;
	for(i=0;i<p.n;i++){
		sum+=(p.ele[i].coef)*pow(x,p.ele[i].pow);
	}
	return sum;
}
struct polynomial Add(struct polynomial p1,struct polynomial p2){
	struct polynomial p;
	p.ele=(struct term *)malloc(p1.n+p2.n*sizeof(struct term));
	int i=0,j=0,index=0;
	while(i<p1.n && j<p2.n){
		if(p1.ele[i].pow==p2.ele[j].pow){
			p.ele[index].coef=p1.ele[i].coef+p2.ele[j].coef;
			p.ele[index].pow=p1.ele[i].pow;
			i++;
			j++;
		}
		else if(p1.ele[i].pow<p2.ele[j].pow){
			p.ele[index]=p1.ele[i];
			i++;
		}
		else{
			p.ele[index]=p2.ele[j];
			j++;
		}
		index++;
	}
	for(;i<p1.n;){
		p.ele[index++]=p1.ele[i++];
	}
	for(;j<p2.n;){
		p.ele[index++]=p2.ele[j++];
	}
	return p;
}

void main(){
	struct polynomial p1,p2;
	create(&p1);
	Display(p1);
	create(&p2);
	Display(p2);
	struct polynomial p3=Add(p1,p2);
	Display(p3);
}
	
	

