#include<iostream>
using namespace std;

class Node{
    string data;
    Node *next;
    public:
    Node(const string & data){
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

    void Enqueue(const string& val){
        Node *n=new Node (val);
        if(f!=NULL&&r!=NULL){
            r->next=n;
            r=n;
        }else{
            f=n;
            r=n;
        }
        cout<<val<<" added to queue...Please Wait.."<<endl<<endl;
    }

    string Dequeue(){
        if(f==NULL){
            cout<<"No orders yet..Nothing to remove."<<endl<<endl;
            return " ";
        }
        else{
            string val=f->data;
            Node *curr=f;
            f=f->next;
            if(f==NULL){
                r=NULL;
            }
            delete curr;
            return val;
        }
    }
    void Display() {
        if (f == NULL) {
            cout << "no orders yet..nothing to display" << endl;
        }else{
        Node* temp = f;
        cout << "Queue: ";
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
}
    }

~linkedlist(){
    Node* curr=f;
    while(curr!=NULL){
        Node* nextNode=curr->next;
        delete curr;
        curr=nextNode;
    }
    f=r=NULL;
}

};

void display_menu(){
    cout<<endl<<"--------------------"<<endl;
    cout<<"1. rice."<<endl;
    cout<<"2. chana chaat."<<endl;
    cout<<"3. biryani."<<endl;
    cout<<"4. burger."<<endl;
    cout<<"----------------------"<<endl;
 
}

int main(){
    linkedlist l1;

    int opt;
    do{
        do{
            cout<<endl<<"Cafeteria ordering system : "<<endl<<endl;
            cout<<"1.Menu Display."<<endl;
            cout<<"2.Press if first order completed."<<endl;
            cout<<"3.Order in queue display. "<<endl;
            cout<<"4.exit"<<endl;
            cout<<"Enter choice : ";
            cin>>opt;

            if(opt<1||opt> 4){
            cout<<"invalid input. enter valid integers(1-4)"<<endl;
        }              
        }while(opt<1||opt> 4);
  

        if(opt==1){
            int ch;
            do{
                display_menu();
                cout<<"enter choice : ";
                cin>>ch;     
                if(ch<1||ch>4){
                    cout<<"invalid choice re-enter please";
                }  
                else if(ch==1){
                    l1.Enqueue("rice");
                    
                }        
                else if(ch==2){
                    l1.Enqueue("chanachaat");
                    
                } 
                else if (ch==3){
                    l1.Enqueue("biryani");
                    
                }
                else if(ch==4){
                    l1.Enqueue("burger");
                    
                }
            }while(ch<1||ch>4);

        }
        else if (opt==2){
            string d_order;
            d_order=l1.Dequeue();
           cout<<"Completed order : "<<d_order<<endl;
           
        }
        else if (opt==3){
            l1.Display();
        }
        else if(opt==4){
        	cout<<"thanks for using me.goodbyr";
		}

            
    }while (opt!=4);




    return 0;
}