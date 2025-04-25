PRACTICAL NO.9-
/*
Second year Computer Engineering class, set A of students like Vanilla Ice-cream
and set B of students like butterscotch ice-cream Write C++ Program to store two
sets using linked list. compute and display
1) Set of students who like both Vanilla and Butterscotch
2) Set of students who like either Vanilla or Butterscotch or not both
3) Number of students who like neither Vanilla nor Butterscotch.
*/



#include <iostream>
using namespace std;

struct node {
    int roll;
    struct node* next;
};

class info {
    node* head1 = NULL;
    node* head2 = NULL;
    node* head3 = NULL;

public:
    node* create();
    void insert(node*& head);
    void display(node* head);
    void allstud();
    void vanilla();
    void butters();
    void uice();
    void ovanilla();
    void obutters();
    void nice();
};

node* info::create() {
    node* p = new node;
    cout << "Enter Student's Roll no: ";
    cin >> p->roll;
    p->next = NULL;
    return p;
}

void info::insert(node*& head) {
    node* p = create();
    if (head == NULL) {
        head = p;
    } else {
        node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = p;
    }
}

void info::display(node* head) {
    node* temp = head;
    if (head == NULL) {
        cout << "\nNo records found.";
        return;
    }
    while (temp != NULL) {
        cout << "\n" << temp->roll;
        temp = temp->next;
    }
    cout << endl;
}

void info::allstud() {
    int k;
    cout << "Enter no. of Students: ";
    cin >> k;
    head1 = head2 = head3 = NULL;
    for (int i = 0; i < k; ++i) {
        insert(head1);
    }
    display(head1);
}

void info::vanilla() {
    int k;
    cout << "Enter no. of Students who like Vanilla: ";
    cin >> k;
    for (int i = 0; i < k; ++i) {
        insert(head1);
    }
    display(head1);
}

void info::butters() {
    int k;
    cout << "Enter no. of Students who like Butterscotch: ";
    cin >> k;
    for (int i = 0; i < k; ++i) {
        insert(head2);
    }
    display(head2);
}

void info::uice() {
    cout << "\nStudents who like Vanilla or Butterscotch:\n";
    head3 = NULL;  // Clear head3 before populating

    node* temp1 = head1;
    while (temp1 != NULL) {
        insert(head3);
        temp1 = temp1->next;
    }

    node* temp2 = head2;
    while (temp2 != NULL) {
        bool found = false;
        node* check = head1;
        while (check != NULL) {
            if (temp2->roll == check->roll) {
                found = true;
                break;
            }
            check = check->next;
        }
        if (!found) {
            insert(head3);
        }
        temp2 = temp2->next;
    }

    display(head3);
}

void info::ovanilla() {
    cout << "\nStudents who like only Vanilla:\n";
    node* temp1 = head1;
    while (temp1 != NULL) {
        bool found = false;
        node* temp2 = head2;
        while (temp2 != NULL) {
            if (temp1->roll == temp2->roll) {
                found = true;
                break;
            }
            temp2 = temp2->next;
        }
        if (!found) {
            cout << "\n" << temp1->roll;
        }
        temp1 = temp1->next;
    }
    cout << endl;
}

void info::obutters() {
    cout << "\nStudents who like only Butterscotch:\n";
    node* temp2 = head2;
    while (temp2 != NULL) {
        bool found = false;
        node* temp1 = head1;
        while (temp1 != NULL) {
            if (temp2->roll == temp1->roll) {
                found = true;
                break;
            }
            temp1 = temp1->next;
        }
        if (!found) {
            cout << "\n" << temp2->roll;
        }
        temp2 = temp2->next;
    }
    cout << endl;
}

void info::nice() {
    cout << "\nStudents who like both Vanilla and Butterscotch:\n";
    node* temp1 = head1;
    while (temp1 != NULL) {
        node* temp2 = head2;
        while (temp2 != NULL) {
            if (temp1->roll == temp2->roll) {
                cout << "\n" << temp1->roll;
            }
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
    cout << endl;
}

int main() {
    info s;
    char ch;
    do {
        int i;
        cout << "\nMenu";
        cout << "\n\t1. Enter Roll number";
        cout << "\n\t2. Students who like Vanilla";
        cout << "\n\t3. Students who like Butterscotch";
        cout << "\n\t4. Display students who like Vanilla or Butterscotch";
        cout << "\n\t5. Display students who like only Vanilla";
        cout << "\n\t6. Display students who like only Butterscotch";
        cout << "\n\t7. Display roll no of students who like both Vanilla and Butterscotch";
        cout << "\n\t8. Exit";
        cout << "\nEnter Choice: ";
        cin >> i;

        switch (i) {
            case 1:
                s.allstud();
                break;
            case 2:
                s.vanilla();
                break;
            case 3:
                s.butters();
                break;
            case 4:
                s.uice();
                break;
            case 5:
                s.ovanilla();
                break;
            case 6:
                s.obutters();
                break;
            case 7:
                s.nice();
                break;
            case 8:
                return 0;
            default:
                cout << "Wrong Choice";
        }

        cout << "\nDo you want to continue (y/n)? ";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');

    return 0;
}
