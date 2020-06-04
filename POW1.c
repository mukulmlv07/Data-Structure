#include<stdio.h>
int pow(int m ,int n){
	int a=1,i,temp=m;
	if(n%2==0){
		for(i=n;i>0;i=i/2){
			a=a*m;
			m=a;
		}
	}
	else{
			for(i=n-1;i>0;i=i/2){
			a=a*m;
			m=a;
		}
		a=a*temp;
	}
	return a;
	
}
void main(){
	printf("%d\n",pow(2,9));
	
}
