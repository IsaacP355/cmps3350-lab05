// C++ code for Rock Paper Scissors Terminal Game

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int playerWins = 0;
int computerWins = 0;
int totalTies = 0;

void printChoices() { // function that prints choices the player can make

    cout << "Choose 1 for Rock" << endl;
    cout << "Choose 2 for Paper" << endl;
    cout << "Choose 3 for Scissors" << endl;
    cout << "Enter your choice for this round: ";

}

void choiceMade(int choice) { // function that outputs the choice made by player and opponent

    if(choice == 1)
        cout << "ROCK";
    else if(choice == 2)
        cout << "PAPER";
    else if(choice == 3)
        cout << "SCISSORS";
}

void printPlayer(int choice) { // function to print ASCII art of rock, paper, or scissors
                               // credit to Veronica Karlsson for ASCII art
    if(choice == 1) { // print rock if choice was 1
        cout << "      _______"    << endl;         
        cout << "  ---'   ____)"   << endl;
        cout << "        (_____)"  << endl;
        cout << "        (_____)"  << endl;
        cout << "        (____)"   << endl;
        cout << "  ---.__(___)"    << endl;
    }
    else if(choice == 2) { // print paper if choice was 2
        cout << "      _______" << endl;
        cout << "  ---'    ____)____" << endl;
        cout << "             ______)" << endl;
        cout << "            _______)" << endl;
        cout << "          _______)" << endl;
        cout << "  ---.__________)" << endl;
    }
    else if(choice == 3) { // print scissors if choice was 3
        cout << "     _______" << endl;
        cout << " ---'   ____)____" << endl;
        cout << "           ______)" << endl;
        cout << "        __________)" << endl;
        cout << "       (____)" << endl;
        cout << " ---.__(___)" << endl;
    }
}

void printComputer(int choice) { // function to print ASCII art of rock, paper, or scissors for Computer's move
                                 // similar to function printPlayer, but ASCII art is reversed
    if(choice == 1) { // print rock
        cout << "   _______" << endl;
        cout << "  (____   '---" << endl;
        cout << " (_____)" << endl;
        cout << " (_____)" << endl;
        cout << "  (_____)" << endl;
        cout << "   (____)__.---" << endl;
    }
    else if(choice == 2) { // print paper
        cout << "       _______" << endl;
        cout << "  ____(____    '---" << endl;
        cout << "(______" << endl;           
        cout << "(______" << endl;       
        cout << " (______" << endl;
        cout << "   (___________.---" << endl;
    }
    else if(choice == 3) { // print scissors
        cout << "        ________" << endl;
        cout << "   ____(____    '---" << endl;
        cout << "  (__________" << endl;
        cout << " (__________  " << endl;
        cout << "       (____)" << endl;
        cout << "       (____)___.---" << endl;
    }
    cout << endl;
}


int WhoWinsRound(int player, int computer) { // function to check whether player or opponent won the round

    if(player == computer) // if both players made same move, it's a tie
        return -1;
    else if((player == 1 && computer == 3) || (player == 2 && computer == 1) || (player == 3 && computer == 2)) // if player made a move that beats the opponent, they won
        return 1;
    else
        return 0; // only option left is that the opponent beat the player
}

void GameSummary() { // prints after all rounds of the game are over, displaying a summary of the rounds and who won overall

    cout << "------------------------GAME SUMMARY------------------------" << endl;
    cout << "You won a total of " << playerWins << " times!" << endl;
    cout << "Your opponent won a total of " << computerWins << " times." << endl;
    cout << "There was a total amount of " << totalTies << " ties." << endl;

    if(playerWins == computerWins)
        cout << "Both players had the same number of wins, so overall it is a tie!" << endl;
    else if(playerWins > computerWins)
        cout << "You had more wins than your opponent, you win!" << endl;
    else if(playerWins < computerWins)
        cout << "Your opponent had more wins than you. Your opponent wins." << endl;

}

// Below is code for a Tic Tac Toe terminal game

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

bool DidPlayerWin() {
    for(int i = 0; i < 9; i = i +3) {
        if(choices[i] == choices[i+1] && choices[i+1] == choices[i+2]) // if all marks horizontally match, player has won
            return true;
    }

    for(int i = 0; i < 3; i++) { // if all marks vertically match, player has won
        if(choices[i] == choices[i+3] && choices[i+3] == choices[i+6])
            return true;
    }

    if(choices[0] == choices[4] && choices[4] == choices[8] || choices[2] == choices[4] && choices[4] == choices[6]) // match was found diagonally
        return true;

    return false; // no match found for a player to win
}

bool DidPlayersTie() {
    for(int i = 0; i < 9; i++) {
        if(choices[i] != 'O' && choices[i] != 'X') // if there still is a empty mark on the board, then the game has not tied
            return false;
    }

    return true; // all marks on board are filled, and there is no winner
}

int getRandomCard() {
    return rand() % 10 + 1; // This is so that I can get a card between 1 and 10
}

