#include<iostream>
using namespace std;

class Node {
    Node *left;
    Node *right;
    int id;
    string name;
    string dept;
    public:
    Node(int id,string name,string dept){
        this->id=id;
        this->name=name;
        this->dept=dept;
        left=NULL;
        right=NULL;
    }
    friend class bst;
};

class bst{
    Node *root;
    public:
    bst(){
        root=NULL;
    }

    Node *getroot(){
        return root;
    }
    void setroot(int id,string name,string dept){
        root=new Node (id,name,dept);
    }

    Node *insert_emp(Node *n,int id,string name,string dept){
        if(n==NULL){
            Node *newnode=new Node (id,name,dept);
            if(root==NULL){
                root=newnode;
            }
            return newnode;
        }
        else if(id>n->id){
            n->right=insert_emp(n->right,id,name,dept);
        }
        else if (id<n->id){
            n->left=insert_emp(n->left,id,name,dept);
        }else{
            cout<<"ERROR: DUPLICATES ACNNOT BE ADDED ..."<<endl;
        }
        return n;
    }

//part2
    Node *searchbyid(Node *n,int c_id){
        if(n==NULL){
            return n;
        }
        if(n->id==c_id){
            return n;
        }else{
            if(c_id>n->id){
                return searchbyid(n->right,c_id);
            }else{
                return searchbyid(n->left,c_id);
            }
        }
    }

//part-3:

    int emp_level_auth(Node *n,int id,int level){
        if(n==NULL){
            return -1;
        }
        else if(n->id==id){
            return level;
        }
        int l=emp_level_auth(n->left,id,level+1);
        int r= emp_level_auth(n->right,id,level+1);

        if(l==-1){
            return r;
        }else{
            return l;
        }
    }

    void find_emp_auth(Node *n,int l,int t_lvl){
        if (n==NULL){
            return ;
        }
        if(l==t_lvl){
            cout << "ID: " << n->id << ", Name: " << n->name << ", Department: " << n->dept << endl;
        }

        find_emp_auth(n->left,l+1,t_lvl);
        find_emp_auth(n->right,l+1,t_lvl);
    }


//pt4 total depth
    int totaldepth(Node *n){
        if(n==NULL){
            return -1;
        }else{
            int l =totaldepth(n->left);
            int r=totaldepth(n->right);

            if(l>r){
                return (l+1);
            }else{
                return (r+1);
            }
        }
    }

//pt5
    void find_subordinates(Node *n,int id){
        if(n==NULL){
            cout<<"employee not found ";
            return ;
        }
        if(n->id==id){
            if(n->left==NULL&&n->right==NULL){
                cout<<"NO SUBORDINATES";
            }
            if(n->left!=NULL){
                cout<<"left subordinate id is :"<<n->left->id<<endl;
            }
            if(n->right!=NULL){
                cout<<"right subordinate id is :"<<n->right->id<<endl;
            }
            return ;
        }
        else{
            if(id<n->id){
                find_subordinates(n->left,id);
            }
            else if (id>n->id){
                find_subordinates(n->right,id);
            }
        }
    }

//pt6
    void view_all(Node *n){
        if(n==NULL){
            return ;
        }
        else{
            cout << "ID: " << n->id << ", Name: " << n->name << ", Department: " << n->dept << endl;
            view_all(n->left);
            view_all(n->right);
        }
    }

};

int main() {
    bst tree;
    int choice, id;
    string name, dept;
    int t_lvl;

    while (true) {
        cout<<"\nMenu:\n";
        cout<<"1. Add Employee\n";
        cout<<"2. View All Employees\n";
        cout<<"3. Find Subordinates\n";
        cout<<"4. Find Employees at Same Level\n";
        cout<<"5. Exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;

        switch (choice){
            case 1:
                cout<<"Enter Employee ID: ";
                cin>>id;
                cout<<"Enter Employee Name: ";
                cin>>name;
                cout<<"Enter Employee Department: ";
                cin>>dept;
                tree.insert_emp(tree.getroot(), id, name, dept);
                break;
            case 2:
                cout<<"Employee List:\n";
                tree.view_all(tree.getroot());
                break;
            case 3:
                cout<<"Enter Employee ID to find subordinates: ";
                cin>>id;
                tree.find_subordinates(tree.getroot(),id);
                break;
            case 4:
                cout<<"Enter Employee ID to find employees at the same level: ";
                cin>>id;
                t_lvl=tree.emp_level_auth(tree.getroot(),id,0);
                tree.find_emp_auth(tree.getroot(),0,t_lvl);
                break;
            case 5:
                cout<<"Exiting program.\n";
                return 0;
            default:
                cout<<"Invalid choice.Please try again.\n";
        }
    }

    return 0;
}