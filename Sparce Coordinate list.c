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
	printf("%d %d %d\n",s.row,s.column,s.num);
	for(z=0;z<s.num;z++){
		printf("%d %d %d\n",(s.e+z)->i,s.e[z].j,s.e[z].x);
	}
	
}
struct sparse *Add(struct sparse p1,struct sparse p2){
	struct sparse *s;
	int size=p1.num+p2.num;
	s->e=(struct element *)calloc(size,sizeof(struct element));
	if(p1.row!=p2.row && p1.column!=p2.column){
		return NULL;
	}
	int y=0;
	int z=0;
	int index=0;
	
	while(y<p1.num && z<p2.num){
		
		if(p1.e[y].i==p2.e[z].i){
			if(p1.e[y].j==p2.e[z].j){
				s->e[index].i=p1.e[y].i;
				s->e[index].j=p1.e[y].j;
				s->e[index].x=p1.e[y].x+p2.e[z].x;
				y++;
				z++;
			}
			else if(p1.e[y].j<p2.e[z].j){
//				s->e[index].i=p1.e[y].i;
//				s->e[index].j=p1.e[y].j;
//				s->e[index].x=p1.e[y].x;
				s->e[index]=p1.e[y];
				y++;
			}
			else{
//				s->e[index].i=p2.e[z].i;
//				s->e[index].j=p2.e[z].j;
//				s->e[index].x=p2.e[z].x;
				s->e[index]=p2.e[z];
				z++;
			}
		}
		else if(p1.e[y].i<p2.e[z].i){
//			s->e[index].i=p1.e[y].i;
//			s->e[index].j=p1.e[y].j;
//			s->e[index].x=p1.e[y].x;	
			s->e[index]=p1.e[y];
			y++;
		}
		else{
//			s->e[index].i=p2.e[z].i;
//			s->e[index].j=p2.e[z].j;
//			s->e[index].x=p2.e[z].x;
			s->e[index]=p2.e[z];
			z++;
		}
		index++;
	}
	for(;y<p1.num;y++){
//		s->e[index].i=p1.e[y].i;
//		s->e[index].j=p1.e[y].j;
//		s->e[index].x=p1.e[y].x;p
		s->e[index]=p1.e[y];
		y++;
		index++;
	}
	for(;z<p2.num;z++){
//		s->e[index].i=p2.e[z].i;
//		s->e[index].j=p2.e[z].j;
//		s->e[index].x=p2.e[z].x;
		s->e[index]=p2.e[z];
		z++;
		index++;
	} 
	s->column=p1.column;
	s->row=p1.row;
	s->num=index;
	return s;
	
}

void main(){
	struct sparse s1;
	create(&s1);
	struct sparse s2;
	create(&s2);
	struct sparse *s3=Add(s1,s2);
	Display(*s3);
}
