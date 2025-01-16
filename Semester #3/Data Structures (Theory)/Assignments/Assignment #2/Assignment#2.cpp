#include<iostream>
using namespace std;

class Node{
    public:
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
    public:
    Node *root;
    public:
    bst(){
        root=NULL;
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
    Node * delete_item(Node *n,int val){
        if (n==NULL){
            return NULL; 
        }
        if(val>n->data){
            n->right=delete_item(n->right,val);
        }else if(val<n->data){
            n->left=delete_item(n->left,val);
        }else{
            if(n->left==NULL&&n->right==NULL){
                delete n;
                return NULL;
            }
            else if (n->left==NULL){
                Node *temp=n->right;
                delete n;
                return temp;
            }
            else if(n->right==NULL){
                Node *temp=n->left;
                delete n;
                return temp;
            }
            else{
                Node * s1=n->right;
                while(s1->left!=NULL){
                    s1=s1->left;
                }
                n->data=s1->data;
                n->right=delete_item(n->right,s1->data);
            }
        }
        return n;
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
};

int main(){
    bst tree;//construct empty tree
    tree.is_empty();//determine tree is empty

    //Node *root=tree.root;

    tree.root=tree.insert(tree.root,3);
    tree.root=tree.insert(tree.root,1);
    tree.root=tree.insert(tree.root,5);
    tree.root=tree.insert(tree.root,4);
    cout<<"Pre-order traversal before deletion : "<<endl;
    tree.display_preorder(tree.root);
    cout<<endl<<endl;
    tree.root=tree.delete_item(tree.root,4);

    cout<<"pre-order traversal after deletition of 4 : "<<endl;
    tree.display_preorder(tree.root);

    return 0;
}