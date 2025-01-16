#include<iostream>
using namespace std;

class Node{
    public:
    Node *left;
    Node *right;
    int data;

    public:
    Node(int data){
        this->data=data;
        left=NULL;
        right=NULL;
    }
    friend class Binary_tree;
};

class Binary_tree{
    private:
    Node *root;
    
    public:
    Binary_tree(){
        root=NULL;
    }

    void set_root(int val){
        if(root!=NULL){
            cout<<"cannot add a value to root already filled.."<<endl;
            return;
        }else{
            root=new Node(val);
        }
    }
    Node* get_root(){
        return root;
    }

    void set_right(Node *p,int val){//(p is parent node)
        if(p->right!=NULL){
            cout<<"cannot insert value : "<<val<<" right side already filled..."<<endl;
            return;
        }else{
            Node *newnode=new Node(val);
            p->right=newnode;
        }
    }
    void set_left(Node *p,int val){
        if(p->left!=NULL){
            cout<<"cannot insert value : "<<val<<" left side already filled..."<<endl;
            return;
        }else{
            Node *newnode=new Node(val);
            p->left=newnode;
        }
    }
    
    

    //curr:the node being checked //p:target node// par:parent of node being inspected
    Node *find_parent(Node *curr,Node *p,Node *par){
        if(curr==NULL){
            return NULL;
        }
        if (curr==p){
            return par;
        }
        else{
            Node *t=find_parent(curr->left,p,curr);
            if(t!=NULL){
                return t;
            }else{
                t=find_parent(curr->right,p,curr);
                return t;
            }
        }
    }

    Node *find_sibling(Node *p){
        Node *par=find_parent(root,p,NULL);
        if(par->left==p){
            return par->right;
        }else{
            return par->left;
        }
    }

    int getlevel(Node *curr,int val,int level){
        if(curr==NULL){
            return 0;
        }
        if(curr->data==val){
            return level;
        }
        int l=getlevel(curr->left,val,level+1);
        int r=getlevel(curr->right,val,level+1);

        if(l==0){
            return r;
        } else{
            return l;
        }
        
    }

    int sum_bst(Node *n){
        if(n==NULL){
            return 0;
        }
        else {
            int left_sum= sum_bst(n->left);
            int r_sum=sum_bst(n->right);
            return n->data+left_sum+r_sum;
        } 
    }

int maxDepth(Node* n){  
    if (n == NULL)  
        return -1;  
    else{  
    
        int lDepth = maxDepth(n->left); 
        int rDepth = maxDepth(n->right);  
    
        //cout<<n->data;
        //cout<<lDepth<<"  "<<rDepth<<endl;
    
        /* use the larger one */
        if (lDepth > rDepth)  
            return(lDepth + 1);  
        else return(rDepth + 1);  
    }  
}

void find_duplicates(Node *n ,int n_count[]){
    if(n==NULL){
        return ;
    }
    else{
        n_count[n->data]++;

        if(n_count[n->data]==2){
            cout<<endl<<endl<<"Data of Duplicate Node : "<<n->data<<endl;
        }

        find_duplicates(n->left,n_count);
        find_duplicates(n->right,n_count);

    }
}


void delete_tree(Node *n){
    if(n==NULL){
        return;
    }
    delete_tree(n->left);
    delete_tree(n->right);
    delete n;
}

int sum(Node *n){
    if(n==NULL){
        return 0;
    }else{
        return n->data+sum(n->left)+sum(n->right);
    }
}
int max(Node *n){
    if (n==NULL){
        return 0;
    }
    else{
        int l=max(n->left);
        int r=max(n->right);
        if(n->data>=l&&n->data>=r){
            return n->data;
        }else if (l>=r){
            return l;
        }else{
            return r;
        }

    }
}

int maxx(Node *n,int max){
    if(n==NULL){
        return max;
    }
    if(n->data>max){
        return max=n->data;
    }
    max=maxx(n->left,max);
    max=maxx(n->right,max);
    return max;
}

