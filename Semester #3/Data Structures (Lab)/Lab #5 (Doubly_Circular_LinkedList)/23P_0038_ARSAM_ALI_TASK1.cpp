#include<iostream>
#include<string>
using namespace std;

class Inventory{
    private:
    string name;
    int unique_id;
    float price;
    int quantity;

    public:

    void insert_val(){
        cout<<"enter the name of the product : ";
        cin.ignore();
        getline(cin,name);
        cout<<endl<<"enter product id : ";
        cin>>unique_id;
        cout<<endl<<"enter the price : ";
        cin>>price;
        cout<<endl<<"enter quantity : ";
        cin>>quantity;
        
        cout<<"Product added successfully..."<<endl<<endl;
        
    }

    int getid(){
        return unique_id;
    }
    friend class doubly_linked_list;
    friend class Node;

};

class Node{
    private:
    Node *prev;
    Node *next;
    Inventory data;

    public:
    Node(){}
    Node(const Inventory &data){
        this->data=data;
        prev=NULL;
        next=NULL;
    }

        ~Node(){  }
    friend class doubly_linked_list;
};

class doubly_linked_list{
    Node *head;
    int length;

    public:
    doubly_linked_list(){
        head=NULL;
        length=0;
    }

    ~doubly_linked_list(){
        Node *temp=head;
        while(temp!=NULL){
            Node *nextNode=temp->next;
            delete temp;
            temp=nextNode;
        }
        cout<<"--destructor called--"<<endl;
    }    

    void insertbyid( Inventory & prod_1){
        Node *newnode=new Node (prod_1);
        if(head==NULL){
            head=newnode;
            return;
        }
        Node *temp=head;

        while(temp!=NULL && temp->data.getid()<prod_1.getid()){
            temp=temp->next;
        }

        if(temp==head){
            newnode->next=head;
            head->prev=newnode;
            head=newnode;
        }

        else if(temp==NULL){
            Node *tail=head;
            while(tail->next!=NULL){
                tail=tail->next;
            }
            tail->next=newnode;
            newnode->prev=tail;
        }

        else{
            newnode->next=temp;
            newnode->prev=temp->prev;
            temp->prev->next=newnode;
            temp->prev=newnode;
        }
        length++;
    }

    void remove(int id){
        if(head==NULL){
            cout<<endl<<"No students entered yet..."<<endl<<endl;
            return;
        }

        Node *temp=head;

        while(temp!=NULL && temp->data.getid()!=id){
            temp=temp->next;
        }

        if(temp==NULL){
            cout<<endl<<"Product with id "<<id<<" is not found.";
            return;
        }

        if (temp==head){
            head=head->next;
            if(head!=NULL){
                head->prev=NULL;
            }
        }

        else {
        if (temp->prev!=NULL){
            temp->prev->next=temp->next;
        }
        if (temp->next!=NULL){
            temp->next->prev=temp->prev;
        }
    }  
    delete temp;
    cout<<endl<<"Product with id : "<<id<<" have been removed succesfully."<<endl;

    length--;
    }

    void updateprice(int id,float pricenew){
    	if(head==NULL){
    		cout<<endl<<"No products entered yet..."<<endl;
    		return;
		}
        Node *temp=head;
        while(temp!=NULL && temp->data.getid()!=id){
            temp=temp->next;
        }

        if(temp==NULL){
            cout<<endl<<"Product not found"<<endl;
            return;
        }
        else{
            temp->data.price=pricenew;
            cout<<endl<<"Price updated.."<<endl;
        }
    }

    void find_prod(int id ){
    	if(head==NULL){
    		cout<<"No products entered yet..."<<endl;
    		return;
		}
        Node *temp=head;

        while(temp!=NULL && temp->data.unique_id!=id){
            temp=temp->next;
        }
        if(temp==NULL){
            cout<<endl<<"product not found ..."<<endl;

        }
        else{
            cout<<"Product name is : "<<temp->data.name<<endl;
            cout<<"product id is : "<<temp->data.unique_id<<endl;
            cout<<"product price is : "<<temp->data.price<<endl;
            cout<<"product quantity is : "<<temp->data.quantity<<endl;
        }
    }

    void display(){
        Node *temp=head;

        while(temp!=NULL){
            cout<<"Product name is : "<<temp->data.name<<endl;
            cout<<"product id is : "<<temp->data.unique_id<<endl;
            cout<<"product price is : "<<temp->data.price<<endl;
            cout<<"product quantity is : "<<temp->data.quantity<<endl;
            cout<<endl<<"-----------------------------------"<<endl;
            temp=temp->next;
        }
    }

};

int main(){
    doubly_linked_list d1;
    int choice,id;
    float newprice;

    Inventory p1;
	cout<<"inventory management system.."<<endl<<endl<<endl;
    do{
        cout<<endl<<endl<<"---------------------------------------------"<<endl<<endl;
        cout<<"1. Add product."<<endl;
        cout<<"2. Remove Product."<<endl;
        cout<<"3. Display Products."<<endl;
        cout<<"4. Update Price."<<endl;
        cout<<"5. Find Product."<<endl;
        cout<<"6. Exit."<<endl<<endl;
        cout<<"Enter choice : ";
        cin>>choice;

        if (choice==1){
            Inventory p1;
            p1.insert_val();
            d1.insertbyid(p1);
            
        }
        else if(choice==2){
            cout<<endl<<"enter the id to remove : ";
            cin>>id;
            d1.remove(id);
            
        }
        else if(choice==3){
            d1.display();
            
        }
        else if(choice==4){
            cout<<endl<<"enter product id to update price : ";
            cin>>id;
            cout<<endl<<"enter price : ";
            cin>>newprice;
            d1.updateprice(id,newprice);
            
        }
        else if(choice==5){
            cout<<"enter the product id to find : ";
            cin>>id;
            d1.find_prod(id);
            
        }
        else if(choice==6){
            cout<<"exiting..."<<endl;
        }
        else{
            cout<<endl<<"invalid choice try again please"<<endl;
        }
    }while(choice!=6);


    return 0;
}

