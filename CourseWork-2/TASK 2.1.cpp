/*
   Student Grade Calculator Program
   This program defines a Student class with:
   1. A student name (string)
   2. Three subject marks (integers)
   3. A function to calculate and display the average marks
*/
#include <iostream>
using namespace std;
class Circle {
private:
    float radius;
public:
    Circle(float r) { //Constructor to initialize radius
        radius = r;
    }
    float getArea() const { //Function to calculate the area of the circle
        return 3.14159 * radius * radius;
    }
    void compareWith(const Circle& other) const { //Member function to compare two circles
        float area1 = this->getArea();
        float area2 = other.getArea();
        cout << "Circle 1 Area: " << area1 << endl;
        cout << "Circle 2 Area: " << area2 << endl;
        if (area1 > area2) {
            cout << "This circle has a larger area." << endl;
        } else if (area2 > area1) {
            cout << "The other circle has a larger area." << endl;
        } else {
            cout << "Both circles have the same area." << endl;
        }
    }
};
int main() {
    float r1, r2;
    cout << "Enter radius of first circle: ";
    cin >> r1;
    cout << "Enter radius of second circle: ";
    cin >> r2;

    Circle circle1(r1), circle2(r2);
    circle1.compareWith(circle2); //Comparing the two circles

    return 0;
}
