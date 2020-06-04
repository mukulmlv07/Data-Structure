#include<stdio.h>
#include<stdlib.h>
struct element{
	int i;
	int j;
	int x;
};

struct sparse{
	int row;
	int column;
	int num;
	struct element *e;
};

void create(struct sparse *s){
	int z;
	printf("\nEnter no of rows and columns respectively\n");
	scanf("%d%d",&s->row,&s->column);
	printf("\nEnter no of non zero elements\n");
	scanf("%d",&s->num);
	s->e=(struct element * )calloc(s->num,sizeof(struct element));
	printf("\nInsert Elements\nEnter Row, Column number and Element Respectively\n");
	for(z=0;z<s->num;z++){
		scanf("%d%d%d",&s->e[z].i,&s->e[z].j,&s->e[z].x);
	}
}
void Display(struct sparse s){
	int z;
	printf("%d %d %d",s.row,s.column,s.num);
	for(z=0;z<s.num;z++){
		printf("%d %d %d\n",s.e[z].i,s.e[z].j,s.e[z].x);
	}
}

void main(){
	struct sparse s1;
	create(&s1)
}
