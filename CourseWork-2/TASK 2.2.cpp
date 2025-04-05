//Create a program with these overloaded functions named findMax
#include <iostream>
using namespace std;
class MaxFinder {
public:
    int findMax(int a, int b) { //Function to find maximum between two integers
        return (a > b) ? a : b; //Return the greater of the two integers
    }
    float findMax(float a, float b) { //Function to find maximum between two floating-point numbers
        return (a > b) ? a : b; //Return the greater of the two floats
    }
        int findMax(int a, int b, int c) { //Function to find maximum among three integers
        if (a > b && a > c) { //Compare all three integers and return the maximum
            return a;
        } else if (b > a && b > c) {
            return b;
        } else {
            return c;
        }
    }
    float findMax(int a, float b) { //Function to find maximum between an integer and a floating-point number
        return (a > b) ? a : b; //Return the greater of the integer and float
    }
};
int main() {
    MaxFinder maxFinder;  //Creating an object of MaxFinder class
    int int1, int2, int3; //Declare variables to store user input
    float float1, float2;
    cout << "Enter two integers: ";
    cin >> int1 >> int2;
    cout << "The maximum of the two integers is: " << maxFinder.findMax(int1, int2) << endl;
    cout << "Enter two floating-point numbers: ";
    cin >> float1 >> float2;
    cout << "The maximum of the two floating-point numbers is: " << maxFinder.findMax(float1, float2) << endl;
    cout << "Enter three integers: ";
    cin >> int1 >> int2 >> int3;
    cout << "The maximum among the three integers is: " << maxFinder.findMax(int1, int2, int3) << endl;
    cout << "Enter an integer and a floating-point number: ";
    cin >> int1 >> float1;
    cout << "The maximum between the integer and the float is: " << maxFinder.findMax(int1, float1) << endl;
    return 0;
}
