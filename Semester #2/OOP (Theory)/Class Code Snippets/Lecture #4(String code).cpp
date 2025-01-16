#include <iostream>
#include <string>
using namespace std;
int main()
{
 
  string string1 = "welcome";
  cout << string1 << endl;
  // output the size of the string (i.e. number of characters)
  cout << "size: " << string1.size() << endl;

 
  // we can modify individual characters in the string with the [] syntax too
  string1[2] = 'C';
  cout << string1 << endl;
 
  // there are several ways to concatenate and append strings
  string1 = string1 + "jklmnop";
  string1 += "qrstu";
  string1.append("vwxyz");
  cout << string1 << endl;
 
  // the length() function is a synonym for size(), it returns the same value
  cout << "length: " << string1.length() << endl;
 
  // we can create more string type variables
  string string2 = "123";
  string test3;
 
  // we can concatenate string variables, not just string literals
  test3 = string1 + string2;
  cout << "string3: " << test3 << endl;
 
  // empty() will check if a string is empty (string3 should not be)
  if (test3.empty()) cout << "string3 is empty" << endl;
  else cout << "string3 is not empty" << endl;
 
  // clear() will make a string empty
  test3.clear();
  cout << "string3: " << test3 << endl;
 
  // string3 should now be empty!
  if (test3.empty()) cout << "string3 is empty" << endl;
  else cout << "string3 is not empty" << endl;
 
  // we can convert values like ints and doubles to strings using to_string()
  string string4 = to_string(-10.5);
  cout << string4 << endl;
 
  // we can convert double values to strings using stod(), other functions
  // exist to convert other types as well
  // DONT WORRY WE WILL HAVE CLASS ON TYPE CASTING
  double number = stod(string4);
  cout << "number: " << number << endl;
 
  // many functions exist for working with strings, for example we can
  // extract a substring from a string using substr, which in this case
  // extracts 4 characters starting from the character at index 2
  string string5 = "A test string";
  string sub = string5.substr(2,4);
  cout << "sub: " << sub << endl;
 
  // we can store use input into a string type variable, for example a name
  string name;
  cout << "Enter name: ";

  // will only store the string up until the first space character, so a
  // name like 'raqeeb' will only be stored as 'raqeeb' into name  
  //cin >> name;

  // will store the string up until the first newline character into name,
  // so a name like 'raqeeb lashari' :) will be stored entirely
  getline(cin, name);

  // output the name
  cout << "Name: " << name << endl;

  return 0;
}