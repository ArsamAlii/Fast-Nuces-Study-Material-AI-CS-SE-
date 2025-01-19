#include <iostream>
#include <string>
using namespace std;

class Store {
private:
    int id;
    string name;
    string category;
    int quantity;
    static int itemCount;

public:
    Store() {
        id = 0000;
        name = "unknown";
        category = "none";
        quantity = 0;
        itemCount++;
    }

    Store(int id, string name, string category, int quantity) {
        this->id = id;
        this->name = name;
        this->category = category;
        this->quantity = quantity;
        itemCount++;
    }

    void setId(int id) {
        this->id = id;
    }

    void setName(const string& name) {
        this->name = name;
    }

    void setCategory(const string& category) {
        this->category = category;
    }

    void setQuantity(int quantity) {
        this->quantity = quantity;
    }

    int getId(){
        return id;
    }

    string getName(){
        return name;
    }

    string getCategory(){
        return category;
    }

    int getQuantity(){
        return quantity;
    }


    void display(){
        cout<<"Name is: "<<name<<endl;
        cout<<"ID is: "<<id<<endl;
        cout<<"Category is: "<<category<<endl;
       cout<<"Quantity is: "<<quantity<<endl;
       cout<<"------------------------------------------"<<endl;
    }

    void searchById(int searchId){
        if (id == searchId){
            cout<<"Item found:" <<endl;
            display();
        } 
		
		else{
            cout << "Item not found."<<endl;
        }
    }

    void searchByCategory(const string& s_category){
        if (category == s_category){
            cout << "Item found:" << endl;
            display();
        } 
		else{
            cout << "Item not found." << endl;
        }
    }

    static void displayCategoryCount(const Store items[], int num){
        int c_food = 0;
        int c_tools = 0;
        int c_equipment = 0;

        for (int i=0;i<num;i++){
            if (items[i].category=="food"){
                c_food++;
            } 
			else if (items[i].category=="tools"){
                c_tools++;
            } 
			else if (items[i].category=="equipment"){
                c_equipment++;
            }
        }

        cout<<"Category Counts:"<<endl;
        cout<<"Food: "<< c_food<<endl;
        cout<<"Tools: "<< c_tools<<endl;
        cout<<"Equipment: "<< c_equipment<<endl;
        cout<<"-----------------------------------"<<endl<<endl;
    }
    
static void addItem(Store* &items, int& num){

    Store* newitems=new Store[num + 1];


    for (int i=0;i<num;i++){
        newitems[i]=items[i];
    }

 
    cout << "Enter name of item: ";
    cin.ignore();
    getline(cin, newitems[num].name);

    cout << "Enter item id: ";
    cin >> newitems[num].id;

    cout << "Enter item category (food, tools, equipment) This is case sensitive be careful: ";
    cin >> newitems[num].category;

    cout << "Enter quantity: ";
    cin >> newitems[num].quantity;

    num++;
 
    delete[] items;
    items=newitems;
}
};


void updateitem(Store items[], int num){
    int choice, quantity, id;
    string name, category;
    cout << "Choose what to update for item "<<num<<": "<<endl;
    cout << "1. Update category."<<endl;
    cout << "2. Update quantity."<<endl;
    cout << "3. Update name. "<<endl;
    cout << "4. Update id."<<endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice){
        case 1:
            cout<<"Enter the new category: ";
            cin>>category;
            items[num].setCategory(category);
            cout<<"Category updated successfully."<<endl;
            break;
        case 2:
            cout<<"Enter the new quantity: ";
            cin>>quantity;
            items[num].setQuantity(quantity);
            cout<<"Quantity updated successfully."<<endl;
            break;
        case 3:
            cout<<"Enter the new name: ";
            cin>>name;
            items[num].setName(name);
            cout<<"Name updated successfully."<<endl;
            break;
        case 4:
            cout<<"Enter the new id: ";
            cin>>id;
            items[num].setId(id);
            cout<<"ID updated successfully."<<endl;
            break;
        default:
            cout<<"Invalid choice."<<endl;
    }
}

int Store::itemCount=0;

int main(){
    cout<<"Enter the total number of items to inventory: ";
    int no_items;
    cin>>no_items;

   Store *items=new Store[no_items];
    string name,category;
    int id,quantity;

    for(int i=0;i<no_items;i++)
	 {
        cout<<"-----------FOR ITEM "<<i+1<<"--------------" << endl;
        cout<<"Enter name of item: ";
        cin.ignore();
        getline(cin, name);
        items[i].setName(name);

        cout<<"Enter item id: ";
        cin>>id;
        items[i].setId(id);

        cout<<"Enter item category (food, tools, equipment) {this is casse sensitive be caareful}:";
        cin>>category;
        items[i].setCategory(category);

        cout<<"Enter quantity: ";
        cin>>quantity;
        items[i].setQuantity(quantity);
    }
    int opt;
    do{
        cout<<"1. Display items."<<endl;
        cout<<"2. Update item detail."<<endl;
        cout<<"3. Search for item ."<<endl;
        cout<<"4. Add item"<<endl;
        cout<<"5. Exit."<<endl;

        cout<<endl<<"Enter your option: ";
        cin>>opt;

        switch (opt){
            case 1:
                for(int i=0;i<no_items;i++){
                    items[i].display();
                }
                Store::displayCategoryCount(items,no_items);
                break;
            case 2:
                int c_item;
                cout<<"Enter the item you want to update: ";
                cin>>c_item;
                updateitem(items,c_item-1);
                break;
            case 3:
                int a_opt;
                cout<<"Do you want to search by id or by item category?"<<endl;
                cout<<"1. Search by id"<<endl;
                cout<<"2. Search by category"<<endl;
                cin>>a_opt;
                if(a_opt==1){
                    int searchid;
                    cout<<"Enter the ID to search: ";
                    cin>>searchid;
                    for(int i=0;i<no_items;i++){
                        items[i].searchById(searchid);
                    }
                } else if(a_opt == 2){
                    string s_category;
                    cout<<"Enter the category you want to search:";
                    cin>>s_category;
                    for(int i=0;i<no_items;i++){
                        items[i].searchByCategory(s_category);
                    }
                } else{
                    cout<<"Invalid option."<<endl;
                }
                break;
            case 4:
                Store::addItem(items,no_items);
                break;
            case 5:
                cout<<"Exiting..."<<endl;
                break;
            default:
                cout<<endl<<"Invalid option. Enter again please."<<endl<<endl;
                break;
        }

    }while(opt != 5);

	 delete[] items;
	 
    return 0;
}

