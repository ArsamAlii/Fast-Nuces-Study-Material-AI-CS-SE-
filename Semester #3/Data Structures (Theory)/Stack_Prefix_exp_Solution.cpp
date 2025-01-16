#include <iostream>
#include<string>

using namespace std;
class Node
{
public:
    int val;
    Node *next;
    Node(int val)
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
            cout << "Stack is empty" << endl;
            return true;
        }
        else
        {
            return false;
        }
    }

    void push(int val)
    {
        Node *temp = new Node(val);
        temp->next = top;
        top = temp;
        length++;
        cout << "Element :" << val << " is pushed." << endl;
    }
    int pop()
    {
        if(isEmpty()){
            cout<<"stack underflow"<<endl;
            return -1;
        }        
        Node *temp = top;
        int val = top->val;
        top = top->next;
        delete temp;
        temp = NULL;
        length--;
        return val;
    }
    void peek()
    {
        if (!isEmpty())
        {
            cout << "Top of the stack: " << top->val << endl;
        }
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
};

void operate_exp(string exp)
{
    Stack exp_stack;

    for (int i = 0; i < exp.size(); i++){
        char c = exp[i];
        string store_val;

        if (isdigit(c)){
            store_val+=c;
        }else if (c==' '){
            int int_num=stoi(store_val);
            exp_stack.push(int_num);
            store_val.clear();
        } //space
        else{
            
            int temp1=exp_stack.pop();
            int temp2=exp_stack.pop();

            if(c=='+'){
                exp_stack.push(temp2+temp1);
               }
            else if(c=='-'){
                exp_stack.push(temp2-temp1);
            }
            else if(c=='*'){
                exp_stack.push(temp2*temp1);
            }
            else if(c=='/'){
                if (temp1==0){
                    cout << "Cannot divide by zero" << endl;
                    return;
                }else{
                    exp_stack.push(temp2/temp1);
                }
            }
            else if(c=='^'){
                int val=1;
                for (int i=0; i<temp1; i++){
                    val *=temp2;
                }
                exp_stack.push(val);
            }
            else{
                cout<<"Unknown operator: "<<c<<endl;
            }
        }
    }
    if (!exp_stack.isEmpty()){
        cout<<"Final answer: "<<exp_stack.pop()<<endl;
    }
}

int main()
{
    string expression;
    cout << "Enter expression: ";
    getline(cin,expression);

    operate_exp(expression);

    return 0;
}
