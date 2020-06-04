#include<iostream>
using namespace std;
class Diagonal{
	private:
		int n ;
		int *A;
	public:
		Diagonal(){
			this->n=2;
			A=new int[2]{0};
		}
		Diagonal(int n){
			this->n=n;
			A=new int[n]{0};	
		}
	void fillDiagonal(int *p);
	void set(int i , int j,int e);
	int get(int i,int j);
	void display();
	~Diagonal(){
		delete []A;
	}
};

void Diagonal::fillDiagonal(int *p){
	int i;
	for(i=0;i<n;i++){
		A[i]=p[i];
	}
}
void Diagonal::set(int i,int j,int e){
	if(i==j){
		A[i]=e;
	}
}
int Diagonal::get(int i,int j){
	if(i==j){
		return A[i];
	}
	return 0;
}
void Diagonal::display(){
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(i==j){
				cout<<A[i]<<" ";
			}
			else{
				cout<<0<<" ";
			}
		}
		cout<<endl;
	}
	cout<<endl<<endl<<endl;
}

int main(){
	Diagonal d1(5);
	int a[]={1,2,3,4,5};
	d1.fillDiagonal(a);
	d1.display();
	d1.set(2,2,-1);
	d1.display();
	cout<<d1.get(2,2);
}


