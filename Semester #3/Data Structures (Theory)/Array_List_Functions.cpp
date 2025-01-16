#include<iostream>
using namespace std;

class Arraylist{
    public:
    int *arr;
    int *curr;
    int length;
    int capacity;
    public:
    Arraylist(int size){
        arr=new int [size];
        curr=NULL;
        length=0;
        capacity=size;
    }
    ~Arraylist(){
        delete []arr;
    }
    void start(){
        curr=arr;
    }
    void tail(){
        curr=arr+length-1;
    }
    void next(){
        curr++;
    }
    void prev(){
        curr--;
    }
    void add(int val){
        if(length<capacity){
            *(arr+length)=val;
            length++;
        }
        else{
            cout<<"array is full ";
        }
    }
    void insert(int val,int pos){
        if(length==capacity){
            cout<<"array is full";
            return;
        }
        if(pos<1||pos>length+1){
            cout<<"invalid postion";
            return;
        }
        tail();
        for(int i=length;i>=pos;i--){
            *(curr+1)=*curr;
            prev();
        }
        *(curr+1)=val;
        length++;
    }
    void remove(int pos){
        if(length==0){
            cout<<"array is empty";
            return;
        }
        if(pos<1||pos>length){
            cout<<"invalid legnth";
            return;
        }
        curr=arr+pos-1;
        for(int i=pos;i<length;i++){
            *curr=*(curr+1);
            next();
        }
        length--;
    }
    int get(int pos){
        if(length==0){
            cout<<"array is empty";
             return 0;
        }
        if(pos<1||pos>length){
            cout<<"invalid position entered";
            return 0;
        }
        curr=arr+pos-1;
        
        return *curr;
    }
    void update(int val,int pos){
         if(length==0){
            cout<<"array is empty";
            return;
        }
        if(pos<1||pos>length){
            cout<<"invalid position entered";
            return;
        }    
        curr=arr+pos-1;
        *curr=val;

    }
    int find(int val){
        if(length==0){
            cout<<"array is empty";
            return 0;
        }

        start();
        for(int i=1;i<=length;i++){
            if(*curr=val){
                return i;
            }
            next();
        }
        return false;
    }

//--------user to provide val which is to be removed
    void v_remove(int val){
        if(length==0){
            cout<<"array is empty";
            return ;
        }

        int pos=find(val);
        while((pos=find(val))!=0){
            remove(pos);
        }
    }

	void display(){
		for(int *ptr=arr;ptr<arr+length;ptr++){
			cout<<*ptr<<" ";
		}
		cout<<endl;
	}

    void checktail(){
        tail();

        int *temp=arr;

        while(temp<curr){
            cout<<*temp;
            cout<<*curr;
            curr--;
            temp++;
        }
    }

    void reverse_arr(){
        tail();
        int *temp=arr;

        while(temp<curr){
         //a=15 b=5 a=a+b=20,b=a-b=15,a=a-b
        *temp=*temp+*curr;
        *curr=*temp-*curr;
        *temp=*temp-*curr;
        temp++;
        curr--;
        }
        
    }



};


int main(){

    Arraylist l1(10);

    l1.add(1);
    l1.add(3);
    l1.add(5);
    l1.add(7);
    l1.add(9);


    cout << "Array after adding elements: ";
    l1.display();

    l1.insert(4, 3);
    cout << "Array after inserting 4 at position 3: ";
    l1.display();

    l1.remove(2);
    cout << "Array after removing element at position 2: ";
    l1.display();

    int val = l1.get(3);
    cout<<"Value at position 3: "<<val<<endl;

    l1.update(10, 2);
    cout<<"Array after updating value at position 2 to 10: ";
    l1.display();

    int pos = l1.find(10);
    if (pos != 0){
        cout<<"Value 10 found at position: " << pos << endl;
    } else{
        cout<<"Value 10 not found." << endl;
    }

    l1.v_remove(10);
    cout<<"Array after removing all occurrences of value 10: ";
    l1.display();

    l1.reverse_arr();
    cout<<"Array after reversing: ";
    l1.display();

    return 0;
}
