//Write a program that reads a number from the user and based on the user input.
#include <iostream>
using namespace std;
int main() {
    int day;
    cout << "Enter the day of the week (1-7): ";
    cin >> day;
    switch (day) {
        case 1:
            cout << "Sunday" << endl;
            break;
        case 2:
            cout << "Monday" << endl;
            break;
        case 3:
            cout << "Tuesday" << endl;
            break;
        case 4:
            cout << "Wednesday" << endl;
            break;
        case 5:
            cout << "Thursday" << endl;
            break;
        case 6:
            cout << "Friday" << endl;
            break;
        case 7:
            cout << "Saturday" << endl;
            break;
        default:
            cout << "Invalid day of the week! Please enter a number between 1 and 7." << endl;
    }
    return 0;
}
