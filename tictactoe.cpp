// Below is code for a Tic Tac Toe terminal game

#include <iostream>

using namespace std;

// numbers = players can use to place their mark on board
char choices[9] = {'1','2','3','4','5','6','7','8','9'};

//char mark_O[10]  = {'O','O','O','O','O','O','O','O','O','O'};
//char mark_X[10]  = {'X','X','X','X','X','X','X','X','X','X'};
bool endGame = false;

// tictactoe is a function that will output the state the board is currently in
void tictactoe() {

    // choices is an array that will be edited based on either player's move
    // Numbers 1-9 will fill the board, allowing the user to input a number to select where their move choice will mark
    // When Player 1 makes a move, the index will be replaced by an 'O'
    // When Player 2 makes a move, the index will be replaced by an 'X'

    cout << "-----------------------" << endl;
    cout << "      TIC TAC TOE     " << endl;
    cout << "-----------------------" << endl;

    cout << "       |       |       " << endl;
    cout << "   " << choices[0] << "   |   " << choices[1] << "   |   " << choices[2] << endl;
    cout << "       |       |       " << endl;
    cout << "-------|-------|-------" << endl;
    cout << "       |       |       " << endl;
    cout << "   " << choices[3] << "   |   " << choices[4] << "   |   " << choices[5] << endl;
    cout << "       |       |       " << endl;
    cout << "-------|-------|-------" << endl;
    cout << "       |       |       " << endl;
    cout << "   " << choices[6] << "   |   " << choices[7] << "   |   " << choices[8] << endl;
    cout << "       |       |       " << endl;

}

int main()
{
    cout << "\033[2J\033[1;1H"; //string of special characters that clear screen, makes printing the board much cleaner

    tictactoe(); // initial board state

    int choice;
    bool player = true; // When true = Player 1, when false = Player 2
    
    while(endGame == false) { // game will continue until the game either has a winner or no spots are available
                              
        if(player == true) { // This is when it is Player 1's turn

            cout << endl << "Player 1, choose a number on the board: ";
            cin >> choice;

            choices[choice - 1] = 'O';
        
            player = false;

        }

        else if(player == false) { // This is when it is Player 2's turn

            cout << "Player 2, choose a number on the board: ";
            cin >> choice;

            choices[choice - 1] = 'X';
            
            player = true;

        }

        cout << "\033[2J\033[1;1H";

        tictactoe(); // board state after a move is made by either player
    }

    return 0;

}
