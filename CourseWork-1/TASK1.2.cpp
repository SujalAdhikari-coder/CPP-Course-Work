//1.2-Write a program to implement a number guessing game with different difficulty levels.
#include <iostream>
#include <ctime>  //generate random numbers
using namespace std;
int main() {
    srand(time(0));  //random number generator
    int easy = rand() % 8 + 1;    //Random number between 1 and 8
    int medium = rand() % 30 + 1; //Random number between 1 and 30
    int hard = rand() % 50 + 1;   //Random number between 1 and 50
    int guess;
    char difficulty;
    cout << "Welcome to the Number Guessing Game!" << endl;
    cout << "Choose your difficulty: Easy (e), Medium (m), Hard (h): ";
    cin >> difficulty;
    switch (difficulty) {
        case 'e': case 'E':
            cout << "Guess a number between 1 and 8: ";
            cin >> guess;
            if (guess == easy) {
                cout << "Congratulations! You guessed the correct number." << endl;
            } else {
                cout << "Wrong guess! The correct number was " << easy << "." << endl;
            }
            break;
        case 'm': case 'M':
            cout << "Guess a number between 1 and 30: ";
            cin >> guess;
            if (guess == medium) {
                cout << "Congratulations! You guessed the correct number." << endl;
            } else {
                cout << "Wrong guess! The correct number was " << medium << "." << endl;
            }
            break;
        case 'h': case 'H':
            cout << "Guess a number between 1 and 50: ";
            cin >> guess;
            if (guess == hard) {
                cout << "Congratulations! You guessed the correct number." << endl;
            } else {
                cout << "Wrong guess! The correct number was " << hard << "." << endl;
            }
            break;
        default:
            cout << "Invalid input! Please restart the game and choose a valid difficulty." << endl;
    }
    return 0;
}
