#include<stdio.h>
#include<stdlib.h>
struct LTMatrix{
	int dim;
	int n;
	int *M;
};
void Set(struct LTMatrix *p,int i,int j,int v){
	if(i>=j){
		int index=((p->n)*j)-((j*(j-1))/2)+i-j;
		p->M[index]=v;	
	}
}
int Get(struct LTMatrix p,int i,int j){
	if(i>=j){
		int index=((p.n)*j)-((j*(j-1))/2)+i-j;
		return p.M[index];
	}
	return 0;
}
void Display(struct LTMatrix l){
	int i,j;
	for(i=0;i<l.dim;i++){
		for(j=0;j<l.dim;j++){
			if(i>=j){
				int index=((p*n)*j)-((j*(j-1))/2)+i-j;
				printf("%d ",l.M[index]);
			}
			else{
				printf("%d ",0);
			}
		}
		printf("\n");
	}
}


void main(){
	struct LTMatrix m1;
	int temp;
	printf("Enter Dieminsion of Matrix:\n");
	scanf("%d",&m1.dim);
	m1.n=(m1.dim*(m1.dim+1))/2;
	m1.M=(int *)calloc((m1.n),sizeof(int));
	Set(&m1,0,0,2);
	Set(&m1,3,3,5);
	Set(&m1,2,2,6);
	Display(m1);
	printf("%d\n",Get(m1,3,3));
	printf("%d\n",Get(m1,2,2));
	printf("%d\n",Get(m1,2,3));
}
