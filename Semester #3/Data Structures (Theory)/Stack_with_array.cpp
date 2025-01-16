#include<iostream>
using namespace std;

class Stack{
	private:
		int *arr;
		int capacity;
		int top;
		
	public:
		Stack(int size){
			arr=new int [size];
			capacity=size;
			top=-1;
		}

        ~Stack(){
            delete[] arr;
        }
		
		bool is_empty(){
			if(top==-1){
				return true;
			}
			else {
				return false;
			}
		}
		
		bool is_full(){
			if(top==capacity-1){
				return true;
			}
			else{
				return false;
			}
		}
		
		void push(int val){
			if(is_full()){
				cout<<"stack is full cannot add more elements"<<endl;
				return;
			}
			else{
				top++;
				arr[top]=val;
			}
		}
		
		int pop(){
			if(is_empty()){
				cout<<"stack is empty nothing to remove"<<endl;
				return 0;
			}
			else{
				int val=arr[top];
				top--;
				return val;
			}
		}
		
		int peak(){
			if(is_empty()){
				cout<<"array is empty nothing to return "<<endl;
				return 0;
			}else{
				return arr[top];
			}
		}
		
		void display(){
			for(int i=0;i<=top;i++){
				cout<<arr[i]<<" ";
			}
			cout<<endl;
		}
};


int main(){
	
	Stack a1(5);
	
	a1.push(1);
	a1.push(2);
	a1.push(3);
	a1.push(4);
	a1.push(5);
//	a1.push(6); //adding this line would give error is max limit reached
	
	cout<<"After using push : ";
	a1.display();
	
	a1.pop();
	
	cout<<"After using pop function : ";
	a1.display();
	
	int peak_val=a1.peak();
	
	cout<<"After using peak function : "<<peak_val;
	
	
	return 0;
}