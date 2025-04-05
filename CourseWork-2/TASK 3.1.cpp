//Write a program that reads the titles of 10 books (use an array of 150 characters) and writes them in a binary file selected by the user. The program should read a title and display a message to indicate if it is contained in the file or not.
#include <iostream>
#include <fstream>  //For file handling
#include <cstring>  //For string handling
using namespace std;
int main() {
    char bookTitles[10][150];  //Array to store 10 book titles (each 150 characters)
    ofstream outFile;          //Output file stream to write to file
    //Open the binary file for writing (append mode, creates if not exists)
    outFile.open("bookTitles.dat", ios::binary | ios::app);
    if (!outFile) {
        cout << "Error opening file for writing!" << endl;
        return 1;
    }
    //Read 10 book titles from the user
    cout << "Enter titles of 10 books:" << endl;
    cin.ignore();  //Ignore newline character left in the buffer
    for (int i = 0; i < 10; i++) {
        cout << "Book " << i + 1 << ": ";
        cin.getline(bookTitles[i], 150);  //Read the book title
        outFile.write(bookTitles[i], sizeof(bookTitles[i]));  //Write to binary file
    }
    outFile.close();  //Close the file after writing
    //Ask the user to enter a book title to search
    char searchTitle[150];
    cout << "\nEnter a book title to search: ";
    cin.getline(searchTitle, 150);
    //Ensure the file exists (create an empty file if missing)
    ifstream testFile("bookTitles.dat", ios::binary);
    if (!testFile) {
        ofstream createFile("bookTitles.dat", ios::binary);
        createFile.close();
    }
    testFile.close();
    //Open the binary file for reading
    ifstream inFile("bookTitles.dat", ios::binary);
    if (!inFile) {
        cout << "Error opening file for reading!" << endl;
        return 1;
    }
    bool found = false;
    char title[150];
    //Read until the end of the file
    while (inFile.read(title, sizeof(title))) {
        if (strcmp(title, searchTitle) == 0) {
            found = true;
            break;
        }
    }
    //Display result based on the search
    if (found) {
        cout << "Title found in the file!" << endl;
    } else {
        cout << "Title not found in the file." << endl;
    }
    inFile.close();  //Close the file after reading
    return 0;
}
