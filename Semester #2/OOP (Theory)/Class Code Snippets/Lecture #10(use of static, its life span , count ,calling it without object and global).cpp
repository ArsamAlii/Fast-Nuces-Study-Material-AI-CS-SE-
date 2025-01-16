#include <iostream>
#include <string>
using namespace std;

//int counter=0;
// learning static

class jaraseem{
    public:
    string naam;
    string maqsad;
    static int tadad;
    int age;
    jaraseem(){
        naam="jarsuma";
        age=0;
        maqsad="bemari";
        tadad++;
    //    counter++;
    }
   
    void infect(){
        cout<<"main jaraseem hoon"<<endl;
    }
   
    ~jaraseem(){
        cout<<"Oii na maro"<<endl;
    }
   
};

//

void statjaraseem_bnao(){
    static jaraseem motu;
}


void nonstatjaraseem_bnao(){
     jaraseem patlu;
}


//



 class safeguard{
     public:
         string name;
         static int countofguards;
     safeguard(){
    name="commander safeguard";
    countofguards++;
//    counter=100;
     }
     
static void disinfect(){
         cout<<"kill jaraseem"<<endl;
     }
         
 };

int safeguard::countofguards=0;
int jaraseem:: tadad=0;



int main() {
    statjaraseem_bnao();
    nonstatjaraseem_bnao();
    safeguard::disinfect();
//    jaraseem j1,j2,j3;


   
//    j1.infect();
//    cout<<jaraseem::tadad;
//    j2.infect();
//    j3.infect();
    safeguard c1;
    c1.countofguards=50;
   

//    cout<<j1.tadad<<endl;
    cout<<c1.countofguards<<endl;
//    cout<<"\n jaraseem count using global = "<<counter<<endl;
       
    cout<<"Program khatam ...program tou ..."<<endl;
    return 0;
}