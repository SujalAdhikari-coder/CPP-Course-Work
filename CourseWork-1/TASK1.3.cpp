//Write a program that reads an array of integer numbers from the user and sorts the numbers in the ascending order.
#include <iostream>
#include <algorithm>  //built-in sort() function
using namespace std;
int main() {
    int n, arr[100];  //Declare an array to store numbers max size 100
    cout << "Enter number of elements: ";
    cin >> n;
    if (n > 100 || n <= 0) {
        cout << "Invalid input! Please enter a number between 1 and 100." << endl;
        return 1;  //Exit the program with an error code
    }
    cout << "Enter numbers: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);  //Sort the array in ascending order using the built-in sort() function
    cout << "Sorted numbers: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
