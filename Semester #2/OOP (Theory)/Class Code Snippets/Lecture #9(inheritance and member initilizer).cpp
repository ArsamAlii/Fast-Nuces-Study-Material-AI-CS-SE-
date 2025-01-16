#include <iostream>
#include <string>
using namespace std;
// Base class Player
class Player {
public:
    string name;
    int age;

public:
    Player(const string& playerName, int playerAge) : name(playerName), age(playerAge) {}

    void displayInfo() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

// Derived class Batsman
class Batsman : public Player {
private:
    int runsScored;

public:
    Batsman(const string& playerName, int playerAge, int runs) : Player(playerName, playerAge), runsScored(runs) {}

    void displayBatsmanInfo() {
        displayInfo();
        cout << "Runs Scored: " << runsScored << endl;
    }
};

// Derived class Bowler
class Bowler : public Player {
private:
    int wicketsTaken;

public:
    Bowler(const string& playerName, int playerAge, int wickets) : Player(playerName, playerAge), wicketsTaken(wickets) {}

    void displayBowlerInfo() {
        displayInfo();
        cout << "Wickets Taken: " << wicketsTaken << endl;
    }
};

int main() {
   
    Player khilari("ahmed lashari",50);
    khilari.displayInfo();
   

    Batsman batsman("Babar Azam", 33, 12000);
   batsman.name="hahaha";
     batsman.displayBatsmanInfo();
    /*
    Bowler bowler("Wasim Jnr", 27, 200);

    cout << "Batsman Information:" << endl;
    batsman.displayBatsmanInfo();

    cout << "\nBowler Information:" << endl;
    bowler.displayBowlerInfo();
*/
    return 0;
}