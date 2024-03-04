// C++ code for Rock Paper Scissors Terminal Game

#include <iostream>
#include <cstdlib>

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

int main() {
    
    cout << "\033[2J\033[1;1H"; // special characters string that clears the screen

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

        int RoundOutcome = WhoWinsRound(playerChoice, computerChoice); // RoundOutcome will equal the outcome of WhoWinsRound, a value of -1 means a tie, 1 means the player won, and 0 means the opponent won
        
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

   
    return 0;

}
