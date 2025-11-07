#include <iostream>
using namespace std;

class Node {
public:
    int customer;
    Node* next;

    Node(int c) {
        customer = c;
        next = nullptr;
    }
};

class SimpleQueue {
    Node* front;
    Node* rear;

public:
    SimpleQueue() {
        front = rear = nullptr;
    }

    void enqueue(int customer) {
        Node* temp = new Node(customer);
        if (rear == nullptr) {
            front = rear = temp;
        } else {
            rear->next = temp;
            rear = temp;
        }
        cout << "Customer " << customer << " arrived.\n";
    }

    void dequeue() {
        if (front == nullptr) {
            cout << "No customer to serve.\n";
            return;
        }
        cout << "Serving Customer " << front->customer << "...\n";
        Node* temp = front;
        front = front->next;
        if (front == nullptr)
            rear = nullptr;
        delete temp;
    }

    void display() {
        if (front == nullptr) {
            cout << "No customers in line.\n";
            return;
        }
        cout << "Customers in line: ";
        Node* temp = front;
        while (temp != nullptr) {
            cout << temp->customer << " ";
            temp = temp->next;
        }
        cout << "\n";
    }
};

int main() {
    SimpleQueue q;
    int choice, customerId;

    while (true) {
        cout << "\n--- Queue Menu ---\n";
        cout << "1. Enqueue (Add customer)\n";
        cout << "2. Dequeue (Serve customer)\n";
        cout << "3. Display Queue\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter customer ID: ";
            cin >> customerId;
            q.enqueue(customerId);
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            q.display();
            break;
        case 4:
            cout << "Exiting...\n";
            return 0;
        default:
            cout << "Invalid choice, try again.\n";
        }
    }
}
