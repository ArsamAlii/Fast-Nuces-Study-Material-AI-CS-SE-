#include <iostream>

using namespace std;

class Node
{
public:
    int info;
    Node *next;

    Node(int val)
    {
        info = val;
        next = NULL;
    }
};

class CircularLinkedList{
public:
    Node *head;
    int length;

    CircularLinkedList(){
        head=NULL;
        length=0;
    }

    void insert(int val, int pos){
        if (pos<1||pos>length+1){
            cout << "Invalid Position" << endl;
            return;
        }

        Node *n = new Node(val);

        if (pos == 1){
            if (head != NULL){
                Node *tail = head;

                while (tail->next != head){
                    tail = tail->next;
                }
                n->next=head;
                head=n;
                tail->next=head;
            }
            else{
                head=n;
                n->next=n;
            }
        }
        else{
            Node *curr=head;

            for (int i=1;i<pos-1;i++){
                curr=curr->next;
            }

            n->next = curr->next;
            curr->next = n;
        }
        length++;
    }

    void remove(int pos){
        if(pos<1||pos>length)
        {
            cout<<"Invalid Position"<<endl;
            return;
        }

        if(head==NULL){
            cout<<"List is empty"<<endl;
            return;
        }

        if(pos==1){
            Node *tail=head;

            if (head->next!=head){
                while (tail->next!=head){
                    tail=tail->next;
                }

                Node *toDelete=head;
                head=head->next;
                tail->next=head;
                delete toDelete;
            }
            else{
                delete head;
                head=NULL;
            }
        }
        else{
            Node *curr=head;
            Node *prev=NULL;

            for (int i=1;i<pos;i++){
                prev=curr;
                curr=curr->next;
            }
            prev->next=curr->next;
            delete curr;
        }
        length--;
    }
};

int main()
{
    CircularLinkedList ll;

    cout << "Inserting elements:" << endl;
    ll.insert(10,1);
    ll.insert(20,2);
    ll.insert(30,3);
    ll.insert(15,2);

    ll.insert(40,0);//error message(invalid position)
    ll.insert(50,6);//error message(invalid pos)

    Node *current=ll.head;
    cout<<"List after inserts: ";
    for (int i=0;i<ll.length;i++)
    {
        cout<<current->info<<" ";
        current=current->next;
    }
    cout<<endl;

    cout << "Removing elements:" << endl;
    ll.remove(1);
    ll.remove(2);

    ll.remove(0);
    ll.remove(4);

    current = ll.head;
    cout << "List after removes: ";
    for (int i=0;i<ll.length;i++)
    {
        cout << current->info << " ";
        current = current->next;
    }
    cout << endl;

    return 0;
}
