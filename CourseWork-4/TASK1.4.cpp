/* 4.	Linked List Problem: Create a singly linked list (not STL) that:
1.	Has functions to insert at start/end/position
2.	Has a function to detect and remove loops
3.	Has a function to find nth node from end
4.	Has a function to reverse list in groups of K nodes
*/
#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};
class LinkedList {
private:
    Node* head;
public:
    LinkedList() {
        head = nullptr;
    }
    void insertAtStart(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }
    void insertAtPosition(int value, int position) {
        if (position <= 0) {
            cout << "Invalid position!\n";
            return;
        }
        if (position == 1) {
            insertAtStart(value);
            return;
        }
        Node* newNode = new Node(value);
        Node* temp = head;
        for (int i = 1; i < position - 1 && temp; i++) {
            temp = temp->next;
        }
        if (!temp) {
            cout << "Position out of bounds!\n";
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    void detectAndRemoveLoop() {
        Node* slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                cout << "Loop detected! Removing...\n";
                removeLoop(slow);
                return;
            }
        }
        cout << "No loop detected.\n";
    }
    void removeLoop(Node* loopNode) {
        Node* ptr1 = head;
        Node* ptr2 = loopNode;

        while (ptr1->next != ptr2->next) {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        ptr2->next = nullptr;
    }
    void findNthFromEnd(int n) {
        Node* first = head;
        Node* second = head;
        for (int i = 0; i < n; i++) {
            if (!first) {
                cout << "N is larger than the list size!\n";
                return;
            }
            first = first->next;
        }
        while (first) {
            first = first->next;
            second = second->next;
        }
        cout << "The " << n << "th node from end is: " << second->data << endl;
    }
    Node* reverseInGroups(Node* head, int k) {
        if (!head || k <= 1) return head;

        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;
        int count = 0;
        Node* temp = head;
        for (int i = 0; i < k && temp; i++, temp = temp->next) count++;
        if (count < k) return head;
        count = 0;
        while (current && count < k) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
            count++;
        }
        if (next)
            head->next = reverseInGroups(next, k);

        return prev;
    }
    void reverseInGroupsK(int k) {
        head = reverseInGroups(head, k);
        cout << "List reversed in groups of " << k << endl;
    }
    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};
int main() {
    LinkedList list;
    int choice, value, pos, k;
    do {
        cout << "\nMenu:\n";
        cout << "1. Insert at Start\n2. Insert at End\n3. Insert at Position\n4. Detect & Remove Loop\n5. Find Nth Node from End\n6. Reverse in Groups of K\n7. Display\n8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                list.insertAtStart(value);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> value;
                list.insertAtEnd(value);
                break;
            case 3:
                cout << "Enter value: ";
                cin >> value;
                cout << "Enter position: ";
                cin >> pos;
                list.insertAtPosition(value, pos);
                break;
            case 4:
                list.detectAndRemoveLoop();
                break;
            case 5:
                cout << "Enter N: ";
                cin >> pos;
                list.findNthFromEnd(pos);
                break;
            case 6:
                cout << "Enter K: ";
                cin >> k;
                list.reverseInGroupsK(k);
                break;
            case 7:
                list.display();
                break;
            case 8:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 8);

    return 0;
}
