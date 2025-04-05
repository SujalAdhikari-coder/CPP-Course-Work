//Write a program that manages a simple student grade calculato
#include <iostream>
using namespace std;
class Student { // Class to manage student details and grading
    string name; // Student name
    int marks[3]; // Array to store marks of three subjects
public:
    void getDetails() { // Function to get student details from user input
        cout << "Enter student name: ";
        cin >> name;
        cout << "Enter marks for three subjects: ";
        for (int i = 0; i < 3; i++) {
            cin >> marks[i];
            if (marks[i] < 0 || marks[i] > 100) { // Validate marks input (should be between 0 and 100)
                cout << "Invalid mark entered! Marks should be between 0 and 100." << endl;
                return;
            }
        }
    }
    int calculateTotal() { // Function to calculate total marks obtained by the student
        return marks[0] + marks[1] + marks[2];
    }
    float calculateAverage() { // Function to calculate average marks
        return calculateTotal() / 3.0;
    }
    char calculateGrade() { // Function to determine grade based on average marks
        float avg = calculateAverage();
        if (avg >= 90) return 'A';
        else if (avg >= 80) return 'B';
        else if (avg >= 70) return 'C';
        else if (avg >= 60) return 'D';
        else return 'F';
    }
    void displayResults() { // Function to display student results
        int total = calculateTotal();
        float avg = calculateAverage();
        char grade = calculateGrade();
        cout << "\nStudent Name: " << name << endl;
        cout << "Total Marks: " << total << endl;
        cout << "Average Marks: " << avg << endl;
        cout << "Grade: " << grade << endl;
    }
};
int main() { // Main function to execute the student grading system
    Student student; // Create Student object
    student.getDetails(); // Get student details
    student.displayResults(); // Display student results
    return 0;
}
