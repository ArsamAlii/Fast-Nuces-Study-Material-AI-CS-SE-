#include <iostream>
using namespace std;

namespace first_namespace{
void func(){
    cout<<"inside first namespace"<<endl;
}
}
namespace second_namespace{
void func(){
    cout<<"inside second namespace"<<endl;
}
}


int main()
{


 using namespace first_namespace;
func();
  //first_namespace::func();

 
    cout<<"just nothing !";
    second_namespace::func();
    return 0;
}