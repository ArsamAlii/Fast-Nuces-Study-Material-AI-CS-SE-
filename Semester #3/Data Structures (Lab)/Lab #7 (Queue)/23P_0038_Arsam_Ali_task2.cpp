#include<iostream>
using namespace std;

class Node{
    int data;
    Node *next;
    public:
    Node(int data){
        next=NULL;
        this->data=data;
    }
    friend class linkedlist;
};

class linkedlist{
    Node *f;
    Node *r;

    public:
    linkedlist(){
        f=NULL;
        r=NULL;
    }

    void Enqueue(int val){
        Node *n=new Node (val);
        if(f!=NULL&&r!=NULL){
            r->next=n;
            r=n;
        }else{
            f=n;
            r=n;
        }
    }

    void Display() {
        if (f == NULL) {
            cout << "Queue is empty" << endl;
            return;
        }
        Node* temp = f;
        cout << "Queue: ";
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

void DuplicateNodes(){
    Node* curr=f;

    while(curr!=NULL){
        int duplicates=curr->data;

        Node* temp=curr;
        for(int i=0;i<duplicates-1;i++){
            Node* n=new Node(curr->data); 
            n->next=temp->next;
            temp->next=n;
            temp=n;
        }
        curr=temp->next;
    }
}
~linkedlist(){
    Node* current=f;
    while(current!=NULL){
        Node* n=current->next;
        delete current;
        current=n;
    }
    f=r=NULL;
}



};

int main(){
    linkedlist l1;

    l1.Enqueue(3);
    l1.Enqueue(4);
    l1.Enqueue(5);

    cout<<"User input : "<<endl;
    l1.Display();


    l1.DuplicateNodes();
    
    cout<<"After Duplicating : "<<endl;
    l1.Display();
    return 0;
}