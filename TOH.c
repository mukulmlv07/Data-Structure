#include<stdio.h>
void TOH(n,a,b,c){
	if(n>0){
		TOH(n-1,a,c,b);
		printf("Move %d from %d\n",a,c);
		TOH(n-1,b,a,c);
	}
}
void main(){
	TOH(16,1,2,3);
}
