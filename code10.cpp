PRACTICAL NO.11-/*
Department of Computer Engineering has student's club named 'Pinnacle Club'. Students of
second, third and final year of department can be granted membership on request. Similarly one
may cancel the membership of club. First node is reserved for president of club and last node is
reserved for secretary of club. Write C++ program to maintain club member‘s information using
singly linked list. Store student PRN and Name. Write functions to:
a) Add and delete the members as well as president or even secretary.
b) Compute total number of members of club
c) Display members
d) Two linked lists exists for two divisions. Concatenate two lists.
*/



#include <iostream>
#include <string>
using namespace std;

struct Node {
    string name;
    long long PRN;
    Node* next;
};

class PinnacleClub {
private:
    Node* head;

public:
    PinnacleClub() {
        head = nullptr;
    }

    void addPresident(long long prn, string name) {
        Node* newNode = new Node();
        newNode->PRN = prn;
        newNode->name = name;
        newNode->next = head;
        head = newNode;
    }

    void addSecretary(long long prn, string name) {
        Node* newNode = new Node();
        newNode->PRN = prn;
        newNode->name = name;
        newNode->next = nullptr;
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void addMember(long long prn, string name) {
        Node* newNode = new Node();
        newNode->PRN = prn;
        newNode->name = name;
        newNode->next = nullptr;
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void deletePresident() {
        if (head == nullptr) {
            cout << "The list is empty. No President to delete." << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        cout << "President deleted successfully." << endl;
    }

    void deleteSecretary() {
        if (head == nullptr) {
            cout << "The list is empty. No Secretary to delete." << endl;
            return;
        }
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
        } else {
            Node* temp = head;
            while (temp->next->next != nullptr) {
                temp = temp->next;
            }
            delete temp->next;
            temp->next = nullptr;
        }
        cout << "Secretary deleted successfully." << endl;
    }

    void deleteMember(long long prn) {
        if (head == nullptr) {
            cout << "The list is empty. No member to delete." << endl;
            return;
        }
        if (head->PRN == prn) {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "Member with PRN: " << prn << ", deleted successfully." << endl;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr && temp->next->PRN != prn) {
            temp = temp->next;
        }
        if (temp->next == nullptr) {
            cout << "Member with PRN: " << prn << ", not found." << endl;
            return;
        } else {
            Node* delNode = temp->next;
            temp->next = temp->next->next;
            delete delNode;
            cout << "Member with PRN: " << prn << ", deleted successfully." << endl;
        }
    }

    void displayMembers() {
        if (head == nullptr) {
            cout << "The list is empty." << endl;
            return;
        }
        Node* temp = head;
        cout << "Members of the Pinnacle Club: " << endl;
        while (temp != nullptr) {
            cout << "PRN: " << temp->PRN << ", Name: " << temp->name << endl;
            temp = temp->next;
        }
    }

    int countMembers() {
        int count = 0;
        Node* temp = head;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    void concatenate(PinnacleClub& other) {
        if (head == nullptr) {
            head = other.head;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = other.head;
        }
        other.head = nullptr;
    }
};

int main() {
    PinnacleClub div1, div2;
    int choice;
    long long prn;
    string name;

    do {
        cout << "\nMenu:";
        cout << "\n1. Add President";
        cout << "\n2. Add Secretary";
        cout << "\n3. Add Member";
        cout << "\n4. Delete President";
        cout << "\n5. Delete Secretary";
        cout << "\n6. Delete Member";
        cout << "\n7. Display Members";
        cout << "\n8. Count of Members";
        cout << "\n9. Concatenate Divisions";
        cout << "\n10. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter PRN of President: ";
            cin >> prn;
            cin.ignore();  // Clear the buffer before taking string input
            cout << "Enter Name of President: ";
            getline(cin, name);
            div1.addPresident(prn, name);
            break;
        case 2:
            cout << "Enter PRN of Secretary: ";
            cin >> prn;
            cin.ignore();
            cout << "Enter Name of Secretary: ";
            getline(cin, name);
            div1.addSecretary(prn, name);
            break;
        case 3:
            cout << "Enter PRN of Member: ";
            cin >> prn;
            cin.ignore();
            cout << "Enter Name of Member: ";
            getline(cin, name);
            div1.addMember(prn, name);
            break;
        case 4:
            div1.deletePresident();
            break;
        case 5:
            div1.deleteSecretary();
            break;
        case 6:
            cout << "Enter PRN of Member to delete: ";
            cin >> prn;
            div1.deleteMember(prn);
            break;
        case 7:
            div1.displayMembers();
            break;
        case 8:
            cout << "Total Members in the club are: " << div1.countMembers() << endl;
            break;
        case 9:
            div1.concatenate(div2);
            cout << "Divisions concatenated." << endl;
            break;
        case 10:
            cout << "Exiting the Program." << endl;
            break;
        default:
            cout << "Invalid Choice. Try again." << endl;
            break;
        }
    } while (choice != 10);

    return 0;
}