    Node* findparent2(Node *n,int val){
        if(n==NULL){
            return NULL;
        }
        if(((n->left!=NULL)&&(n->left->data==val))||((n->right!=NULL)&&(n->right->data==val))){
            return n;
        }
        findparent2(n->left,val);
        findparent2(n->right,val);
    }

void display_preorder(Node *n){//n is root node
    if(n==NULL){
        return;
    }else{
        cout<<n->data<<" --> ";
        display_preorder(n->left);
        display_preorder(n->right);
    }
}
    void display_postorder(Node *n){
        if(n==NULL){
            return ;
        }
        else{
            display_postorder(n->left);
            display_postorder(n->right);
            cout<<n->data<<" --> ";
        }
    }
    void display_inorder(Node *n){
        if(n==NULL){
            return;
        }else{
            display_inorder(n->left);
            cout<<n->data<<" --> ";
            display_inorder(n->right);
        }
    }

    bool is_strictly_bt(Node *n){//check if its strictly bianry or not
        if(n==NULL){
            return true;
        }
        if(n->left==NULL&&n->right==NULL){
            return true;
        }
        else if(n->left==NULL||n->right==NULL){
            return false;
        }
        bool c_1=is_strictly_bt(n->left);
        bool c_2=is_strictly_bt(n->right);

        if(c_1==false||c_2==false){
            return false ;
        }else{
            return true;
        }

    }

    int range(Node *n,int max,int min){
        if(n==NULL){
            return;
        }
        if(n->data>max){
            max=n->data;
        }
        if(n->data<min){
            min=n->data;
        }
        range(n->right,max,min);
        range(n->left,max,min);
    }

    void display_max_min(Node *n,int max,int min){
        range(n,max,min);
        cout<<max<<min;
    }

    void make_bst(Node *curr,Node *root){
        if(curr==NULL){
            return;
        }
        if(root=NULL){
            return;
        }
        if(root->left!=NULL){
            if(root->left->data>root->data){
                
            }
        }
    }



};

int main(){
    Binary_tree tree;
    tree.set_root(5);

    Node *root1 = tree.get_root();
    tree.set_left(root1,2);
    tree.set_right(root1,7);

    tree.set_left(root1->right, 3);
    tree.set_right(root1->right, 9);

    tree.set_left(root1->left, 6);
    tree.set_right(root1->left, 1);

    tree.display_preorder(root1);
    cout<<endl;

    //cout<<"is it strictly binary tree : "<<boolalpha<<tree.is_strictly_bt(root1)<<endl;
    //----------------------------------------------------------
    Node *p_node=tree.find_parent(root1,root1->right->left,NULL);
    //cout<<"parent is : "<<p_node->data<<endl;

    //----------------------------------------------------------
    Node *sibling_node=tree.find_sibling(root1->right->left);
    //cout<<"sibling node is : "<<sibling_node->data<<endl;

    //----------------------------------------------------------
    int level=tree.getlevel(root1,88,1);
    //cout<<"level is  : "<<level<<endl;

    //----------------------------------------------------------
    //cout<<"max depth is : "<<tree.maxDepth(root1);

    //-----------------
    int max_val=tree.max(root1);
    //cout<<"max val is : "<<max_val<<endl;

    //-----------------
    int sum_b=tree.sum_bst(root1);
    //cout<<("               ",sum_b);

 

    //----------------------------------------------------------
    //search for duplicates
    // Binary_tree t2;
    // t2.set_root(14);
    // Node *root=t2.get_root();
    // t2.set_left(root,4);
    // t2.set_left(root->left,3);
    // t2.set_right(root->left,9);
    // t2.set_left(root->left->right,7);
    // t2.set_left(root->left->right->left,5);//left side of tree

    // t2.set_right(root,15);
    // t2.set_right(root->right,18);
    // t2.set_left(root->right->right,16);
    // t2.set_right(root->right->right,20);
    // t2.set_right(root->right->right->left,5);

    // cout<<endl<<endl<<"pre-order display : "<<endl;
    // t2.display_preorder(root);
    // cout<<endl<<endl<<"Post order display  : "<<endl;
    // t2.display_postorder(root);
    // cout<<endl<<endl<<"in order display  : "<<endl;
    // t2.display_inorder(root);

    // int n_count[20]={0};
    // t2.find_duplicates(root,n_count);

    // t2.delete_tree(root);

    // cout<<endl<<"After deleting : "<<endl;
    // t2.display_postorder(root);//no output 

    // return 0;

}