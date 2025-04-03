//Write a program that manages a cinema ticket booking system. The program should display a 5x5 seating arrangement
#include <iostream>
using namespace std;
int main() {
    char seats[5][5] = {  // Initialize a 5x5 seating arrangement
        {'O', 'O', 'O', 'O', 'O'},
        {'O', 'O', 'O', 'O', 'O'},
        {'O', 'O', 'O', 'O', 'O'},
        {'O', 'O', 'O', 'O', 'O'},
        {'O', 'O', 'O', 'O', 'O'}
    };
    while (true) { //loop for seat booking
        cout << "Cinema Seats:\n";
        for (int row = 0; row < 5; row++) {  //Display the current seat
            for (int col = 0; col < 5; col++) {
                cout << seats[row][col] << " ";  //Print seat status
            }
            cout << endl;
        }
        cout << "Which row (1-5)? ";
        int row;
        cin >> row;
        cout << "Which column (1-5)? ";
        int col;
        cin >> col;
        if (row == 0 && col == 0) {
            cout << "Exiting...\n";
            break;
        }
        if (row < 1 || row > 5 || col < 1 || col > 5) {  //Ensure row and column are within valid range
            cout << "Invalid seat selection! Please enter values between 1 and 5.\n";
            continue;
        }
        // Convert to zero-based indexing
        row--;
        col--;
        if (seats[row][col] == 'X') { //Check if the seat is already booked
            cout << "Sorry, that seat is already taken. Try another.\n";
            continue;
        }
        seats[row][col] = 'X'; //Mark the seat as booked
        cout << "Seat booked successfully!\n";
        char choice;
        cout << "Do you want to book more seats? (y/n): ";
        cin >> choice;
        if (choice == 'n' || choice == 'N') {
            cout << "Exiting...\n";
            break;
        }
    }
    return 0;
}
