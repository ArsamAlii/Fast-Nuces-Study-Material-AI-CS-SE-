
#include<iostream>
using namespace std;

class Studentrecord{
    private:
    string stud_name;
    int stud_id;
    float stud_gpa;

    public:
    Studentrecord(){}
    Studentrecord(string name,int id,float gpa){
        stud_name=name;
        stud_id=id;
        stud_gpa=gpa;
    }
    void input(){
        cout<<"enter the name of the student : ";
        cin.ignore();
        getline(cin,stud_name);
        cout<<endl<<"enter thhe id of the student (integer): ";
        cin>>stud_id;
        do{
        	cout<<endl<<"enter the gpa of the student (1-4)";
        	cin>>stud_gpa;
        	if(stud_gpa<0||stud_gpa>4){
        		cout<<"invalid gpa..(enter gpa 1-4)"<<endl;
			}
        cout<<"student added successfully"<<endl<<endl;
		}while(stud_gpa<0||stud_gpa>4);
    }
    friend class linkedarray;
};

class Node{
    private:
    Studentrecord new_stud;
    Node *next;

    public:
    Node(const Studentrecord &new_stud){
        next=NULL;
        this->new_stud=new_stud;
    }
    friend class linkedarray;
};

class linkedarray{
    private:
    Node *head;
    public:
    linkedarray(){
        head=NULL;
    }
    void add_stud(const Studentrecord &new_stud){
       Node *new_node=new Node(new_stud);
       if(head==NULL){
            head=new_node;
       }
       else{
            Node *temp=head;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=new_node;        
       }
       

    }
    void removestud(int id){
    	
    	if(head==NULL){
    		cout<<"No student added..nothing to remove."<<endl<<endl;
    		return;
		}
    	Node *to_remove=searchbyid(id);		
		
		if(to_remove==NULL){
			cout<<"no student with this id fouund";
			return;
		}
		if(head->new_stud.stud_id==id){
			Node *temp=head;
			head=head->next;
			delete temp;
			cout<<"Student with id"<<id<<"has been removed successfully"<<endl<<endl;
			return;
			}
		
		Node *temp=head;
		Node *slow=NULL;
		
		while(temp!=NULL&&temp->new_stud.stud_id!=id){
			slow=temp;
			temp=temp->next;
		}
		
        if (temp == NULL) {
            cout << "Student with ID " << id << " not found." << endl << endl;
            return;
        }

		slow->next=temp->next;
		delete temp;
		cout<<"student with id "<<id<<"has been removed successfully"<<endl<<endl;
		

    	
	}
	
	Node* searchbyid(int id){
		Node*temp=head;
		if(temp==NULL){
			cout<<"nothing to search..no students added yet"<<endl<<endl;
			return NULL;
		}
//		while(temp!=NULL&&temp->new_stud.stud_id!=id)
		while(temp!=NULL){
			if(temp->new_stud.stud_id==id){
            cout<<"\tName: "<<temp->new_stud.stud_name<<"\tID: "<<temp->new_stud.stud_id<<"\tGPA: "<<temp->new_stud.stud_gpa<<endl;
				return temp;
			}
			temp=temp->next;
		}
		cout<<"NO students found with this id."<<endl<<endl;
		return NULL;
	}

    void display(){
    	Node *temp=head;
		if(temp==NULL){
    		cout<<"No records of any student found add students please"<<endl<<endl;
		}
        
        while (temp!=NULL){
            cout<<"\tName:\tID:\tGPA: "<<endl
			<<"\t"<<temp->new_stud.stud_name 
            <<"\t"<<temp->new_stud.stud_id 
            <<"\t"<<temp->new_stud.stud_gpa<<endl;
            temp = temp->next;
        }
    }
    
    void calc_avg() {
        Node *temp=head;
        if (temp==NULL){
            cout<<"No records available to calculate GPA."<<endl<<endl;
            return;
        }
        float sum=0;
        int count=0;
        while(temp!=NULL){
            sum+=temp->new_stud.stud_gpa;
            count++;
            temp=temp->next;
        }

        float average=sum/count;
        cout<<"Average GPA of all students: "<<average<<endl<<endl;
    }
};


int main() {
    linkedarray students;
    int opt1;
    do{
    cout<<endl<<"welcome to the Student Registration system : "<<endl;
    cout<<"1. Add a student"<<endl;
    cout<<"2. Remove a student"<<endl;
    cout<<"3. Search for a student"<<endl;
    cout<<"4. Display all students"<<endl;
    cout<<"5. Calculate average GPA"<<endl;
    cout<<"6. Exit"<<endl;
    cout<<"Enter your desired option : ";
    cin>>opt1;

    if(opt1<1||opt1>6){
        cout<<"invalid option enter again [please]."<<endl<<endl;
    }
    
    if(opt1==1){
        Studentrecord student;
        student.input();
        students.add_stud(student);
    }

	if(opt1==2){
		int id;
		cout<<"Enter the student id whom you want to remove: ";
		cin>>id;
		students.removestud(id);
	}
	
    if(opt1==3){
		int id;
		cout<<"Enter the student id whom you want to search: ";
		cin>>id;
		students.searchbyid(id);
	}
	
    if(opt1==4){
    	students.display();
	}	
	
	if(opt1==5){
		students.calc_avg();
	}
	
    }while(opt1!=6);

	cout<<"GOODBYE";

    return 0;
}

