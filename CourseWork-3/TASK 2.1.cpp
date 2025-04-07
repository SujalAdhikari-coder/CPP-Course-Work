/*1.	Create a base class Vehicle and two derived classes Car and Bike:
1.	Vehicle has registration number and color
2.	Car adds number of seats
3.	Bike adds engine capacity
4.	Each class should have its own method to write its details to a file
5.	Include proper inheritance and method overriding
*/
#include <iostream>
#include <fstream>
using namespace std;
// Base class: Vehicle
class Vehicle {
protected:
    string registrationNumber;
    string color;
public:
    Vehicle(string regNum, string clr) : registrationNumber(regNum), color(clr) {}
    // Virtual function to write details to a file
    virtual void writeToFile(ofstream& file) const {
        file << "Vehicle: " << registrationNumber << ", " << color << endl;
    }
    virtual void display() const {
        cout << "Vehicle - Reg No: " << registrationNumber << ", Color: " << color << endl;
    }
};
// Derived class: Car
class Car : public Vehicle {
private:
    int numberOfSeats;
public:
    Car(string regNum, string clr, int seats) : Vehicle(regNum, clr), numberOfSeats(seats) {}
    // Overriding the writeToFile method
    void writeToFile(ofstream& file) const override {
        file << "Car: " << registrationNumber << ", " << color << ", Seats: " << numberOfSeats << endl;
    }
    void display() const override {
        cout << "Car - Reg No: " << registrationNumber << ", Color: " << color << ", Seats: " << numberOfSeats << endl;
    }
};
// Derived class: Bike
class Bike : public Vehicle {
private:
    int engineCapacity; // in CC
public:
    Bike(string regNum, string clr, int engineCap) : Vehicle(regNum, clr), engineCapacity(engineCap) {}
    // Overriding the writeToFile method
    void writeToFile(ofstream& file) const override {
        file << "Bike: " << registrationNumber << ", " << color << ", Engine Capacity: " << engineCapacity << "cc" << endl;
    }
    void display() const override {
        cout << "Bike - Reg No: " << registrationNumber << ", Color: " << color << ", Engine: " << engineCapacity << "cc" << endl;
    }
};
int main() {
    string regNum, color;
    int choice, seats, engineCap;
    ofstream file("vehicles.txt", ios::app); // Open file in append mode
    if (!file) {
        cout << "Error opening file!" << endl;
        return 1;
    }
    cout << "Choose Vehicle Type:\n1. Car\n2. Bike\nEnter choice: ";
    cin >> choice;
    cin.ignore(); // To clear newline character from input buffer
    cout << "Enter Registration Number: ";
    getline(cin, regNum);
    cout << "Enter Color: ";
    getline(cin, color);
    if (choice == 1) {
        cout << "Enter Number of Seats: ";
        cin >> seats;
        Car car(regNum, color, seats);
        car.writeToFile(file);
        cout << "Car details saved!\n";
        car.display();
    } else if (choice == 2) {
        cout << "Enter Engine Capacity (in CC): ";
        cin >> engineCap;
        Bike bike(regNum, color, engineCap);
        bike.writeToFile(file);
        cout << "Bike details saved!\n";
        bike.display();
    } else {
        cout << "Invalid choice!" << endl;
    }
    file.close();
    return 0;
}
