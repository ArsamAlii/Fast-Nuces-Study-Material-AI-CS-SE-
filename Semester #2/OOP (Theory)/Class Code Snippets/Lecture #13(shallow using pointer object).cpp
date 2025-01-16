// finally shallow
#include <iostream>
using namespace std;
class Demo
{
    public:
    int a;
    int b;
    int *p;
    public:
//  Demo()
 //  {
     
 // }
 
 
 
    void setdata(int x,int y,int z)
    {
        p=new int;
        a=x;
        b=y;
        *p=z;
    }
    void showdata()
    {
        std::cout << "value of a is : " <<a<< std::endl;
        std::cout << "value of b is : " <<b<< std::endl;
        std::cout << "value of *p is : " <<*p<< std::endl;
    }
};


 
     


int main()
{

Demo  *dd;
Demo normal_object;
normal_object.setdata(10,10,10);
dd=&normal_object;

Demo  *dd2;
dd2=dd;
cout<<normal_object.a <<" "<<normal_object.b<<" "<<normal_object.p<<" "<<endl;
dd->a=55;
cout<<dd->a <<" "<<dd->b<<" "<<dd->p<<" "<<endl;
cout<<dd2->a<<" "<<dd2->b<<" "<<dd2->p<<" "<<endl;

    return 0;



}