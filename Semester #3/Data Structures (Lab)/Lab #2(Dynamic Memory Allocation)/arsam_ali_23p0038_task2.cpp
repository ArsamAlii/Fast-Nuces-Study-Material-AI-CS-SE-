#include<iostream>
using namespace std;

char* getchar(char *ptr,int s_index,int e_index){
	int diff=e_index-s_index;
	char* user_arr = new char [diff];
	
	char* start_ptr=ptr+s_index;
	char* temp_ptr=user_arr;
	
	for(char *c_ptr=start_ptr;c_ptr<=ptr+e_index;c_ptr++){
		*temp_ptr=*c_ptr;
		temp_ptr++;
	}
	
	return user_arr;
}

int main(){
	int size;
	
	cout<<"enter the size of character array : ";
	cin>>size;
	
	char* char_arr= new char [size+1];
	
	cin.ignore();
	
	cout<<"enter "<<size<< " character :";
	cin.getline(char_arr,size+1);
	
	
	cout<<"you entered : "<<char_arr<<endl;
	
	int s_index;
	cout<<"enter start index ";
	cin>>s_index;
	
	int e_index;
	cout<<"enter end index : ";
	cin>>e_index;
	
	char* result=getchar(char_arr,s_index,e_index);
	
	cout<<"the final result is : "<<result<<endl;
	
	delete [] char_arr;
	delete [] result;
	
	return 0;
	
}
