#include <iostream>
using namespace std;

struct Task {
    int priority;
    int etime;
    Task* next;
};

void appendTask(Task* &head, int priority, int etime) {
    Task* newTask = new Task{priority, etime, nullptr};
    if (!head) {
        head = newTask;
        return;
    }
    Task* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newTask;
}

Task* sortByPriority(Task* head) {
    if (!head || !head->next) return head;
    Task* sorted = nullptr;

    while (head) {
        Task* curr = head;
        head = head->next;
        if (!sorted || curr->priority > sorted->priority) {
            curr->next = sorted;
            sorted = curr;
        } else {
            Task* p = sorted;
            while (p->next && p->next->priority >= curr->priority) p = p->next;
            curr->next = p->next;
            p->next = curr;
        }
    }
    return sorted;
}

Task* sortByTime(Task* head) {
    if (!head || !head->next) return head;
    Task* sorted = nullptr;

    while (head) {
        Task* curr = head;
        head = head->next;
        if (!sorted || curr->etime < sorted->etime) {
            curr->next = sorted;
            sorted = curr;
        } else {
            Task* p = sorted;
            while (p->next && p->next->etime <= curr->etime) p = p->next;
            curr->next = p->next;
            p->next = curr;
        }
    }
    return sorted;
}

void printTasks(Task* head) {
    while (head) {
        cout << "Priority: " << head->priority << ", Execution time: " << head->etime << "ms\n";
        head = head->next;
    }
}

void deleteTasks(Task* &head) {
    while (head) {
        Task* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Task* taskList = nullptr;

    appendTask(taskList, 4, 100);
    appendTask(taskList, 1, 100);
    appendTask(taskList, 3, 100);
    appendTask(taskList, 2, 100);
    appendTask(taskList, 4, 50);
    appendTask(taskList, 3, 150);
    appendTask(taskList, 3, 90);

    int choice;
    do {
        cout << "\nMenu:\n1. Sort by Priority (desc)\n2. Sort by Execution Time (asc)\n3. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                taskList = sortByPriority(taskList);
                cout << "\nTasks sorted by Priority:\n";
                printTasks(taskList);
                break;
            case 2:
                taskList = sortByTime(taskList);
                cout << "\nTasks sorted by Execution Time:\n";
                printTasks(taskList);
                break;
            case 3:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 3);

    deleteTasks(taskList);
    return 0;
}

