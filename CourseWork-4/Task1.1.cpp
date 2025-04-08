/*1.	STL Container Practice: Write a program using STL containers that:
1.	Uses vector<string> to store names
2.	Uses map<string, int> to store age against each name
3.	Implements functions to:
1.	Add new name-age pair
2.	Find all people above certain age
3.	Sort and display names alphabetically
*/
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
void addNameAgePair(vector<string>& names, map<string, int>& ageMap, const string& name, int age) {
    names.push_back(name);
    ageMap[name] = age;
}
void findPeopleAboveAge(const map<string, int>& ageMap, int threshold) {
    cout << "People with age above " << threshold << ":\n";
    for (const auto& pair : ageMap) {
        if (pair.second > threshold) {
            cout << pair.first << " (" << pair.second << " years old)" << endl;
        }
    }
}
void sortAndDisplayNames(vector<string>& names) {
    vector<string> sortedNames = names;
    sort(sortedNames.begin(), sortedNames.end());

    cout << "Names sorted alphabetically:\n";
    for (const auto& name : sortedNames) {
        cout << name << endl;
    }
}
int main() {
    vector<string> names;
    map<string, int> ageMap;
    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Add new name-age pair\n";
        cout << "2. Find all people above a certain age\n";
        cout << "3. Sort and display names alphabetically\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        if (choice == 1) {
            string name;
            int age;
            cout << "Enter name: ";
            cin >> name;
            cout << "Enter age: ";
            cin >> age;
            addNameAgePair(names, ageMap, name, age);
            cout << "Pair added successfully.\n";
        }
        else if (choice == 2) {
            int threshold;
            cout << "Enter the age threshold: ";
            cin >> threshold;
            findPeopleAboveAge(ageMap, threshold);
        }
        else if (choice == 3) {
            sortAndDisplayNames(names);
        }
        else if (choice == 4) {
            cout << "Exiting program.\n";
        }
        else {
            cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 4);

    return 0;
}
