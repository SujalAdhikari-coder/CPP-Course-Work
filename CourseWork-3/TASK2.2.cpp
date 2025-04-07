/*2.	Create a program that:
1.	Reads student records (roll, name, marks) from a text file
2.	Throws an exception if marks are not between 0 and 100
3.	Allows adding new records with proper validation
4.	Saves modified records back to file
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <stdexcept>
using namespace std;
// Custom exception for invalid marks
class InvalidMarksException : public exception {
public:
    const char* what() const throw() {
        return "Invalid marks! Marks should be between 0 and 100.";
    }
};
// Structure to store student record
struct Student {
    int roll;
    string name;
    int marks;
};
// Function to read student records from file
vector<Student> readRecords(const string& filename) {
    vector<Student> students;
    ifstream file(filename);
    // If file does not exist, create it and display a message
    if (!file) {
        cout << "File not found! Creating a new file..." << endl;
        ofstream newFile(filename); // Create the file
        newFile.close(); // Close after creation
        return students; // Return empty list
    }
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        Student s;
        ss >> s.roll;
        ss.ignore(); // Ignore space
        getline(ss, s.name, ',');
        ss >> s.marks;

        // Validate marks
        if (s.marks < 0 || s.marks > 100) {
            throw InvalidMarksException();
        }
        students.push_back(s);
    }
    file.close();
    return students;
}
// Function to add a new student record
void addRecord(vector<Student>& students) {
    Student s;
    cout << "Enter roll number: ";
    cin >> s.roll;
    cin.ignore(); // Ignore newline character
    cout << "Enter name: ";
    getline(cin, s.name);
    cout << "Enter marks (0-100): ";
    cin >> s.marks;

    // Validate marks
    if (s.marks < 0 || s.marks > 100) {
        throw InvalidMarksException();
    }

    students.push_back(s);
}
// Function to save student records back to file
void saveRecords(const string& filename, const vector<Student>& students) {
    ofstream file(filename);
    if (!file) {
        cout << "Error opening file for writing!" << endl;
        return;
    }
    for (const Student& s : students) {
        file << s.roll << " " << s.name << "," << s.marks << endl;
    }
    file.close();
    cout << "Records saved successfully!" << endl;
}
int main() {
    string filename = "students.txt";
    vector<Student> students;
    try {
        students = readRecords(filename);
    } catch (const exception& e) {
        cout << "Error reading file: " << e.what() << endl;
        return 1; // Exit if there's an issue
    }
    cout << "Existing student records:" << endl;
    for (const Student& s : students) {
        cout << s.roll << " " << s.name << " " << s.marks << endl;
    }
    char choice;
    cout << "Do you want to add a new student? (y/n): ";
    cin >> choice;
    if (choice == 'y' || choice == 'Y') {
        try {
            addRecord(students);
            saveRecords(filename, students);
        } catch (const exception& e) {
            cout << "Error: " << e.what() << endl;
        }
    }
    return 0;
}
