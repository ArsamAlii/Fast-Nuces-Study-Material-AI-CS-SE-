#include <iostream>
#include <array>
using namespace std;
// Base class representing a generic game board with fixed size
class GameBoard {
public:
    const array<array<int, 4>, 4> dimensions; // Fixed 4x4 array for board dimensions
    GameBoard() : dimensions({{ {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0} }}) {}
    virtual void display() const {
        cout<<"Base GameBoard Display"<<endl;
        for (const auto & row : dimensions) {
            for (const auto& cell : row) {
                cout << cell << " ";
            }
            cout << endl;
        }
    }
};
// Derived class for a puzzle board
class PuzzleBoard : public GameBoard {
public:
    array<array<int, 4>, 4> dimensions; // Shadowing the base class variable
    PuzzleBoard() : GameBoard(), dimensions({{ {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1},
{1, 1, 1, 1} }}) {}
    virtual void display() const {
        cout<<"PuzzleBoard Display"<<endl;
        // Modifying a mutable copy of the board despite the base class being const
         auto modifiableBoard = dimensions;
        modifiableBoard[0][0] = 2; // Example modification for display
        for (const auto& row : modifiableBoard) {
            for (const auto& cell : row) {
                cout << cell<<" ";
            }

            cout <<endl;
        }
    }
};
// Derived class for a battle board
class BattleBoard : public GameBoard {
public:
    array<array<int, 4>, 4> dimensions;// Shadowing the base class variable
    BattleBoard() : GameBoard(), dimensions({{ {2, 2, 2, 2}, {2, 2, 2, 2}, {2, 2, 2, 2}, {2,
2, 2, 2} }}) {}
    virtual void display() const {
        cout<<"BattleBoard Display"<<endl;
         auto modifiableBoard = dimensions;
        modifiableBoard[1][1] = 3; // Example modification for display
        for (const auto& row : modifiableBoard) {
            for (const auto& cell : row) {
                cout << cell << " ";
            }
            cout<< endl;
        }
    }
};
int main() {
    GameBoard baseBoard;
    baseBoard.display(); // Displaying the base game board
    PuzzleBoard puzzleBoard;
    puzzleBoard.display(); // Displaying the puzzle board
    BattleBoard battleBoard;
    battleBoard.display(); // Displaying the battle board
    return 0; }

