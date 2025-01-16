#include <iostream>
using namespace std;

namespace outer_namespace
{
    void func()
    {
        cout<<"inside outer namespace"<<endl;
    }
    namespace inner_namespace
    {
        void func()
        {
            cout<<"inside inner namespace"<<endl;
        }
    }

}



int main()
{




 //outer_namespace::func();
 //outer_namespace::inner_namespace::func();

    cout<<"just nothing !";

    return 0;
}