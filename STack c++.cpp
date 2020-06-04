#include<iostream>
using namespace std;
template<class S>
class Stack{
	private:
		int size;
		int top;
		S *stack;
	public:
		Stack(){
			this->size=5;
			top=-1;
			stack=new S[this->size];
		}
		Stack(int size){
			this->size=size;
			top=-1;
			stack=new S[this->size];
		}
		int isEmpty();
		int isFull();
		void push(S ele);
		void pop();
		void display();
};

template<class S>
int Stack<S>::isEmpty(){
	if(top==-1){
		return 1;
	}
	return 0;
}

template<class S>
int Stack<S>::isFull(){
	if(top==size-1){
		return 1;
	}
	return 0;
}

template<class S>
void Stack<S>::push(S ele){
	if(isFull()){
		cout<<"\nCan't insert Stack is full\n";
	}
	else{
		stack[++top]=ele;
		cout<<"\nSuccessfully inserted\n";
	}
}

template<class S>
void Stack<S>::pop(){
	if(isEmpty()){
		cout<<"\nCan't pop stack is empty\n";
	}
	else{
		top--;
		cout<<"\nSuccessfully popped\n";
	}
}

template<class S>
void Stack<S>::display(){
	int sz=top;
	if(isEmpty()){
		cout<<"\nStack is Empty\n";
	}
	else{
		cout<<"\n ___ \n";
		while(sz>-1){
			cout<<"| "<<stack[sz--]<<" |"<<"\n ___ \n";
		}
	}
}

int main(){
	Stack<string> s1(5);
	s1.push("good");
	s1.push("I am good Boy");
//	s1.push(3);
//	s1.push(4);
//	s1.push(5);
//	s1.push(6);
	s1.pop();
	s1.display();
}




