#include <iostream>
#include<string>

using namespace std;
class Node
{
public:
    float val;
    Node *next;
    Node(float val)
    {
        this->val = val;
        next = NULL;
    }
};
class Stack
{
    Node *top;
    int length;

public:
    Stack()
    {
        top = NULL;
        length = 0;
    }

    bool isEmpty()
    {
        if (top == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void push(float val)
    {
        Node *temp = new Node(val);
        temp->next = top;
        top = temp;
        length++;
        cout << "Element :" << val << " is pushed." << endl;
    }
    float pop()
    {
        if(isEmpty()){
            cout<<"Stack Underflow-- Cannot solve further..."<<endl;
            exit(0);
        }        
        Node *temp = top;
        int val = top->val;
        top = top->next;
        delete temp;
        temp = NULL;
        length--;
        return val;
    }

    void display()
    {
        if (!isEmpty())
        {
            Node *temp = top;
            while (temp != NULL)
            {
                cout << temp->val;
                temp = temp->next;
            }
            cout << endl;
        }
    }
    ~Stack(){
        while(!isEmpty()){
            pop();  
        }
        cout<<endl<<"--destructor called--"<<endl<<endl;
    }
};

float operate_exp(string exp){
	Stack exp_stack;
	char c;
	
	string store_val; 
	for(int i=0;i<exp.size();i++){
	       c=exp[i];
	
	    if(isdigit(c)){
	        store_val += c;
	    }else if(c == ' ') {
	        if(!store_val.empty()){
	            float int_num = stof(store_val);
	            exp_stack.push(int_num);  
	            store_val.clear();
	        }
	    }
		else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^'){

	        float temp1=exp_stack.pop();
	        float temp2=exp_stack.pop();
	
	        if(c=='+'){
	            exp_stack.push(temp2+temp1);
	            }
	        else if(c=='-')
	            exp_stack.push(temp2-temp1);
	        else if(c=='*')
	            exp_stack.push(temp2*temp1);
	        else if(c=='/')
	            if (temp1==0){
	                cout << "Error : Cannot divide by zero" << endl;
	                return -1;
	            }else{
	                exp_stack.push(temp2/temp1);
	            }
	        else if(c=='^'){
	            int val=1;
	            for (int i=0; i<temp1; i++){
	                val *=temp2;
	            }
	            exp_stack.push(val);
			}
		}
	        else{
	            cout<<"Unknown operator : "<<c<<endl;
	        }
	}
	if(!store_val.empty()){
	   	float num=stof(store_val);
	   	exp_stack.push(num);
	}	
	
	
	if(!exp_stack.isEmpty()){
	    float f_val=exp_stack.pop();
	    return f_val;
	}	
		
	
}

int main(){
    string expression;
    cout << "Enter expression: ";
    getline(cin,expression);

    cout<<"Final value is : "<<operate_exp(expression)<<endl;

    return 0;
}