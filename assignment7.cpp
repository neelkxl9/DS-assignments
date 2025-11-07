#include <iostream>
using namespace std;

class Node {
public:
    int job;
    Node* next;
    Node(int j) {
        job = j;
        next = nullptr;
    }
};

class CircularQueue {
    Node* front;
    Node* rear;
public:
    CircularQueue() { front = rear = nullptr; }

    void enqueue(int job) {
        Node* temp = new Node(job);
        if (front == nullptr) {
            front = rear = temp;
            rear->next = front;
        } else {
            rear->next = temp;
            rear = temp;
            rear->next = front;
        }
        cout << "Added Print Job " << job << " to queue.\n";
    }

    void dequeue() {
        if (front == nullptr) {
            cout << "No print jobs in queue.\n";
            return;
        }

        cout << "Processing Print Job " << front->job << "...\n";

        if (front == rear) {
            delete front;
            front = rear = nullptr;
        } else {
            Node* temp = front;
            front = front->next;
            rear->next = front;
            delete temp;
        }
    }

    void display() {
        if (front == nullptr) {
            cout << "No jobs in queue.\n";
            return;
        }

        cout << "Current Print Jobs: ";
        Node* temp = front;
        do {
            cout << temp->job << " ";
            temp = temp->next;
        } while (temp != front);
        cout << "\n";
    }
};

int main() {
    CircularQueue cq;
    int choice, jobId;

    while (true) {
        cout << "\n--- Printer Queue Menu ---\n";
        cout << "1. Add Print Job\n";
        cout << "2. Process Print Job\n";
        cout << "3. Display Print Jobs\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter Print Job ID: ";
            cin >> jobId;
            cq.enqueue(jobId);
            break;
        case 2:
            cq.dequeue();
            break;
        case 3:
            cq.display();
            break;
        case 4:
            cout << "Exiting...\n";
            return 0;
        default:
            cout << "Invalid choice, try again.\n";
        }
    }
}
