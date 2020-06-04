#include<iostream>
using namespace std;
class TriDiagonalMatrix{
	private:
		int dim;
		int n;
		int *M;
	public:
		TriDiagonalMatrix(){
			dim=3;
			n=3*dim-2;
			M=new int[n]{0};
		}
		
		TriDiagonalMatrix(int dim){
			this->dim=dim;
			n=3*dim-2;
			M=new int[n]{0};
		}
		
		void Set(int i,int j,int v);
		void Display();
		int Get(int i,int j);
		
		~TriDiagonalMatrix(){
			delete []M;
		}
			
};

void TriDiagonalMatrix::Set(int i,int j,int v){
	int index;
	if(i-j==1){
		index=j;
		M[index]=v;
	}
	else if(i-j==0){
		index=dim-1+i;
		M[index]=v;
	}
	else if(i-j==-1){
		index=2*dim-1+i;
		M[index]=v;
	}
	
}

int TriDiagonalMatrix::Get(int i,int j){
	int index;
	if(i-j==1){
		index=j;
		return M[index];
	}
	else if(i-j==0){
		index=dim-1+i;
		return M[index];
	}
	else if(i-j==-1){
		index=2*dim-1+i;
		return M[index];
	}
	return 0;
}

void TriDiagonalMatrix::Display(){
	int i,j,index;
	for(i=0;i<dim;i++){
		for(j=0;j<dim;j++){
			if(i-j==1){
				index=i-1;
				cout<<M[index];
			}
			else if(i-j==0){
				index=dim-1+i;
				cout<<M[index];
			}
			else if(i-j==-1){
				index=2*dim-1+i;
				cout<<M[index];
			}
			else{
				cout<<0;
			}
			cout<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}

int main(){
	TriDiagonalMatrix t1(4);
	t1.Display();
	t1.Set(0,0,1);
	t1.Set(2,1,2);
	t1.Set(3,3,3);
	t1.Display();
	cout<<t1.Get(2,1);
	cout<<endl<<t1.Get(3,3)<<endl;
	cout<<t1.Get(0,3)<<endl;
	
}








