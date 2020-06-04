#include<stdio.h>

void main(){
	int A[10]={2,3,3,3,11,11,12,14,14,16};
	int i,diff=A[0];
	int duplicate=0;
//	for(i=0;i<10;i++){
//		if(A[i]==A[i+1] && A[i]!=duplicate){
//			printf("%d\n",A[i]);
//			duplicate=A[i];
//		}
//	}
	for(i=0;i<10;i++){
		printf("i2  %d\n",i);
		if(A[i]==A[i+1] && A[i]!=duplicate){
			printf("%d\n",A[i]);
			int j=i;
			while(A[j]==A[i]){
				j++;
			}
			i=j-1;
		
		}
	}
	
}
