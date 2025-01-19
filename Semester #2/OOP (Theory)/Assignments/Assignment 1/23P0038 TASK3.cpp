#include <iostream>
#include <string>

using namespace std;

class AutonomousVehicle{
protected:
    int *uniqueid;
    string type;
    int batterycapacity;
    float maxspeed;

public:
	AutonomousVehicle(){}
    AutonomousVehicle(int i,const string &type,int batterycapacity,float maxspeed)
	{
        uniqueid=new int(i);
        this->type=type;
        this->batterycapacity=batterycapacity;
        this->maxspeed=maxspeed;
    }

//    AutonomousVehicle(const AutonomousVehicle &other){
//        uniqueid=new int(*other.uniqueid);
//        type=other.type;
//        batterycapacity=other.batterycapacity;
//        maxspeed=other.maxspeed;
//    }

    ~AutonomousVehicle(){
        delete uniqueid;
    }

    void display(){
        cout<<"ID: "<<*uniqueid<<endl;
        cout<<"Type: "<<type<<endl;
        cout<<"Battery Capacity: "<<batterycapacity<<" kg"<<endl;
        cout<<"Max Speed: " <<maxspeed<<" m/s"<<endl;
        cout<<"Address: " <<uniqueid<<endl;

        cout << endl;
    }
};

class car : protected AutonomousVehicle{
public:
	car(){}
	
    car(int uniqueid, const string type,int batterycapacity,float maxspeed)
        : AutonomousVehicle(uniqueid,type,batterycapacity,maxspeed){
    }
    void display(){
	AutonomousVehicle::display();
	}
};

class truck :protected AutonomousVehicle{
public:
	truck(){}
    truck(int uniqueid, const string type, int batterycapacity, float maxspeed)
        : AutonomousVehicle(uniqueid,type,batterycapacity,maxspeed){
    }
    void display(){
	AutonomousVehicle::display();
	}
};

int main(){
    car c1(1234,"sedan",234,444);
    cout<<"Original car is : "<<endl;
    c1.display();

    car deepcopiedcar=c1;
    car shallowcopiedcar;
	shallowcopiedcar=c1;

    cout<<"Shallow copied car is :"<<endl;
    shallowcopiedcar.display();
    cout<<"Deep copied car is :"<<endl;
    deepcopiedcar.display();

    truck t1(4567,"truck",546,324);
    cout<<"Original truck is :"<<endl;
    t1.display();

    truck deepcopiedtruck=t1;
    truck shallowcopiedtruck;
	shallowcopiedtruck=t1;

    cout<<"Shallow copied truck is :"<<endl;
    shallowcopiedtruck.display();
    cout<<"Deep copied truck is :"<<endl;
    deepcopiedtruck.display();

    return 0;
}

