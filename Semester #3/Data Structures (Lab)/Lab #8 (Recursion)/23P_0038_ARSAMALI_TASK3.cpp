#include<iostream>
using namespace std;

int sum_of_digits(int num) {
    if (num == 0) {
        return 0;
    } else {
        return (num%10)+sum_of_digits(num/10);
    }
}

int main() {
    int num;
    cout<<"Enter an integer: ";
    cin>>num;

    cout<<"The sum of the digits is: "<<sum_of_digits(num)<<endl;

    return 0;
}
