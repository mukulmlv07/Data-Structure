#include<iostream>
#include<stdlib.h>
using namespace std;
class Element{
	public:
		int i;
		int j;
		int x;
};
class Sparse{
	private:
		int row;
		int col;
		int num;
		Element *ele;
	public:
		Sparse(){
			row=0;
			col=0;
			num=0;
			ele=new Element[this->num];
		}
		Sparse(int row,int col,int num){
			this->row=row;
			this->col=col;
			this->num=num;
			ele=new Element[this->num];
		}
		~Sparse(){
			delete [] ele;
		}
		friend istream & operator>>(istream &ie,Sparse &s);
		friend ostream & operator<<(ostream &oe,Sparse &s);
		void Add(Sparse e1,Sparse e2);
};

istream & operator>>(istream &ie,Sparse &s){
	int z;
	cout<<"\nInsert Elements\nEnter Row, Column number and Element Respectively\n";
	for(z=0;z<s.num;z++){
		cin>>s.ele[z].i>>s.ele[z].j>>s.ele[z].x;
	}
	return ie;
}

ostream & operator<<(ostream &oe,Sparse &s){
	int z;
	for(z=0;z<s.num;z++){
		cout<<s.ele[z].i<<" "<<s.ele[z].j<<" "<<s.ele[z].x<<endl;
	}
	cout<<endl<<endl;
	return oe;
}

void Sparse::Add(Sparse e1,Sparse e2){
	int size=e1.num+e2.num;
	realloc(ele,size);
	if(e1.row==e2.row && e1.col==e2.col){
		int y=0;
		int z=0;
		int index=0;
		
		while(y<e1.num && z<e2.num){
			
			if(e1.ele[y].i==e2.ele[z].i){
				if(e1.ele[y].j==e2.ele[z].j){
					ele[index].i=e1.ele[y].i;
					ele[index].j=e1.ele[y].j;
					ele[index].x=e1.ele[y].x+e2.ele[z].x;
					y++;
					z++;
				}
				else if(e1.ele[y].j<e2.ele[z].j){
	
					ele[index]=e1.ele[y];
					y++;
				}
				else{
	
					ele[index]=e2.ele[z];
					z++;
				}
			}
			else if(e1.ele[y].i<e2.ele[z].i){
	
				ele[index]=e1.ele[y];
				y++;
			}
			else{
				ele[index]=e2.ele[z];
				z++;
			}
			index++;
		}
		for(;y<e1.num;y++){
	
			ele[index]=e1.ele[y];
			y++;
			index++;
		}
		for(;z<e2.num;z++){
	
			ele[index]=e2.ele[z];
			z++;
			index++;
		} 
		col=e1.col;
		row=e1.row;
		num=index;
	}
	
}




int main(){
	Sparse s1(5,6,2);
	Sparse s2(5,6,2);
	cin>>s1;
	cin>>s2;
	cout<<s1;
	cout<<s2;
	Sparse s3;
	s3.Add(s1,s2);
	cout<<s3;
}



