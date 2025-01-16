#include <iostream>
using namespace std;
// function overloading is also called
// Static binding
//Compile-Time binding
//Early binding
//Method overloading
class Apple{
    public:
        int apple(){
    cout<<"its an parent apple\n";
    return 1;
}



int apple(int a){
    cout<<"its an apple\n";
    return a;
}

int apple(int a,int b){
    cout<<"its an apple\n";
    return a+b;
}

//float apple(){
    //cout<<"its an apple\n";
    //return 1.0;
//}

float apple(float a,float b){
    cout<<"its an apple\n";
    return 2.0;
}

float apple(float a,int b){
    cout<<"its an apple\n";
    return 3.0;
}

float apple(int a,float b){
    cout<<"its an apple\n";
    return 4.0;
}


};

class greenapple: public Apple{
    public:
    void apple(){
        cout<<"iam child class apple"<<endl;
    }
};

int apple(){
    cout<<"its an apple\n";
    return 1;
}

int apple(int a){
    cout<<"its an apple\n";
    return a;
}

int apple(int a,int b){
    cout<<"its an apple\n";
    return a+b;
}

//float apple(){
    //cout<<"its an apple\n";
    //return 1.0;
//}

float apple(float a,float b){
    cout<<"its an apple\n";
    return 2.0;
}

float apple(float a,int b){
    cout<<"its an apple\n";
    return 3.0;
}

float apple(int a,float b){
    cout<<"its an apple\n";
    return 4.0;
}


int main() {
    apple();
    apple(1,2);
    float hexa=3.5;
    apple(hexa,2.1000f);
    apple(3,3.f);
    apple(3.0f,3);
    cout<<"objects\n"<<endl;
    Apple a1;
//    a1.apple();
    a1.apple(2.0f,3.0f);
    a1.apple(5);
    greenapple g1;
    g1.apple();
   
    return 0;
}