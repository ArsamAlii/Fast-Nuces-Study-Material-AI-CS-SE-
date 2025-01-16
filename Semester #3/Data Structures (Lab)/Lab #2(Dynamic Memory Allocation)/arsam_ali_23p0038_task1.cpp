#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
int findTopSellingProduct(int *ptr,int size){
	int max=*ptr;
	for(int i=1;i<size;i++){
        if (*(ptr+i)>max){
            max=*(ptr+i);
        }
	}
	return max;
}

int findsecondtopsellingproduct(int *ptr,int size,int topSelling){
    int secondMax = -1;

    for (int i=0;i<size;i++){
        if(*(ptr+i)<topSelling && (*(ptr+i)>secondMax)){
            secondMax=*(ptr+i);
        }
    }

    return secondMax;
}


void sortbypopularity(int *ptr, int size) {
    for (int *ptrr=ptr;ptrr<ptr+size-1;ptrr++){
        for (int *current=ptr;current<ptr+size-1;++current){
            if (*current>*(current+1)){
                int temp=*current;
                *current=*(current + 1);
                *(current + 1)=temp;
            }
        }
    }

    for (int *ptr1=ptr;ptr1<ptr+size;++ptr1){
        cout << *ptr1 << " ";
    }
    cout << endl;
}


float find_avg(int *inventory_arr,int size){
	float sum=0;
    for(int *ptr=inventory_arr;ptr<inventory_arr+size;ptr++){
       sum=sum+*ptr;
    }	
    
    float average=sum/size;
    
    return average;
    
}

int* identifyCriticalPoints(int *inventoryArr,int size,float avg,int &count){
    count = 0;
    for (int i=0;i<size;i++){
        if (*(inventoryArr+i)<avg){
            count++;
        }
    }

    int *positions=new int[count];
    int index=0;
    for (int i=0;i<size;i++){
        if(*(inventoryArr+i)<avg){
            positions[index++]=i;
        }
    }
    return positions;
}

int main(){
    int size;
    cout<<"Enter your desired size of array: ";
    cin>>size;

    int *inventory_arr=new int[size];

    srand(time(0));

    
    for(int *ptr=inventory_arr;ptr<inventory_arr+size;ptr++){
        int random_number=rand()%100;
        *ptr=random_number;
    }
    
    cout<<endl<<"random num generated are: ";
    for(int *ptr =inventory_arr;ptr<inventory_arr+size;ptr++){
        cout<<*ptr<<"  ";
    }

	float avg = find_avg(inventory_arr,size);
	
	cout<<endl<<endl<<"Average is :"<<avg<<endl;


	int c_count;
	int *criticalPositions=identifyCriticalPoints(inventory_arr,size,avg,c_count);
	
	cout<<"Number of critically low products: "<<c_count<<endl<<endl;
	
    cout << "Positions of critically low products: ";
    for (int *ptr2 = criticalPositions; ptr2<criticalPositions+c_count;ptr2++) {
        cout << *ptr2+1<< " ";
    }
    cout << endl;

    int topselling=findTopSellingProduct(inventory_arr,size);
    cout<<"top selling product is "<<topselling;
    
    int sec_topselling=findsecondtopsellingproduct(inventory_arr,size,topselling);
    
    cout<<endl<<"second top selling is : "<<sec_topselling<<endl<<endl;
    
    sortbypopularity(inventory_arr,size);



    return 0;
}

