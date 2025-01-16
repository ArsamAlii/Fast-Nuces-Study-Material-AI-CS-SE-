#include<iostream>
using namespace std;
//front del //rear insert
class Queue{
    private:
    int *arr;
    int capacity;
    int front;
    int length;
    int rear;

    public:
    Queue(int size){
        arr=new int [size];
        capacity=size;
        length=0;
        front=0;
        rear=-1;
    }


    void Enqueue(int val){
        if(length==capacity){
            cout<<"size id full cannot add more values."<<endl<<endl;
            return;
        }
        if((rear+1)==capacity){
            rear=0;
        }else{
            rear++;
        }
        arr[rear]=val;
        length++;
    }

    int dequeue(){
        if(length==0){
            cout<<"Queue underflow"<<endl<<endl;
            return 0;
        }
        int val=arr[front];
        if((front+1)==capacity){
            front=0;
        }else{
            front++;
        }
        length--;
        return val;
    }

    void display(){
        if(length==0){
            cout<<"queue is empty.";
            return;
        }
        int index=front;
        for(int i = 0;i<length;i++){
            cout<<arr[index]<<" ";
            index=(index+1)%capacity;
        }
        cout<<endl;
    }

    ~Queue(){
        delete [] arr;
    }
};

int main(){
    Queue q1(5);

    q1.Enqueue(1);
    q1.Enqueue(2);
    q1.Enqueue(3);
    q1.Enqueue(4);
    q1.Enqueue(5);
    q1.display();

    q1.dequeue();
    q1.dequeue();
    q1.dequeue();
    q1.display();
    return 0;
}