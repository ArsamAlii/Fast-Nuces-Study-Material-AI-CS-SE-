#include <iostream>
#include <string>

using namespace std;

class UAV {
protected:
    string name;
    float weight;
    float maxaltitude;
public:
    UAV(string n, float w, float m):name(n),weight(w),maxaltitude(m){}
    virtual void takeOff(){
        cout<<"Taking off..."<<endl;
    }
    virtual void land(){
        cout<<"Landing..."<<endl;
    }
    void display(){
        cout<<"Name: "<<name<<endl;
        cout<<"Weight: "<<weight<<" kg"<<endl;
        cout<<"Altitude: "<<maxaltitude<<" ft"<<endl;
    }
};

class SurveillanceUAV:virtual public UAV{
protected:
    int zoomlevel;
    int rec_capacity;
    int night_vision; 
public:
    SurveillanceUAV(string n,float w,float m,int z,int r,int night):UAV(n, w, m),zoomlevel(z),rec_capacity(r),night_vision(night){}
    void captureImage(){
        cout<<"Capturing image..."<<endl;
    }
    void recordVideo(){
        cout<<"Recording video..."<<endl;
    }
    void display(){
        UAV::display();
        cout<<"Zoom Level: "<<zoomlevel<<" x"<<endl;
        cout<<"Recording Capacity: "<<rec_capacity<<" GB"<<endl;
        if(night_vision==1){
            cout<<"i have night vision"<<endl;
        }
		else{
            cout<<"i dont have night vision"<<endl;
        }
    }
};

class CargoDeliveryUAV:virtual public UAV{
protected:
    float cargoArea;
public:
    CargoDeliveryUAV(string n,float w,float m,float a):UAV(n,w,m),cargoArea(a){}
    void deliverCargo(){
        cout<<"Delivering cargo..."<<endl;
    }
    void display(){
        UAV::display();
        cout<<"Cargo Area: "<<cargoArea<<endl;
    }
    float getcargoarea(){
    	return cargoArea;
	}
};

class MultiPurposeUAV :public SurveillanceUAV,public CargoDeliveryUAV{
protected:
    float eff_solar;
public:
    MultiPurposeUAV(string n,float w,float m,int z,int r,int night,float a,float s)
	:UAV(n,w,m),SurveillanceUAV(n,w,m,z,r,night),CargoDeliveryUAV(n,w,m,a),eff_solar(s){
	
	}
	
    void deliverCargoWithSurveillance(){
        takeOff();
        recordVideo();
        land();
        deliverCargo();
    }
    void display(){
        
        SurveillanceUAV::display();
        cout<<"my cargoarea is : "<<CargoDeliveryUAV::getcargoarea()<<endl;
        cout<<"Solar Panel Efficiency: "<<eff_solar<<endl;
    }
};

int main() {
	CargoDeliveryUAV cargoDeliveryUAV("multipupose drone",14.5,3000.00,40);
    SurveillanceUAV surveillanceUAV("surveillance drone",16.700,1000,20,3.00,1); // Night vision is on
    MultiPurposeUAV multiPurposeUAV("multi-Purpose drone",10.4,2000,20,5,1,5,5); // Night vision is off
    
	cout<<"i am cargo Delivery UAV:"<<endl;
    cargoDeliveryUAV.display();    
	cargoDeliveryUAV.deliverCargo();
    cout<<endl;
    
    cout<<"i am surveillance UAV:"<<endl;
    surveillanceUAV.display();    
	surveillanceUAV.recordVideo();
    cout<<endl;

    cout<<"i am multi-Purpose UAV:"<<endl;
    multiPurposeUAV.display();
    cout<<endl;



    cout<<"i am going to deliver cargo along wiht surveilance"<<endl;
    multiPurposeUAV.deliverCargoWithSurveillance();

    return 0;
}