// Code using to calculate / show how much the cards are
int calculateHandTotal(const int hand[], int size) {
    int total = 0;
    int numAces = 0;

    for (int i = 0; i < size; ++i) {
        if (hand[i] == 1) {
            numAces++;
            total += 11; // Force 1 to be a Ace making it 11
        } else if (hand[i] > 10) {
            total += 10; // Face cards have a value of 10
        } else {
            total += hand[i];
        }
    }

    // if there is a Ace
    while (total > 21 && numAces > 0) {
        total -= 10; // Change an Ace's value from 11 to 1 when you break
        numAces--;
    }

    return total;
}



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main() {



    cout << "\033[2J\033[1;1H"; // special characters string that clears the screen

    cout << "*******************************************" << endl;
    cout << "         Welcome to the Arcade!" << endl;
    cout << "*******************************************" << endl;
    cout << "Choose a game to play:" << endl;
    cout << "1. BlackJack" << endl;
    cout << "2. Tictactoe" << endl;
    cout << "3. Rock Paper Scissors" << endl;
    cout << "*******************************************" << endl;

    int option;
    cout << "Enter the number of your choice ( 1, 2, or 3): ";
    cin >> option;
    cout << endl;


    if (option == 3)
    {
        int rounds = 0;
        cout << "How many rounds of Rock Paper Scissors should be played? ";
        cin >> rounds; // user inputs how many rounds they want to play

        srand(time(0));

        for(int i = 0; i < rounds; i++) { // Loop taking place as many times as rounds was chosen                                    
            cout << "-----ROUND " << i+1 << "-----" << endl;
            int computerChoice = rand() % 3 + 1; // The opponent will randomly generate a number between 1-3
            int playerChoice = 0;

            printChoices();
            cin >> playerChoice; // Player is shown choices they can make for that round

            while(playerChoice < 1 || playerChoice > 3) { // ensure player correctly chooses 1, 2, or 3 for their move
                cout << "Your choice must be either: 1 2 3" << endl;
                cout << "Enter your choice for this round: ";
                cin >> playerChoice;
            }

            cout << "Your opponent's choice was: " << computerChoice << endl; // output opponent's move

            // output the move both the player and opponent made (ex: ROCK VS PAPER)
            choiceMade(playerChoice); 
            cout << " VS ";
            choiceMade(computerChoice);
            cout << endl;

            // print ASCII art for choice made by both player and opponent
            printPlayer(playerChoice);
            cout << endl;
            printComputer(computerChoice);

            int RoundOutcome = WhoWinsRound(playerChoice, computerChoice); 
            // RoundOutcome will equal the outcome of WhoWinsRound, a value of -1 means a tie, 1 means the player won, and 0 means the opponent won

            if(RoundOutcome == -1) { 
                cout << "Both players made the same move, it's a draw." << endl;
                totalTies = totalTies + 1;
            }
            else if(RoundOutcome == 1) {
                cout << "You beat the opponent!" << endl;
                playerWins = playerWins + 1;
            }
            else if(RoundOutcome == 0) {
                cout << "The opponent beat your move." << endl;
                computerWins = computerWins + 1;
            }

            cout << endl << endl;

        }

        GameSummary(); // print out the results of all the rounds and who won

    }
    else if (option == 2)
    {
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

            if(DidPlayerWin() == true) { // Did either player win after their turn?

                if(player == true) // if the match is all "O"
                    cout << "Player 1 wins Tic Tac Toe!" << endl;
                else // if match instead is all "X"
                    cout << "Player 2 wins Tic Tac Toe!" << endl;

                endGame = true;
            }

            if(DidPlayersTie() == true) { // Is the board completely filled without a winner?
                cout << "There is no winner. The game is a tie!" << endl;

                endGame = true;
            }

        }
    }


    else if(option == 1)
    {
        srand(static_cast<unsigned int>(time(0))); // Code i found for randomization

        const int MAX_CARDS = 10; // Maximum number of cards in a hand before it kicks out

        int playerHand[MAX_CARDS];
        int dealerHand[MAX_CARDS];
        int playerHandSize = 0;
        int dealerHandSize = 0;

        // Initial deal
        playerHand[playerHandSize++] = getRandomCard();
        dealerHand[dealerHandSize++] = getRandomCard();
        playerHand[playerHandSize++] = getRandomCard();
        dealerHand[dealerHandSize++] = getRandomCard();

        // The game loop
        while (true) {
            cout << "Your hand: ";
            for (int i = 0; i < playerHandSize; ++i) {
                cout << playerHand[i] << " ";
            }
            cout << " (Total: " << calculateHandTotal(playerHand, playerHandSize) << ")" << endl;

            cout << "Dealer's hand: " << dealerHand[0] << " ??" << endl;

            // Check if a blackjack is dealt for player
            if (calculateHandTotal(playerHand, playerHandSize) == 21) {
                cout << "Blackjack! You win!" << endl;
                break;
            }

            if (calculateHandTotal(dealerHand, dealerHandSize) == 21) {
                cout << "Dealer has Blackjack you lose" << endl;
                break;
            }

            // Player's turn
            cout << "Do you want to (H)it or (S)tand? ";
            char choice;
            cin >> choice;

            if (choice == 'H' || choice == 'h') {
                playerHand[playerHandSize++] = getRandomCard();
                if (calculateHandTotal(playerHand, playerHandSize) > 21) {
                    cout << "Bust! You lose." << endl;
                    break;
                }
            } else if (choice == 'S' || choice == 's') {
                // Dealer's turn
                while (calculateHandTotal(dealerHand, dealerHandSize) < 17) {
                    dealerHand[dealerHandSize++] = getRandomCard();
                }

                cout << "Dealer's hand: ";
                for (int i = 0; i < dealerHandSize; ++i) {
                    cout << dealerHand[i] << " ";
                }
                cout << " (Total: " << calculateHandTotal(dealerHand, dealerHandSize) << ")" << endl;

                // Determine the winner
                if (calculateHandTotal(dealerHand, dealerHandSize) > 21 ||
                        calculateHandTotal(playerHand, playerHandSize) > calculateHandTotal(dealerHand, dealerHandSize)) {
                    cout << "You win!" << endl;
                } else if (calculateHandTotal(playerHand, playerHandSize) < calculateHandTotal(dealerHand, dealerHandSize)) {
                    cout << "You lose." << endl;
                } else {
                    cout << "Tie." << endl;
                }

                break;
            } else {
                cout << "Invalid choice. Please enter 'H' or 'S'." << endl;
            }
        }



    }



    return 0;

}


