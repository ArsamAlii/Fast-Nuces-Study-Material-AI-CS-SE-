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

    Node *search(Node *n,int val){//search the bst
        if(n==NULL){
            return NULL;
        }
        if(n->data==val){
            return n;
        }
        if(val>n->data){
            return search(n->right,val);
        }else if(val<n->data){
            return search(n->left,val);
        }
    }



    void display_preorder(Node *n){
        if(n==NULL){
            return;
        }else{
            cout<<n->data<<",";
            display_preorder(n->left);
            display_preorder(n->right);
        }
    }
};

int main(){
    bst tree;

    Node *root=tree.getroot();
    root=tree.insert(root,4);
    root=tree.insert(root,2);
    root=tree.insert(root,1);
    root=tree.insert(root,3);
    root=tree.insert(root,7);

    //tree.display_preorder(tree.root->left);
    
    Node *node_toshow=tree.search(root,2);

    cout<<"output with input 2 : "<<endl;
    cout<<"[";
    tree.display_preorder(node_toshow);
    cout<<"]";

    cout<<endl;
    cout<<"output with input 5 : "<<endl;
    Node *node_toshow2=tree.search(root,5);
    cout<<"[";
    tree.display_preorder(node_toshow2);
    cout<<"]";


    return 0;
}