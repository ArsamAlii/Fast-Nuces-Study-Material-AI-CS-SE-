/*
The behavior you're observing, where variables
are not initialized to zero by a constructor,
can be attributed to the way C++ handles default
 initialization and zero initialization. When a
 constructor is not explicitly defined, C++ does
 not automatically zero-initialize all member variables.
  Instead, it performs default initialization, which
  leaves the variables in an unspecified state if
  they are not explicitly initialized. This can lead
  to unpredictable values being assigned to the variables,
   including non-zero values.
*/
#include <iostream>
#include <string>
using namespace std;
class Hospital {
public:
 string name;
 int numBeds;
public:
//Hospital();

// Default Constructor
 Hospital() {
name = "Default Hospital";
 numBeds = 100;
 cout << "Default constructor called." << endl;
 }
 
 // Parameterized Constructor
Hospital(string n, int b) {
 name = n;
numBeds = b;
 cout << "Parameterized constructor called." << endl;}
 // Copy Constructor
  Hospital(const Hospital &h)
   {
   name = h.name;
 numBeds = h.numBeds;
  cout << "Copy constructor called." << endl;
   }
 
// Method to display hospital information
 void display() {
cout << "Hospital Name: " << name << endl;
cout << "Number of Beds: " << numBeds << endl;
 }

};
/*
Hospital ::Hospital(){
    name = "Default Hospital";
 numBeds = 100;
 cout << "Default constructor called." << endl;
 }
}*/

int main() {
    int x,noh;
    cout<<"enter no of hospitals you want"<<endl;
    cin>>noh; // no of hospitals
        Hospital hos[noh];
        for(x=0;x<noh;x++){
        cout<<"enter name of hospital"<<endl;
//    hos[x].name=
        cin.ignore() ;
        getline(cin,hos[x].name);
    //    cin>>hos[x].name;
        cout<<"enter num of beds"<<endl;
        cin>>hos[x].numBeds;

    }
for(x=0;x<noh;x++){
                hos[x].display();
            }
   
    /*
// Using the default constructor
 Hospital defaultHospital;

  defaultHospital.display();
 //Using the parameterized constructor
 Hospital paramHospital("General Hospital", 200);
 paramHospital.display();
 
 
 // Using the copy constructor
 Hospital copyHospital(paramHospital);
 copyHospital.display();
 
 Hospital secondcopy(copyHospital);
 secondcopy.display();
 secondcopy.name="now iam second copy";
  secondcopy.display();

 */
 return 0;
 
 
 }