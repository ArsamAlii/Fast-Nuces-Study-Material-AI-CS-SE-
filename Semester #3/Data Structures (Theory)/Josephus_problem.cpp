#include<iostream>
using namespace std;
class Node{
    private:
    Node *next;
    Node *prev;
    int data;

    public:
    Node(int data){
        next=NULL;
        prev=NULL;
        this->data=data;
    }
    friend class D_linkedlist;

};
class D_linkedlist{
    Node *head;
    int length=0;
    public:
    D_linkedlist(){
        head=NULL;
    }

    void insert(int val){
        Node *newnode=new Node (val);
        if(head==NULL){
            head=newnode;
            head->next=head;
            head->prev=head;
        }else{
            Node *temp=head;
            while(temp->next!=head){
                temp=temp->next;
            }
            temp->next=newnode;
            newnode->prev=temp;
            newnode->next=head;
            head->prev=newnode;
        }
        length++;
    }

    void remove(int pos){
        if(head==NULL){
            cout<<"list is empty nothing to remove"<<endl;
            return;
        }
        else if(pos<1||pos>length){
            cout<<"Invalid position cannot remove ..."<<endl;
            return;
        }
        else{
            Node *curr=head;
            if(pos==1){
                Node *temp=head;
                while(temp->next!=head){
                    temp=temp->next;
                }
                if(head->next==head){
                    delete head;
                    head=NULL;
                }else{
                    head=head->next;
                    head->prev=temp;
                    temp->next=head;
                    delete curr;
                }
            }else{
                Node *slow=head;
                for(int i = 0 ; i<pos-1;i++){
                    slow=curr;
                    curr=curr->next;
                }
                slow->next=curr->next;
                curr->next->prev=slow;
            }            
            delete curr;
            length--;
        }

    }

    void josephus(int skip,int st_pos){//m=to skip//n
        if(skip<1){
            cout<<"invalid input (to skip value)..."<<endl;
            return;
        }

        if(length<1){
            cout<<"no person in circle..."<<endl;
            return;
        }

        Node *curr=head;
        for(int i=0;i<st_pos-1;i++){
            curr=curr->next;
        }

        while(length!=1){
        for(int i=0;i<skip;i++){//skip-1
            curr=curr->next;
        }   
            //cout<<"length before removing is : "<<length<<endl;
            cout<<"Value removed is : "<<curr->data<<endl;
            
            Node* nextnode=curr->next;
            int pos=find_pos_by_val(curr->data);
            remove(pos);
            //cout<<"length after removing is : "<<length<<endl;
            curr=nextnode;
            //curr=curr->next;
        }

        
        
    }

    int find_pos_by_val(int val){
        Node *curr=head;
        for(int i =0;i<length;i++){
            if(curr->data==val){
                return i+1;
            }
            curr=curr->next;
        }
        cout<<"no such value found"<<endl;
        return -1;
    }

    void display(){
        Node* temp=head;
        if(head->next==head){
            cout<<"the value left is : "<<temp->data<<endl;
        }
        while(temp->next!=head){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<temp->data;
        cout<<endl;
    }
    friend class Node;
};

int main(){
    D_linkedlist l1;

    l1.insert(1);
    l1.insert(2);
    l1.insert(3);
    l1.insert(4);
    l1.insert(5);
    l1.insert(6);
    l1.insert(7);
    l1.insert(8);
    l1.insert(9);
    l1.insert(10);

    cout << "Initial circle: ";
    l1.display();

    l1.josephus(3, 10);




    return 0;
}