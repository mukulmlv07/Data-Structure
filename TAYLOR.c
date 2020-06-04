#include<stdio.h>
//RECURSIVE APPROACH
double e(double x, double n){
	static double s=1;
	if(n==0){
		return s;
	}
	s=1+(x/n)*s;
	return e(x,n-1);
}
double main(){
	printf("%lf",e(2,10));
	
}
