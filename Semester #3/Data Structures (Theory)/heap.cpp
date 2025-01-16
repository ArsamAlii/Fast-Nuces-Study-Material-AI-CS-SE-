#include<iostream>
using namespace std;

class Heap{
    int *h;//point dynamic array
    int capacity;//max size of array
    int length;//no of elements in array

    public:
    Heap(int *arr,int capacity){
        h=new int [capacity];
        this->capacity=capacity;
        length=0;
    }


    void insert(int x) {
        if (length == capacity) {
            cout << "Heap is full!" << endl;
            return;
        }
        length++;
        int i = length;

        while (i > 1 && h[i / 2] > x) {
            h[i] = h[i / 2];
            i /= 2;
        }
        h[i] = x;
    }


    void swap(int &a,int &b){//pass by ref to directly make changes to arr
        a=a+b;
        b=a-b;
        a=a-b;
    }

    void heapify(int i){
        int smallest=i;
        int l=2*i+1;
        int r=2*i +2;

        // If left child is smaller than root 
        if(l<length && h[l]<h[smallest]){
            smallest=l;
        }

        // If right child is smaller than root 
        if(r<length && h[r]<h[smallest]){
            smallest=r;
        }        

        if (smallest != i ){
            swap(h[i],h[smallest]);


            heapify(smallest);//recursive call
        }
    }

    void buildHeap(){//build heap from given array
        int start_index=length/2;

        for(int i=start_index;i>0;i--){
            heapify(i);
        }
    }

    int deletemin(){
        int root=h[1];
        h[1]=h[length];
        length--;
        heapify(1);
        return root;
    }

    void print_heap(){
        for(int i =1;i=length;i++){
            cout<<h[i]<<" ";

        }
        cout<<endl;
    }

};