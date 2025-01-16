#include<iostream>
using namespace std;

void reversearray(int *ptr1,int *ptr2){
		while(ptr1<ptr2){
		*ptr1=*ptr1+*ptr2;
		*ptr2=*ptr1-*ptr2;
		*ptr1=*ptr1-*ptr2;
		
		
		ptr1++;
		ptr2--;
	}
	
}
void max_min_val(int *ptr,int size,int *maxval,int *minval){
	int*max=ptr;
	int *min=ptr;
	for(int *ptr2=ptr;ptr2<ptr+size;ptr2++){
		if(*ptr2>*max){
			 max=ptr2;
				 
		}
		if(*ptr2<*min){
			 min=ptr2;
			
		}
		
	}	
*maxval=*max;
*minval=*min;
	
}
void shiftarray(int *ptr1,int size){
	
	int *lastval=new int;
	 *lastval=*(ptr1+size-1);
	
	int *arrsize=ptr1+size-1;
	
	
	for(int *ptr2=arrsize;ptr2>ptr1;ptr2--){
		*ptr2=*(ptr2-1);
	}
	
	*ptr1=*lastval;
}
void displayarray(int*ptr1,int size){
		for(int *ptr3=ptr1;ptr3<ptr1+size;++ptr3){
		cout<<*ptr3;
		cout<<" ";
	}
}



int main(){
//reversing
	int array[5]={1,2,3,4,5};
	int *ptr1=array;
	//ptr1 = array;
	
	int size=sizeof(array)/sizeof(int);
	
	void (*reversePtr)(int*,int*)=&reversearray;
    void (*displayPtr)(int*,int)=&displayarray;
	
	cout<<"orignal array is : "<<endl;
	displayPtr(ptr1,size);
	
	cout<<endl<<"after reverse array is: "<<endl;
	int *ptr2=array+size-1;
	
	reversePtr(ptr1,ptr2);
	 
	displayPtr(ptr1,size);
	
////////////////min and max value

	void (*funcPtr)(int*,int,int*,int*)=&max_min_val;
	
	int maxval,minval;
	funcPtr(ptr1,size,&maxval,&minval);

	
	cout<<endl<<endl<<"max value is : "<<maxval<<endl;
	cout<<"min value is :"<<minval<<endl<<endl;
	
////////////shifting

	void (*shiftPtr)(int*,int)=&shiftarray;

    
	cout<<"array before shifting is : "<<endl;
	displayPtr(ptr1,size);
	
	shiftPtr(ptr1,size);
	
	cout<<endl<<"array after shifting is : "<<endl;
	displayPtr(ptr1,size);
	
	return 0;
}
