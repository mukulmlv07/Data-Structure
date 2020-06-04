#include<stdio.h>
//ITERATIVE APPROACH
double e(int x , int n){
	double p=1,f=1;
	double i,s=0;
	for(i=0;i<n+1;i++){
		s=s+p/f;
		p=p*x;
		f=f*(i+1);
	}
	return s;
}
double main(){
	printf("%lf",e(2,10));
	
}
