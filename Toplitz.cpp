#include<iostream>
using namespace std;
class Toplitez{
	private:
		int dim;
		int n;
		int *A;
	public:
		Toplitez(){
			dim=2;
			n=2;
			A=new int[2]{0};
		}
		Toplitez(int n){
			dim=n;
			this->n=n;
			A=new int[dim+dim-1]{0};
		}
		void Display();
		void Set(int i,int j,int v);
		int Get(int i,int j);
		~Toplitez(){
			delete []A;
		}
};

void Toplitez::Display(){
	int i,j,index;
	for(i=0;i<dim;i++){
		for(j=0;j<dim;j++){
			if(i<=j){
				index=j-i;
			}
			else{
				index=dim-1+i-j;
			}
			cout<<A[index]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}
void Toplitez::Set(int i,int j,int v){
	int index;
	if(i<=j){
		index=j-i;
	}	
	else{
		index=dim-1+i-j;
	}
		A[index]=v;	
	
}

int Toplitez::Get(int i,int j){	
	int index;
	if(i<=j){
		index=j-i;
	}	
	else{
		index=dim-1+i-j;
	}
	return A[index];
}

int main(){
	Toplitez m1(10);
	m1.Display();
	m1.Set(0,0,1);
	m1.Set(0,1,2);
	m1.Set(0,2,3);
	m1.Set(0,3,4);
	m1.Set(1,0,5);
	m1.Set(2,0,6);
	m1.Set(3,0,7);
	m1.Display();
}

