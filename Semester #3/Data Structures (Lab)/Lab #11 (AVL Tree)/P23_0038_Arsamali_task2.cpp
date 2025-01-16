#include <iostream>
#include <string>

using namespace std;

class Node
{
public:
    int data, height;
    Node *left;
    Node *right;
    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
        height = 1;
    }
};

class Avl{
    Node *root;

public:
    Avl(){
        root = NULL; 
    }

    int getHeight(Node *n){
        if (n==NULL){
            return 0;
        }
        return n->height;
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

    // for every node height will be updated and balance check
    void insert(Node *n, int data)
    {
        if (n == NULL)
        {
            root = new Node(data);
            update_height(root);
            return;
        }
        else if (n->data < data)
            insert(n->left, data);
        else if (n->data > data)
            insert(n->right, data);

        n->height = update_height(n);
        int balance = check_balance(n);

        if (balance < -1){
            leftRotate(n);
        }
        else if (balance > 1){
            rightRotate(n);
        }
    }

    void leftRotate(Node *A){
        Node *B = A->right;
        B->left = A;
        A->right = NULL;
        A->height = update_height(A);
        root = B;
    }
    void rightRotate(Node *A){
        Node *B = A->left;
        B->right = A;
        A->left = NULL;
        A->height = update_height(A);
        root = B;        
    }
};

int main()
{

    Avl tree;

    cout << endl;

    return 0;
}