#include<iostream>
using namespace std;

int recursive_seq(int seq){
    if(seq==0){
        return 0;
    }else if(seq==1){
        return 1;
    }else{
        return recursive_seq(seq-1)+recursive_seq(seq-2);
    }

}

int main(){


    int num;
    do{
        cout<<"enter a number to find its fibonacci val : ";
        cin>>num;
        if(num<0){
            cout<<"----------enter only positive values pls.-------"<<endl;
        }
    }while(num<0);

    cout<<"fibonacci val is : "<<recursive_seq(num);

    return 0;
}