#include<iostream>
using namespace std;

class stack{
	public:
		int arr[100];
		int top;
	stack(){
		top=-1;
	}
	
	void push(int val){
		if(top == 99){
			cout<<"Stack Overflow !!";
			return;
		}
		top++;
		arr[top]=val;
	}
	void pop(){
		if(top == -1){
			cout<<"Stack underflow !!";
			return;
		}
		top--;
	}
	void peek(){
		if(top == -1){
			cout<<"Stack underflow !!";
			return;
		}
		cout<<"TOP element : "<<arr[top];
	}
	void display(){
		if(top == -1){
			cout<<"Stack underflow !!";
			return;
		}
		for(int i=0;i<=top;i++){
			cout<<arr[i]<<" ";
		}
		cout<<endl;
	}
};

int main(){
	stack s;
	s.push(12);
	s.push(81);
	s.push(75);
	s.push(91);
	
	s.display();
	
	return 0;
}
