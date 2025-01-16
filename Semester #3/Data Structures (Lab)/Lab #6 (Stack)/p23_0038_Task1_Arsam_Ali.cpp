#include <iostream>
using namespace std;
class Node
{
public:
    string val;
    Node *next;
    Node(string val)
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
   ~Stack()
   {
       while(!isEmpty())
       {
           pop();
       }
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

    void push(string val)
    {
        Node *temp = new Node(val);
        temp->next = top;
        top = temp;
        length++;
    }
    
    string pop()
    {
		if(isEmpty()){
			cout<<"stack empty";
			return 0;
		}
        Node *temp = top;
        string val = top->val;
        top = top->next;
        delete temp;
        temp = NULL;
        length--;
		return val;
    }



};
int main(){
	int opt;
	Stack fns;
	Stack bns;
	string curr_link="";

	do{
		do{
		cout<<"1. Enter a new Link"<<endl;
    	cout<<"2. Go Back"<<endl;
    	cout<<"3. Go forward"<<endl;
		cout<<"4. Display current "<<endl;
		cout<<"Enter option : ";
		cin>>opt;

        if (opt<1 || opt>4) {
                cout<<"Invalid option enter again."<<endl<<endl;
        	}
		} while (opt<1||opt>4);



		if(opt<1||opt>4){

			cout<<"Invalid option please enter again ."<<endl<<endl;
		}
		else if (opt==1){
			string link;
			cout<<"Enter link : ";
			cin>>link;
            if(!curr_link.empty()){
				bns.push(curr_link);
			}

			curr_link=link;
			
			cout << "Current link: " << curr_link << endl<<endl;

			while(!fns.isEmpty()){
				fns.pop();
			}
		}
		else if (opt==2){
			if(bns.isEmpty()){
				cout<<"No previous links ."<<endl<<endl;
			}
			else{
				fns.push(curr_link);
				curr_link=bns.pop();
				cout<<"Now current link is : "<<curr_link<<endl<<endl;
			}
		}
		else if(opt==3){
			if(fns.isEmpty()){
				cout<<"No forwards links to go to "<<endl<<endl;
			}
			else{
				bns.push(curr_link);
				curr_link=fns.pop();
				cout<<"Now current link is : "<<curr_link<<endl<<endl;
			}
		}
		
			
		else if (opt==4){
			cout<<"Now current link is : "<<curr_link<<endl<<endl;
		}

			

		
	}while (opt >= 1 && opt <= 4);
	
	
	
	return 0;
}