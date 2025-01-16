#include<iostream>
using namespace std;

class Node{
    private:
    Node *right;
    Node *left;
    int data;
    public:
    Node(int data){
        this->data=data;
        right=NULL;
        left=NULL;
    }
    friend class bst;
};
class bst{
    private:
    Node *root;
    public:
    bst(){
        root=NULL;
    }

    Node* getroot(){
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

    bool is_empty(){
        if(root==NULL){
            cout<<"The tree is empty."<<endl;
            return true;
        }else{
            cout<<"Tree is filled."<<endl;
            return false;
        }
    }
    void display_preorder(Node *n){
        if(n==NULL){
            return;
        }else{
            cout<<n->data<<"-->";
            display_preorder(n->left);
            display_preorder(n->right);
        }
    }

    void display_inorder(Node *n){
        if(n==NULL){
            return;
        }else{
            display_inorder(n->left);
            cout<<n->data<<"-->";
            display_inorder(n->right);
        }
    }

    void display_postorder(Node *n){
        if(n==NULL){
            return;
        }else{
            display_postorder(n->left);
            display_postorder(n->right);
            cout<<n->data<<"-->";
        }
    }

    int find_smallest_val(Node *n){
        if(n==NULL){
            return -1;
        }
        if(n->left==NULL){
            return n->data;
        }
        return find_smallest_val(n->left);
    }

    int count_nodes(Node *n,int count){
        if (n==NULL){
            return 0 ;
        }
        int l_count=count_nodes(n->left,count+1);
        int r_count=count_nodes(n->right,count+1);

        return 1+l_count+r_count;
    }
};

int main() {
    bst tree;
    int choice, data;
    Node *root=tree.getroot();
    do {
        cout<<"\nMenu:\n";
        cout<<"1. Insert a node\n";
        cout<<"2. Display Preorder\n";
        cout<<"3. Display Inorder\n";
        cout<<"4. Display Postorder\n";
        cout<<"5. Find the smallest value\n";
        cout<<"6. Count nodes in the tree\n";
        cout<<"7. Exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;

        switch (choice) {
            case 1:
                cout<<"Enter value to insert: (only integer)";
                cin>>data;
                root=tree.insert(root, data);
                cout<<"\n--VALUE INSERTED--\n";
                break;
            case 2:
                cout<<"Preorder traversal: ";
                tree.display_preorder(root);
                break;
            case 3:
                cout << "Inorder traversal: ";
                tree.display_inorder(root);
                break;
            case 4:
                cout << "Postorder traversal: ";
                tree.display_postorder(root);
                break;
            case 5:
                data = tree.find_smallest_val(root);
                if (data!=-1)
                    cout<<"The smallest value is: "<<data<<endl;
                break;
            case 6:
                cout<<"Total nodes in tree: "<<tree.count_nodes(root,0)<<endl;
                break;
            case 7:
                cout<<"Exiting..."<<endl;
                break;
            default:
                cout<<"Invalid choice. Please try again."<< endl;
        }
    }while(choice!=7);

    return 0;
}