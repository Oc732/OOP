practical no.15-/*
Write program to implement a priority queue in C++ using an inorder list to store
the items in the queue. Create a class that includes the data items (which should
be template) and the priority (which should be int). The inorder list should
contain these objects, with operator <= overloaded so that the items with highest
priority appear at the start of the list (which will make it relatively easy to
retrieve the highest item.)
*/


#include <iostream>
using namespace std;

struct Node {  // Node structure for priority queue
    int info;
    int priority;
    Node* next;
    Node(int i, int p) : info(i), priority(p), next(nullptr) {}
};

class PriorityQueue {
private:
    Node* front;

public:
    // Constructor
    PriorityQueue() : front(nullptr) {}

    // Insert method
    void insert(int value, int priority) {
        Node* newNode = new Node(value, priority);

        // If the queue is empty or the new node has the highest priority
        if (front == nullptr || priority < front->priority) {
            newNode->next = front;
            front = newNode;
        } else {
            // Traverse the queue and find the correct position for the new node
            Node* current = front;
            while (current->next != nullptr && current->next->priority <= priority) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
    }

    // Delete method
    void del() {
        if (front == nullptr) {
            cout << "Queue Underflow\n";
        } else {
            Node* temp = front;
            cout << "Deleted item is: " << temp->info << endl;
            front = front->next;
            delete temp;
        }
    }

    // Display method
    void show() {
        if (front == nullptr) {
            cout << "Queue is empty\n";
        } else {
            cout << "Queue is:\n";
            cout << "Priority  Item\n";
            Node* ptr = front;
            while (ptr != nullptr) {
                cout << ptr->priority << "         " << ptr->info << endl;
                ptr = ptr->next;
            }
        }
    }

    // Destructor to free memory
    ~PriorityQueue() {
        while (front != nullptr) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }
};

// Main function
int main() {
    int choice, value, priority;
    PriorityQueue pq;

    do {
        cout << "\n1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the item value to be added in the queue: ";
                cin >> value;
                cout << "Enter its priority: ";
                cin >> priority;
                pq.insert(value, priority);
                break;
            case 2:
                pq.del();
                break;
            case 3:
                pq.show();
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 4);

    return 0;
}
