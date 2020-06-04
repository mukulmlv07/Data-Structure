#include<stdio.h>
void main(){
	int A[10]={5,5,5,5,5,5,5,5,5,9};
	int B[10]={0};
	int sum,i,j,count=0;
	for(i=0;i<10;i++){
		sum=10-A[i];
		if(B[sum]){
			
			for(j=0;j<B[sum];j++){
				count++;
			printf("%d %d\n",A[i],sum);
			}
		}
		B[A[i]]++;
		
	}
	printf("%d",count);
}
