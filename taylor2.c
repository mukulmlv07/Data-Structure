#include<stdio.h>
//ITERATIVE APPROACH
double e(double x , double n){
	double s=1;
	for(;n>0;n--){
		printf("%d\n",s);
		s=1+(x/n*s);
	}
	return s;
}
int main(){
	printf("%lf",e(2,10));
	
}
