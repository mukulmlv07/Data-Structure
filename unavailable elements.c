#include<stdio.h>

void main(){
	int A[10]={1,2,3,4,6,10,11,12,14,16};
	int i,diff=A[0];
	for(i=0;i<10;i++){
		if(A[i]-i!=diff){
			while(diff< A[i]-i){
				printf("%d\n",diff+i);
				diff++;
			}
		}
	}
}
