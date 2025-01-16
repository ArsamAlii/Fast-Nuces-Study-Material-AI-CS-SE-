#include<iostream>

using namespace std;

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


int main(){
	int array[5]={1,2,3,4,5};
	
	int *ptr=array;
	
	int size=sizeof(array)/sizeof(int);
	
	int maxval,minval;
	
	void (*funcPtr)(int*,int,int*,int*)=&max_min_val;
	
	funcPtr(ptr,size,&maxval,&minval);

	
	cout<<"max value is : "<<maxval<<endl;
	cout<<"min value is :"<<minval;
	
	
	return 0;
	

	
}
