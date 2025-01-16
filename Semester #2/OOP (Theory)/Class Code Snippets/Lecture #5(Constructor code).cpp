#include <iostream>
#include <string>
using namespace std;
class Hospital {
public:
 string name;
 int numBeds;
public:

Hospital();


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
 // Copy Constructor Hospital(const Hospital &h) { name = h.name;
// numBeds = h.numBeds;
 // cout << "Copy constructor called." << endl; }
 
// Method to display hospital information
 void display() {
cout << "Hospital Name: " << name << endl;
cout << "Number of Beds: " << numBeds << endl;
 }

};

Hospital ::Hospital(){
    name = "Default Hospital";
 numBeds = 100;
 cout << "Default constructor called." << endl;
 }


int main(){
// Using the default constructor
 Hospital defaultHospital;

  defaultHospital.display();
//Using the parameterized constructor
 Hospital paramHospital("General Hospital", 200);
 paramHospital.display();
 // Using the copy constructor
//  Hospital copyHospital(paramHospital); copyHospital.display();
 return 0;
 }