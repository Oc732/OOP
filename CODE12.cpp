Practical n0.12-/*
A palindrome is a string of character that‘s the same forward and backward.
Typically, punctuation, capitalization, and spaces are ignored. For example, Poor
Dan is in a droop is a palindrome, as can be seen by examining the characters?
poor danisina droop? And observing that they are the same forward and backward.
One way to check for a palindrome is to reverse the characters in the string and
then compare with them the original-in a palindrome, the sequence will be
identical. Write C++ program with functions:
1. To check whether given string is palindrome or not that uses a stack to
determine whether
a string is a palindrome.
2. To remove spaces and punctuation in string, convert all the Characters to
lowercase, and then call above Palindrome checking function to check for a
palindrome
3. To print string in reverse order using stack.
*/





#include <iostream>
using namespace std;

class binary; // Forward declaration

// Node structure for the doubly linked list
class node {
    node* prev;
    bool n;
    node* next;

public:
    node() {
        prev = next = NULL;
    }

    node(bool b) {
        n = b;
        prev = next = NULL;
    }

    friend class binary;
};

// Class to perform binary operations
class binary {
    node* start;

public:
    binary() {
        start = NULL;
    }

    void generateBinary(int no);
    void displayBinary();
    void onesComplement();
    void twosComplement();
    binary operator+(binary n1);
    bool addBitAtBegin(bool val);
};

// Function to add a bit at the beginning of the binary number
bool binary::addBitAtBegin(bool val) {
    node* newNode = new node(val);
    if (start == NULL) {
        start = newNode;
    } else {
        newNode->next = start;
        start->prev = newNode;
        start = newNode;
    }
    return true;
}

// Function to generate binary representation from a decimal number
void binary::generateBinary(int no) {
    if (no == 0) {
        start = new node(0);
        return;
    }

    start = NULL; // Reset the list
    while (no != 0) {
        bool rem = no % 2;
        addBitAtBegin(rem);
        no /= 2;
    }
}

// Function to display the binary number
void binary::displayBinary() {
    node* temp = start;
    while (temp != NULL) {
        cout << temp->n;
        temp = temp->next;
    }
    cout << endl;
}

// Function to compute one's complement
void binary::onesComplement() {
    node* temp = start;
    while (temp != NULL) {
        temp->n = !temp->n;
        temp = temp->next;
    }
}

// Function to compute two's complement
void binary::twosComplement() {
    onesComplement(); // First compute the one's complement
    bool carry = 1;
    node* temp = start;

    // Move to the last node
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Add 1 to the one's complement
    while (temp != NULL) {
        if (temp->n == 1 && carry == 1) {
            temp->n = 0;
            carry = 1;
        } else if (temp->n == 0 && carry == 1) {
            temp->n = 1;
            carry = 0;
        } else {
            break;
        }
        temp = temp->prev;
    }
    displayBinary();
}

// Overload the + operator for binary addition
binary binary::operator+(binary n1) {
    binary sum;
    node* a = start;
    node* b = n1.start;
    bool carry = false;

    // Move to the last nodes
    while (a != NULL && a->next != NULL) a = a->next;
    while (b != NULL && b->next != NULL) b = b->next;

    // Add bits from both numbers
    while (a != NULL || b != NULL) {
        bool bitA = (a != NULL) ? a->n : 0;
        bool bitB = (b != NULL) ? b->n : 0;
        sum.addBitAtBegin(bitA ^ bitB ^ carry);
        carry = (bitA && bitB) || (bitA && carry) || (bitB && carry);

        if (a != NULL) a = a->prev;
        if (b != NULL) b = b->prev;
    }

    // Add any remaining carry
    if (carry) {
        sum.addBitAtBegin(carry);
    }

    return sum;
}

// Main function to interact with the user
int main() {
    int num, num1;
    binary n1, n2, n3;
    int choice = 1;

    do {
        cout << "\n\n========= Binary Number Operations =========\n";
        cout << "1. Generate binary\n2. One's Complement\n3. Two's Complement\n4. Addition\n0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "\nEnter Number in decimal form: ";
                cin >> num;
                n1.generateBinary(num);
                cout << "Binary Representation: ";
                n1.displayBinary();
                break;

            case 2:
                cout << "\nEnter Number in decimal form: ";
                cin >> num;
                n1.generateBinary(num);
                cout << "Binary Representation: ";
                n1.displayBinary();
                cout << "One's Complement: ";
                n1.onesComplement();
                n1.displayBinary();
                break;

            case 3:
                cout << "\nEnter Number in decimal form: ";
                cin >> num;
                n1.generateBinary(num);
                cout << "Binary Representation: ";
                n1.displayBinary();
                cout << "Two's Complement: ";
                n1.twosComplement();
                break;

            case 4:
                cout << "\nEnter Two Numbers: ";
                cin >> num >> num1;
                n1.generateBinary(num);
                n2.generateBinary(num1);
                cout << "First Binary: ";
                n1.displayBinary();
                cout << "Second Binary: ";
                n2.displayBinary();
                cout << "Sum: ";
                n3 = n1 + n2;
                n3.displayBinary();
                break;

            case 0:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Wrong Choice! Please try again.\n";
        }

    } while (choice != 0);

    return 0;
}
