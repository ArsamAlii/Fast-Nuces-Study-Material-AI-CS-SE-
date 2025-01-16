#include<iostream>
using namespace std;

class Node{
    int data;
    Node *next;
    public:
    Node(int data){
        next=NULL;
        this->data=data;
    }
    friend class Queue;
};

class Queue{
    Node *f;
    Node *r;

    public:
    Queue(){
        f=NULL;
        r=NULL;
    }

    void Enqueue(int val){
        Node *n=new Node (val);
        if(f!=NULL&&r!=NULL){//if there are elements existing in queue
            r->next=n;
            r=n;
        }else{//if no elements in queue
            f=n;
            r=n;
        }
    }


    int Dequeue(){
        if(f==NULL){
            cout<<"queue underflow."<<endl<<endl;
        }
        else{
            int val=f->data;
            Node *curr=f;
            f=f->next;
            if(f==NULL){
                r=NULL;
            }
            delete curr;
            return val;
        }
    }

    // void moveNthFront(int n) {
    //     if (n < 1 || n > count) {
    //         cout << "Invalid position " << n << endl;
    //         return;
    //     }

    //     // Calculate the actual position of the nth element
    //     int index = (front + n - 1) % capacity;

    //     // Store the nth element
    //     int nthElement = arr[index];

    //     // Shift elements to preserve order
    //     for (int i = index; i != front; i = (i - 1 + capacity) % capacity) {
    //         arr[i] = arr[(i - 1 + capacity) % capacity];
    //     }

    //     // Place nth element at the front
    //     arr[front] = nthElement;
    // }

    void Display() {
        if (f == NULL) {
            cout << "Queue is empty" << endl;
            return;
        }
        Node* temp = f;
        cout << "Queue: ";
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main(){
    Queue l1;
    l1.Enqueue(1);
    l1.Enqueue(2);
    l1.Enqueue(3);

    l1.Dequeue();
    l1.Dequeue();
    // l1.Dequeue();
    // l1.Dequeue();
    
    l1.Display();
    return 0;
}