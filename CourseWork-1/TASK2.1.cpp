#include <iostream>
using namespace std;
bool isBouncy(int num) {
    if (num < 100) return false;  //Numbers below 100 are NOT bouncy
    bool increasing = false, decreasing = false;
    int lastDigit = num % 10;  //Extract last digit
    num /= 10;  //Remove last digit
    while (num > 0) {
        int currentDigit = num % 10;  //Extract next digit
        if (currentDigit < lastDigit) increasing = true;   //Checking increasing trend
        if (currentDigit > lastDigit) decreasing = true;   //Checking decreasing trend
        if (increasing && decreasing) return true;  //If both are true, it's bouncy
        lastDigit = currentDigit;  //Move to the next digit
        num /= 10;  //Remove last digit
    }
    return false;  //Not a bouncy number
}
int main() {
    int num;
    cout << "Enter a positive integer: ";
    cin >> num;
    if (isBouncy(num)) {
        cout << num << " is a bouncy number." << endl;
    } else {
        cout << num << " is NOT a bouncy number." << endl;
    }
    return 0;
}
