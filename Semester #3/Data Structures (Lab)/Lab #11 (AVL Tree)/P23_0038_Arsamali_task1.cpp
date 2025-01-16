#include <iostream>
using namespace std;

class Node {
private:
    int data, height;
    Node* left;
    Node* right;

    Node(int d) {
        data=d;
        left=NULL;
        right=NULL;
        height=1;
    }
    friend class Avl;
};

class Avl{
    Node* root;

public:
    Avl(){ 
        root = NULL;
    }
    Node *getroot(){
        return root;
    }

    Node *insert(Node *node,int data){
        if(node==NULL){//destination
            Node *newnode=new Node (data);
            if(root==NULL){
                root=newnode;
            }
            return newnode;
        }
        else if(data>node->data){
            node->right=insert(node->right,data);
        }
        else if (data<node->data){
            node->left=insert(node->left,data);

        }
        else{
            cout<<"ERROR: DUPLICATES FOUND CANNOT BE ADDED...";
        }
        return node;
    }

    int update_height(Node *n){
        if(n==NULL){
            return 0;
        }
        int l=update_height(n->left);
        int r =update_height(n->right);

        if(l>r){
            return l+1;
        }else{
            return r+1;
        }
    }

    int check_balance(Node *n){
        if (n==NULL){
            return 0;
        }else{
            return update_height(n->left)-update_height(n->right);
        }
    }

    bool check_avl(Node *n){
        if(n==NULL){
            return true;
        }
        int balance = check_balance(n);

        if (balance > 1 || balance < -1) {
            return false;
        }        

        return check_avl(n->left) && check_avl(n->right);
    }
};


int main(){
    Avl tree;
    Node* root=tree.getroot();
    
    int n,data;
    cout<<"Enter the number of elements you want to insert into the AVL tree: ";
    cin>>n;

    cout<<"Enter "<<n<<" elements: \n";
    for(int i=0;i<n;i++){
        cin>>data;
        root=tree.insert(root,data);
    }

    cout << "\nCheck AVL for entered values:\n";
    bool c=tree.check_avl(root);
    if(c==true){
        cout<<"AVL";
    }
    else{
        cout<<"Not AVL";
    }

    return 0;
}