/*1.	Create a Time class to store hours and minutes. Implement:
1.	Overload the + operator to add two Time objects
2.	Overload the > operator to compare two Time objects
3.	Handle invalid time (>24 hours or >60 minutes) by throwing a custom exception
*/
#include <iostream>
#include <stdexcept> //For exception handling
using namespace std;
class InvalidTimeException : public exception {
public:
    const char* what() const throw() {
        return "Invalid time! Hours should be <= 24 and minutes should be < 60.";
    }
};
class Time {
private:
    int hours, minutes;

    void validate() {
        if (hours > 24 || minutes >= 60) {
            throw InvalidTimeException();
        }
    }
public:
    Time(int h = 0, int m = 0) : hours(h), minutes(m) {
        validate();
    }
    Time operator+(const Time& t) {
        int totalMinutes = (hours + t.hours) * 60 + (minutes + t.minutes);
        return Time(totalMinutes / 60, totalMinutes % 60);
    }
    bool operator>(const Time& t) {
        return (hours * 60 + minutes) > (t.hours * 60 + t.minutes);
    }
    void show() {
        cout << hours << " hours " << minutes << " minutes" << endl;
    }
};
int main() {
    try {
        int h1, m1, h2, m2;
        cout << "Enter first time (hours minutes): ";
        cin >> h1 >> m1;
        Time t1(h1, m1);
        cout << "Enter second time (hours minutes): ";
        cin >> h2 >> m2;
        Time t2(h2, m2);
        // Addition
        Time t3 = t1 + t2;
        cout << "Sum: ";
        t3.show();
        // Comparison
        if (t1 > t2)
            cout << "First time is greater than second time." << endl;
        else
            cout << "Second time is greater than or equal to first time." << endl;

    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }
    return 0;
}
