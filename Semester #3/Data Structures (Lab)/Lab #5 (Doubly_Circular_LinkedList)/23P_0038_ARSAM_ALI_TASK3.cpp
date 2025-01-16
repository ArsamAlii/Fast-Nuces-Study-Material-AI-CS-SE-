#include<iostream>
#include<string>
using namespace std;

class Node{
    string data;
    Node *prev;
    Node *next;
    public:
    Node(string data){
        this->data=data;
        prev=NULL;
        next=NULL;
    }
    friend class Linkedlist;
};
class Linkedlist{
    //circular linked list
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
    void insert(const string &data){
        Node* newnode=new Node(data);
        if(head==NULL){
            head=newnode;
            newnode->next=head;
            newnode->prev=head;
        }
        else{
            Node *tail=head->prev;

            newnode->next=head;
            newnode->prev=tail;
            tail->next=newnode;
            head->prev=newnode;

            head=newnode;

        }
        legnth++;
    }

    void display(){
        if(head==NULL){
            cout<<"list is empty"<<endl;
            return;
        }
        Node *temp=head;
        
        while(temp->next!=head){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        
        cout<<temp->data<<" ";

    }
    
    void remove(){
    	if(head==NULL){
    		cout<<"list is empty..."<<endl;
    		return;
		}
		if(head->next==head){
			delete head;
			head=NULL;
			cout<<"element from end removed...."<<endl;
			return;
		}
		
		Node* tail=head->prev;
		Node* slow=tail->prev;
		
		slow->next=head;
		head->prev=slow;
		
		delete tail;
		
		legnth--;
		
		cout<<"element from last have been removed.."<<endl;
		
	}
	
	friend class Node;
};

int main(){
    Linkedlist l1;
	int choice;
	
    do{
    	cout<<endl<<endl<<"----PLAYLIST----"<<endl<<endl;
    	cout<<"1. Add Song at Beginning."<<endl;
    	cout<<"2. Remove Song at End:"<<endl;
    	cout<<"3. Display Playlist:"<<endl;
    	cout<<"4. Exit"<<endl;
    	cout<<"Enter choice : ";
    	cin>>choice;
    	
    	if(choice==1){
    		string songname;
    		cout<<"Enter the song you want to add : ";
    		cin.ignore();
    		getline(cin,songname);
			l1.insert(songname);
		}
		else if(choice==2){
			l1.remove();
		}
		else if(choice==3){
			l1.display();
		}
		else{
			cout<<"exiting the program..."<<endl;
			break;
		}
    	
	}while(choice!=4);
	
	return 0;

}

