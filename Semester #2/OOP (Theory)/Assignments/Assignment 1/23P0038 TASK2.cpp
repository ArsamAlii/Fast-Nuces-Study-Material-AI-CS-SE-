#include <iostream>
#include <string>

using namespace std;

class Robot{
private:
    int uniqueid;
    string type;
    string ps;
    float max_speed;
    float weight;

public:
    
    Robot(){}
    
    Robot(int id,const string& robotType,const string& source,float speed,float robotWeight){
        uniqueid=id;
        type=robotType;
        ps=source;
        max_speed=speed;
        weight=robotWeight;
    }

   
    ~Robot(){
        cout<<"Robot with unique id: "<<uniqueid<<" has been destructed\n";
    }

    
    Robot(const Robot& other){
    	uniqueid=other.uniqueid;
    	max_speed=other.max_speed;
    	weight=other.weight;
        type=other.type;
        ps=other.ps;
    }

    void display(){
        cout<< "Robot ID: "<<uniqueid<<endl;
        cout<< "Type: "<<type<<endl;
        cout<<"Power Source: "<<ps<<endl;
        cout<<"Max Speed: "<<max_speed<<" m/s"<<endl;
        cout<<"Weight: "<<weight<<" kg"<<endl;
        cout<<endl;
    }
};


void shallowCopy(Robot* destination,const Robot* source,int arraysize) {
    for(int i=0;i<arraysize;++i){
        destination[i]=source[i]; 
    }
}


void deepCopy(Robot*destination,const Robot* source,int arraysize){
    for(int i=0;i<arraysize;++i){
        destination[i]=Robot(source[i]);
    }
}

int main() {
    int size=3;
    Robot orig_robots[size]={
        Robot(0001,"industrial","battery",8.5,155.0),
        Robot(0002,"humanoid", "solar",10.5,102.0),
        Robot(0003,"aerial","fuel",50.0,203.0)
    };

    cout<<"Original Robot Details:"<<endl; 
     for(int i=0;i<size;++i){
        orig_robots[i].display();
    }


	
	 cout << "Original Robot Addresses:"<<endl;
	 
    for (int i=0;i<size;++i){
        cout<<"orig_robots["<< i <<"]: "<<&orig_robots[i]<<endl;
    }
    
    cout<<"------------------------"<<endl;
    for(int i=0;i<size;++i){
        orig_robots[i].display();
    }


    Robot shallowcrobots[size];
    Robot deepcopyrobots[size];

    shallowCopy(shallowcrobots,orig_robots,size);
    
    cout<<"Shallow Copied Robot Details:"<<endl;
    
    cout<<"\nShallow Copied Robot Addresses:"<<endl;
    for(int i=0;i<size;++i) {
        cout<<"shallowcrobots["<<i << "]: " << &shallowcrobots[i] << endl;
    }
    cout<<"-----------------------------"<<endl;
    for(int i=0;i<size;++i){
        shallowcrobots[i].display();
    }

    
    deepCopy(deepcopyrobots,orig_robots,size);
    cout<<"Deep Copied Robot Details:"<<endl;
    cout<<"--------------------------"<<endl;
    for (int i=0;i<size;++i){
        deepcopyrobots[i].display();
    }
    
    cout << "\nDeep Copied Robot Addresses:" << endl;
		for(int i=0;i<size;++i){
    cout <<"deepcopyrobots["<<i<< "]: "<<&deepcopyrobots[i]<<endl;
}
    

    return 0;
}

