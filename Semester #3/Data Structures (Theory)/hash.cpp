#include<iostream>
using namespace std;

class hash_table{
    private:
    int *h_table;
    int size;
    int range_min;
    int range_max;
    int count;

    public:
    hash_table(int *arr,int size,int min,int max){
        range_min=min;
        range_max=max;
        h_table=new int [size];
        for (int i=0;i<size;i++){
            h_table[i]=-1;
        }
    }

    void insert(int val){
        if(val<range_min||val>range_max){
            cout<<"Value "<<val<<" is out of range."<<endl;
            return ;
        }
        int index=val%size;

        while(h_table[index]!=-1){
            index=index+1%size;
        }

        h_table[index]=val;
        count++;

        float loadfactor=float(count/size);

        if (loadfactor>0.7){
            rehash();
        }
        
    }

    void rehash(){
        cout<<"rehashing the table now ."<<endl;
        int new_size=size*2;

        int *newtable=new int [new_size];

        for(int i = 0 ; i<new_size; i++){
            newtable[i]=-1;
        }

        for(int i = 0 ; i < size ; i++){
            if(h_table[i]!=-1){
                int val=h_table[i];
                int new_tbl_index=val%new_size;

                while(newtable[new_tbl_index]!=-1){
                    new_tbl_index=new_tbl_index%new_size;
                }
                newtable[new_tbl_index]=val;
            }   
        }
        delete [] h_table;
        h_table=newtable;
        cout<<"REHASING COMPLETED..."<<endl;
    }

    bool search(int val){
        if(size==0){
            cout<<"no elements in table to search"<<endl;
            return false;
        }
        int index=val%size;
        int start_index=index;

        while(h_table[index]!=-1){
            if(h_table[index]==val){
                return true;
            }
            index=(index+1)%size;

            if(index==start_index){
                break;
            }
        }
        return false;
    }

    void display(){
        cout<<"OUTPUT HASH TABLE : "<<endl;
        for(int i=0;i<size;i++){
            if(h_table[i]==-1){
                cout<<"-";
            }else{
                cout<<h_table[i]<<" ";
            }
        }
        cout<<endl<<endl;
    }
    
};


int main(){
    

    return 0;
}