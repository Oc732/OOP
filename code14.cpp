PRACTICAL NO.14-/*
Queues are frequently used in computer programming, and a typical example is the
creation of a job queue by an operating system. If the operating system does not
use priorities, then the jobs are processed in the order they enter the system.
Write C++program for simulating job queue. Write functions to add job and delete
job from queue.
*/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Job {
    static int k;
    int id;
    string name;

public:
    Job() : id(0), name("") {} // Default constructor

    void createJob(string n) {
        id = k++;
        name = n;
    }

    void showJob() const {
        cout << setw(10) << id << setw(10) << name << endl;
    }
};

int Job::k = 101;

class JobQueue {
    Job* q;
    int size;
    int front, rear;

public:
    JobQueue(int s) : size(s) {
        q = new Job[size];
        front = rear = -1;
    }

    ~JobQueue() {
        delete[] q;
    }

    bool isEmpty() const {
        return rear == -1;
    }

    bool isFull() const {
        return (rear + 1) % size == front;
    }

    void createNewJob(const Job& j) {
        if (isFull()) {
            cout << "Job Queue is Full" << endl;
            return;
        }
        rear = (rear + 1) % size;
        q[rear] = j;
        if (front == -1) front = 0; // Set front for the first element
    }

    void processJob() {
        if (isEmpty()) {
            cout << "Job Queue is Empty" << endl;
            return;
        }

        cout << setw(10) << "ID" << setw(10) << "Name" << endl;
        q[front].showJob();
        cout << "Processed..." << endl;

        if (front == rear) {
            // Only one element was in the queue
            front = rear = -1;
        } else {
            front = (front + 1) % size;
        }
    }

    void showJobs() const {
        if (isEmpty()) {
            cout << "Currently No Jobs in the Queue" << endl;
            return;
        }

        cout << "Job Queue" << endl;
        cout << setw(10) << "ID" << setw(10) << "Name" << endl;

        for (int i = front; i != rear; i = (i + 1) % size) {
            q[i].showJob();
        }
        q[rear].showJob();
    }

    void nextJobToBeProcessed() const {
        if (!isEmpty()) {
            cout << setw(10) << "ID" << setw(10) << "Name" << endl;
            q[front].showJob();
        } else {
            cout << "No Jobs to Process" << endl;
        }
    }

    void lastCreatedJob() const {
        if (!isEmpty()) {
            cout << setw(10) << "ID" << setw(10) << "Name" << endl;
            q[rear].showJob();
        } else {
            cout << "No Jobs Created Yet" << endl;
        }
    }
};

int main() {
    JobQueue jq(4);
    Job j;

    do {
        cout << "\n\nMenu" << endl;
        cout << "1. Create Job\n2. Process Job\n";
        cout << "3. Show All Jobs in the Queue\n";
        cout << "4. Show the Next Job to be Processed\n";
        cout << "5. Show the Last Created Job\n6. Exit\n";
        cout << "Enter Your Choice: ";
        
        int ch;
        cin >> ch;
        cin.ignore(); // Clear input buffer
        string name;

        switch (ch) {
            case 1:
                if (!jq.isFull()) {
                    cout << "Enter job name: ";
                    getline(cin, name);
                    j.createJob(name);
                    jq.createNewJob(j);
                } else {
                    cout << "Job Queue is Full" << endl;
                }
                break;
            case 2:
                jq.processJob();
                break;
            case 3:
                jq.showJobs();
                break;
            case 4:
                jq.nextJobToBeProcessed();
                break;
            case 5:
                jq.lastCreatedJob();
                break;
            case 6:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid Choice. Try Again!" << endl;
        }
    } while (true);

    return 0;
}
