#include <iostream>  
using namespace std;  
class A  
{  
   
    int x;  
      public:  
      A(){}  
    A(int i)  
    {  
       x=i;  
    }  
    int operator+(A);  
     int operator*(A);
};  
 
int A :: operator+(A a)  
{  
     
    int m = x+a.x;  
   // cout<<"The result of the addition of two objects is : "<<m;  
      return m;
}  

int A :: operator*(A a)  
{  
     
    int m = x*a.x;  
  //  cout<<"The result of the mul of two objects is : "<<m;  
      return m;
}

int main()  
{  
    A a1(5);  
    A a2(4);
    A a3(10);
    cout<<(a1+a2*a3);  
    return 0;  
}