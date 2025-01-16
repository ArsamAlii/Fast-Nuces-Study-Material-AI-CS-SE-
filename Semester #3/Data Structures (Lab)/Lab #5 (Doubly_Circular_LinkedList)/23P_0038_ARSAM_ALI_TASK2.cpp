#include<iostream>
using namespace std;

class Node{
    int data;
    Node *prev;
    Node *next;
    public:
    Node(int data){
        this->data=data;
        prev=NULL;
        next=NULL;
    }
    friend class Linkedlist;
};
class Linkedlist{
    //doubly linked list
    Node *head;
    int legnth;
    public:
    Linkedlist(){
        head =NULL;
        legnth=0;
    }
    ~Linkedlist(){
        Node *temp=head;
        while(temp!=NULL){
            Node *nextNode=temp->next;
            delete temp;
            temp=nextNode;
        }
        cout<<endl<<"--destructor called--"<<endl;
    }   
    void insert(int data){
        Node* newnode=new Node(data);
        if(head==NULL){
            head=newnode;
            legnth++;
        }
        else{
            Node *temp=head;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=newnode;
            newnode->prev=temp;
            legnth++;
        }
    }
    void display(){
        Node *temp=head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }

    }

    void split_list(){
        Node*temp =head;
        Linkedlist even_list,odd_list;


        while(temp!=NULL){
            if(temp->data%2==0){
                even_list.insert(temp->data);
            }else{
                odd_list.insert(temp->data);
            }
            temp=temp->next;
        }

        cout<<endl<<"Even list is : "<<endl;
        even_list.display();
        cout<<endl<<"odd list is : "<<endl;
        odd_list.display();
    }
    friend class Node;
};

int main(){
    Linkedlist l1;
    l1.insert(1);
    l1.insert(2);
    l1.insert(3);
    l1.insert(4);
    l1.insert(5);
    l1.insert(6);
    l1.insert(7);
    l1.insert(8);
    l1.insert(9);


    cout<<"orignal list is : "<<endl;
    l1.display();

    cout<<"split list are :"<<endl<<endl;

    l1.split_list();

    return 0;
}

