#include <iostream>
#include <string>

using namespace std;

class ReadingMaterial{
protected:
    string title;
    string author;

public:
    ReadingMaterial(const string& title,const string& author):title(title),author(author){}

     void displayInfo(){
        cout<<"Title: "<<title<<endl<<"Author: "<<author<<endl;
    }
};

class Book:virtual public ReadingMaterial{
protected:
    int pagecount;

public:
    Book(const string& title,const string& author,int pagecount):ReadingMaterial(title,author),pagecount(pagecount){}

    void readPage(int pageNum){
        cout<<"Reading page "<<pageNum<<" of the book."<<endl;
    }

     void calculatespeed(){
        cout<<"class book read time "<<endl;
    }
};

class Magazine:virtual public ReadingMaterial{
protected:
    int pagecount;

public:
    Magazine(const string& title,const string& author,int pagecount):ReadingMaterial(title,author),pagecount(pagecount){}

    void browseSection(int sectionNum){
        cout<<"browsing section "<<sectionNum<<" of class magazine."<<endl;
    }

     void calculatespeed(){
        cout<<"class magazine speed."<<endl;
    }
};

class ReferenceMaterial:public Book,public Magazine{
public:
    ReferenceMaterial(const string& title,const string& author,int pagecount):ReadingMaterial(title,author),Book(title,author,pagecount),Magazine(title,author,pagecount){}

    void displayInfo(){
        cout<<"Reference Material: "<<endl;
        ReadingMaterial::displayInfo();
        cout<<"page count is : "<<Book::pagecount<<endl;
    }

    void calculatespeed(){
    	//cout<<"this is caleed";
        Book::calculatespeed();
        Magazine::calculatespeed();
    }
};

int main() {
    ReferenceMaterial reference("ref book","unknown author",230038);
    reference.displayInfo();
    reference.readPage(50);
	reference.browseSection(3);
    reference.calculatespeed();

    return 0;
}

