#include <iostream>
using namespace std;

class Node{
public:
    char val;
    Node* next;
    Node(char val){
        this->val=val;
        next=NULL;
    }
};

class Stack{
    Node* top;
    int length;

public:
    Stack(){
        top = NULL;
        length = 0;
    }

    bool is_empty(){
        if(top==0){
            return true;
        }
        else{
            return false;
        }
    }

    void push(char val) {
        Node* temp=new Node(val);
        temp->next=top;
        top=temp;
        length++;
    }

    char pop() {
        if (is_empty()){
            return 0;
        }
        Node* temp=top;
        char val=top->val;
        top=top->next;
        delete temp;
        length--;
        return val;
    }

    bool check_balance(string user_string) {
        for (int i = 0; i < user_string.size(); i++){
            char ch = user_string[i];

            if(ch=='('||ch=='{'||ch=='['){
                push(ch);
            } 
            else if(ch==')'||ch=='}'||ch==']'){
                if(is_empty()){
                    return false;
                }

                char temp=pop();
                if((ch == ')' && temp != '(')||(ch == '}' && temp != '{')||(ch == ']' && temp != '[')) {
                    return false;
                }
            }
        }

        return is_empty();
    }
};

int main(){
    Stack s;
    string user_string;
    bool valid_input;

    do {
        valid_input=true;
        cout<<"Enter brackets to check balance: ";
        cin>>user_string;

   
        for(int i=0; i<user_string.size();i++){
            char ch=user_string[i];
            if(ch!='('&&ch!=')'&&ch!='{'&&ch!='}'&&ch!='['&&ch!=']'){
                cout<<"Wrong input! Enter only brackets."<<endl<<endl;
                valid_input=false;
                break;
            }
        }

    } while (!valid_input);

    cout << boolalpha << s.check_balance(user_string) << endl<<endl;

    return 0;
}
