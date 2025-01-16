#include<iostream>
#include<string> 
using namespace std;

class Book{
    string isbn;
    string title;
    Book *next;
    public:
    Book(string isbn,string title){
        this->isbn=isbn;
        this->title=title;
        next=NULL;
    }
    string get_isbn(){
        return isbn;
    }
    string get_title(){
        return title;
    }
    friend class hash_t;
};

class hash_t{
    Book **arr;
    int capacity;
    public:
    hash_t(int capacity){
        this->capacity=capacity;
        arr=new Book *[capacity];
        for(int i=0;i<capacity;i++){
            arr[i]=NULL;
        }
    }

    int hashfunction(string isbn){
        return stoi(isbn)%capacity;
    }

    void insert(string isbn,string title){
        int index=hashfunction(isbn);
        Book *newbook=new Book (isbn,title);

        if(arr[index]==NULL){
            arr[index]=newbook;
        }else{
            newbook->next=arr[index];
            arr[index]=newbook;
        }
    }


    Book *searchbook(string isbn_find){
        int isbn_no=stoi(isbn_find);
        int index=isbn_no%capacity;
        Book *temp=arr[index];
        while(temp!=NULL){
            if(temp->isbn==isbn_find){
                return temp;
            }
            temp=temp->next;
        }
        return NULL;
    }

    bool delete_book(string isbn_delete){
        int index=hashfunction(isbn_delete);
        Book *temp=arr[index];
        Book *prev=NULL;
        while(temp!=NULL){
            if(temp->isbn==isbn_delete){
                if(prev==NULL){
                    arr[index]=temp->next;
                }else{
                    prev->next=temp->next;
                }
                delete temp;
                return true;
            }
            prev=temp;
            temp=temp->next;
        }
        return false;
    }

    void display() {
        for (int i=0;i<capacity;i++) {
            Book*temp=arr[i];
            cout<<endl<<"Index "<<i<<" :";
            while (temp != NULL) {
                cout<<"Book ISBN is: "<<temp->isbn<<endl;
                cout<<"Book Title is: "<<temp->title<<endl;
                temp=temp->next;
            }
            cout<<endl<<"---------------" << endl<<endl;
        }
    }


};

int main(){
    hash_t library(5);

    library.insert("123","book 1");
    library.insert("456","book 2");
    library.insert("789","book 3");
    library.insert("5","book 3");
    library.insert("10","book 3");
    library.insert("7","book 3");
    
    
    cout<<"books in library : "<<endl;
    library.display();

    cout<<"--------searching----------";
    string search_isbn="789";
    Book *s_book=library.searchbook(search_isbn);
    if(s_book!=nullptr){
        cout<<"book found : "<<endl;
        cout<<"book isbn is : "<<s_book->get_isbn()<<endl;
        cout<<"book title is"<<s_book->get_title()<<endl<<endl;
    }else{
        cout<<"book not found with isbn"<<search_isbn<<endl;
    }

    cout<<endl<<"--------deleting---------"<<endl;

    string delete_isbn="12345";
    if(library.delete_book("12345")){
        cout<<"book deleted successfully"<<endl;
    }else{
        cout<<"book not found";
    }

    cout<<"after deletion :"<<endl;
    library.display();

    return 0;
}