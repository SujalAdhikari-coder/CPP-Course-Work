/*2.	Stack Problem: Implement a stack using arrays (not STL) that:
1.	Has basic push and pop operations
2.	Has a function to find middle element
3.	Has a function to reverse only bottom half of stack
4.	Maintain stack size of 10
*/
#include <iostream>
using namespace std;
#define MAX_SIZE 10
class Stack {
private:
    int arr[MAX_SIZE];
    int top;
public:
    Stack() {
        top = -1;
    }
    void push(int value) {
        if (top >= MAX_SIZE - 1) {
            cout << "Stack Overflow! Cannot push " << value << endl;
            return;
        }
        arr[++top] = value;
    }
    int pop() {
        if (top < 0) {
            cout << "Stack Underflow! Cannot pop.\n";
            return -1;
        }
        return arr[top--];
    }
    void findMiddle() {
        if (top < 0) {
            cout << "Stack is empty!\n";
            return;
        }
        int middleIndex = top / 2;
        cout << "Middle Element: " << arr[middleIndex] << endl;
    }
    void reverseBottomHalf() {
        if (top < 1) {
            cout << "Not enough elements to reverse bottom half.\n";
            return;
        }
        int halfSize = (top + 1) / 2;
        for (int i = 0; i < halfSize / 2; i++) {
            swap(arr[i], arr[halfSize - 1 - i]);
        }
        cout << "Bottom half reversed.\n";
    }
    void display() {
        if (top < 0) {
            cout << "Stack is empty.\n";
            return;
        }
        cout << "Stack elements (top to bottom): ";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main() {
    Stack stack;
    int choice, value;
    do {
        cout << "\nMenu:\n";
        cout << "1. Push\n2. Pop\n3. Find Middle\n4. Reverse Bottom Half\n5. Display Stack\n6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                stack.push(value);
                break;
            case 2:
                value = stack.pop();
                if (value != -1)
                    cout << "Popped: " << value << endl;
                break;
            case 3:
                stack.findMiddle();
                break;
            case 4:
                stack.reverseBottomHalf();
                break;
            case 5:
                stack.display();
                break;
            case 6:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 6);
    return 0;
}
