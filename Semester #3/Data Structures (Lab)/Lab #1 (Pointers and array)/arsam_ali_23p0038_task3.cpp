#include<iostream>
using namespace std;

void shiftarray(int *ptr1,int size){
	
	int lastval=*(ptr1+size-1);
	
	int *arrsize=ptr1+size-1;
	
	
	for(int *ptr2=arrsize;ptr2>ptr1;ptr2--){
		*ptr2=*(ptr2-1);
	}
	
	*ptr1=lastval;
}

void displayarr(int *ptr1,int size){
	for(int *ptr2=ptr1;ptr2<ptr1+size;ptr2++){
		cout<<*ptr2<<" ";
		
	}
}
int main(){
	int array[5]={1,2,3,4,5};
	
	int *ptr1=array;
	
	int size=sizeof(array)/sizeof(int);
	
	void (*shiftPtr)(int*,int)=&shiftarray;
    void (*displayPtr)(int*,int)=&displayarr;
    
	cout<<"array before shifting is : "<<endl;
	displayPtr(ptr1,size);
	
	shiftPtr(ptr1,size);
	
	cout<<endl<<"array after shifting is : "<<endl;
	displayPtr(ptr1,size);
	
	return 0;
}

