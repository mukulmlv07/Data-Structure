#include<iostream>
using namespace std;
class SymmetricM{
	private:
		int dim;
		int n;
		int *A;
	public:
		SymmetricM(){
			dim=2;
			n=2;
			A=new int[2]{0};
		}
		SymmetricM(int n){
			dim=n;
			this->n=n;
			A=new int[n]{0};
		}
		void Display();
		void Set(int i,int j,int v);
		int Get(int i,int j);
		~SymmetricM(){
			delete []A;
		}
};

void SymmetricM::Display(){
	int i,j;
//	for(i=0;i<n;i++){
//		cout<<A[i]<<" ";
//	}
//	cout<<endl;
	for(i=0;i<dim;i++){
		for(j=0;j<dim;j++){
			if(i<=j){
				cout<<A[i]<<" ";
			}
			else{
				cout<<A[j]<<" ";
			}
		}
		cout<<endl;
	}
	cout<<endl;
}
void SymmetricM::Set(int i,int j,int v){
	int index;
	if(i<=j){
		index=i;
	}	
	else{
		index=j;
	}
		A[index]=v;	
	
}

int SymmetricM::Get(int i,int j){	
	int index;
	if(i<=j){
		index=i;
	}	
	else{
		index=j;
	}
	return A[index];
}

int main(){
	SymmetricM m1(4);
	m1.Display();
	m1.Set(0,0,1);
	m1.Set(1,1,2);
	m1.Set(2,2,3);
	m1.Set(3,3,4);
	m1.Display();
}

