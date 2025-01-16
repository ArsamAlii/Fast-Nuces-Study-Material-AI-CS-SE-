#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;

    public:

    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};
class Linkedlist{
    public:
    Node *head;
    int length;

    public:

    Linkedlist(){
        head=NULL;
        length=0;
    }

    ~Linkedlist() {
        Node *current = head;
        while (current != NULL) { 
            delete current; 
            current = current->next;
        }
        head = NULL; 
        cout << "Linked list deleted." << endl;
    }    

    void add(int val){

        Node *newnode=new Node(val);
        if(head==NULL){
            head=newnode;
        }else{
            Node *curr=head;
            while(curr->next!=NULL){
                curr=curr->next;
            }
            curr->next=newnode;
        }
        length++;
    }

    void insert(int val,int pos){
        if (pos<1||pos>length+1){
            cout<<"invalid position"<<endl;
            return;
        }
        Node *newnode=new Node (val);
        if(pos==1){
            if(head==NULL){
                head=newnode;
            }else{
                newnode->next=head;
                head=newnode;
            }
        }else{
            Node *curr=head;
            for(int i=1;i<pos-1&&curr!=NULL;i++){
                curr=curr->next;
            }
            newnode->next=curr->next;
            curr->next=newnode;
        }
        length++;
    }


    void update(int pos, int newValue){
        if (pos<1||pos>length){
            cout<<"Invalid position"<<endl;
            return;
        }
        Node *curr=head;
        for (int i=1;i<pos;i++){
            curr=curr->next;
        }
        curr->data=newValue;
        cout<<"Node at position "<<pos<<" updated to "<<newValue<<endl;
    }    

    void remove(int pos){
        if(length==0){
            cout<<"Linked List is empty"<<endl;
            return;
        }
        if(pos<1||pos>length){
            cout<<"invalid position";
            return;
        }
        Node* curr=head;
        if(pos==1){
            head=head->next;
            delete curr;
        }
        else{
            Node *slow=NULL;
            for(int i =1;i<pos;i++){
                slow=curr;
                curr=curr->next;
            }
            slow->next=curr->next;
            delete curr;
        }
        length--;
    }

    bool find(int val){
        if(length==0){
            cout<<"Linkedlist is empty"<<endl;
            return false;
        }
        Node *temp=head;
        while(temp!=NULL){
              if(temp->data==val){
                return true;
            }
            temp=temp->next;
        } 
        return false;
    }

    void display() {
        if (head==NULL) {
            cout<<"List is empty"<<endl;
            return;
        }
        Node *temp=head;
        while (temp!=NULL) {
            cout<<temp->data<<" -> ";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }    

};

int main(){
    Linkedlist l1;

    l1.add(2);
    l1.add(6);
    l1.add(8);
    l1.add(10);

    Linkedlist l2;
    l2.add(1);
    l2.add(3);
    l2.add(5);

    l1.display();

    return 0;
}