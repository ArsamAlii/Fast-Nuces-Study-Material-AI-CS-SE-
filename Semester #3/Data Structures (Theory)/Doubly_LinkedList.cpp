#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node *prev;

    Node(int data){
        this->data=data;
        next=NULL;
        prev=NULL;
    }
};

class DoublyLinkedList{
public:
    Node *head;
    int length;

    DoublyLinkedList(){
        head=NULL;
        length=0;
    }

    void insert(int val, int pos) {
        if (pos < 1 || pos > length + 1) {
            cout << "Invalid position" << endl;
            return;
        }

        Node *n=new Node(val);

        if (pos==1){
            if (head != NULL){
                Node *tail = head->prev;

                n->next = head;
                n->prev=tail;
                head->prev=n;
                tail->next=n;
                head=n;
            }else{
                head=n;
                n->next=n;
                n->prev=n;
            }
        }else{
            Node *curr=head;

            for (int i=1;i<pos-1;i++){
                curr=curr->next;
            }

            n->next=curr->next;
            n->prev=curr;
            curr->next->prev=n;
            curr->next=n;
        }

        length++;
        cout<<"Inserted "<<val<<" at position "<<pos<<endl;
    }

    void remove(int pos){
        if (pos<1||pos>length){
            cout << "Invalid Position"<<endl;
            return;
        }

        if (head==NULL){
            cout<<"List is empty"<<endl;
            return;
        }

        if(pos==1){
            Node *tail=head->prev;
            if(head->next!=head){
                Node *toDelete=head;
                head=head->next;
                tail->next=head;
                head->prev=tail;
                delete toDelete;
            }else{
                delete head;
                head=NULL;
            }
        }else{
            Node *curr=head;

            for (int i=1;i<pos;i++){
                curr=curr->next;
            }

            curr->prev->next=curr->next;
            curr->next->prev=curr->prev;
            delete curr;
        }

        length--;
    }

    void display(){
        if(head==NULL){
            cout<<"List is empty"<<endl;
            return;
        }

        Node *temp=head;
        do{
            cout<<temp->data<<" ";
            temp=temp->next;
        }while(temp!=head);
        cout<<endl;
    }
};

int main() {
    DoublyLinkedList ll;

    cout<<"Inserting elements:" <<endl;
    ll.insert(10,1);
    ll.insert(20,2);
    ll.insert(30,3);
    ll.insert(15,2);
    ll.insert(40,5);

    cout<<"List after inserts: ";
    ll.display();

    cout<<"Removing elements:"<<endl;
    ll.remove(1);
    ll.remove(3);

    cout<<"List after removes: ";
    ll.display();

    return 0;
}