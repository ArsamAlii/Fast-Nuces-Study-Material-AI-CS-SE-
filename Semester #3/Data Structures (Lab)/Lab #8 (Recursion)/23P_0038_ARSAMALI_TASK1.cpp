#include<iostream>
using namespace std;

int recur_multiply(int a,int b){
    if(b==0){
        return 0;
    }else{
        return  a+recur_multiply(a,b-1);
    }
}
int main(){

    int a,b;

    do{
        cout<<"Enter a positive val to multiply : ";
        cin>>a;
        cout<<endl<<"Enter second value to multiply : ";
        cin>>b;
        if(a<0||b<0){
            cout<<endl<<"Enter only positive values. "<<endl<<endl;
            cout<<"-------------------"<<endl<<endl;
        }
    }while(a<0||b<0);


    int mul=recur_multiply(a,b);
    cout<<endl<<"Multiplication using recursion is : "<<mul<<endl<<endl;
    cout<<"-------------------"<<endl<<endl;
    return 0;
}