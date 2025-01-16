#include <iostream>
#include <string>
// what happens to constructor and destructor in inheritance
using namespace std;
class parent{
    public:
        string name;
        parent(){
            cout<<"iam parent constructor"<<endl;
            name="gudu";
        }
       
        parent(string k){
        name=k;
        cout<<"iam parent parameterized constructor"<<endl;
        }
       
       
        ~parent(){
            cout<<"iam parent destructor"<<endl;
        }
       
       
       
       
};

class child:public parent{
    public:
    int age;
    child(){
            cout<<"iam child constructor"<<endl;
        }
       
            child(int k,string j):parent(j){
            age=k;
        //    name=j;
        cout<<"iam child parameterized constructor"<<endl;
        }
       
   
        ~child(){
            cout<<"iam child destructor"<<endl;
        }
       
};

    void iamcreatingobjects(){
    //    parent p1;
        child c1(50,"bacha");
        cout<<"\n"<<c1.age<<" name is"<<c1.name;
       
    }


int main() {

    iamcreatingobjects();
   
   
    return 0;
}