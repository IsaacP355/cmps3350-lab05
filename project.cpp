#include <iostream>

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// This is for a random card
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

int main() {
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

    return 0;
}

