#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
    Node* head;

    public:
    LinkedList(): head(NULL) {}

    void insertAtBeg(int value) {
        Node* node = new Node();
        node->data = value;
        node->next = head;
    }

    void insertAtEnd(int value) {
        Node* node = new Node;
        node->data = value;
        node->next = NULL;

        if (!head) {
            head = node;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL) temp = temp->next;

        temp->next = node;
    }

    void insertAtPos(int value, int pos) {
        if (pos < 1) {
            cout << "Position should be greater then 1!" << endl;
            return;
        }

        if (pos == 1) {
            insertAtBeg(value);
            return;
        }

        Node* node = new Node();
        node->data = value;

        Node* temp = head;
        for (int i = 1; i < pos - 1 && temp; i++) {
            temp = temp->next;
        }

        if (!temp) {
            cout << "Position out of range!" << endl;
            delete node;
            return;
        }

        node->next = temp->next;
        temp->next = node;
    }

    void deleteFromBeg() {
        if (!head) {
            cout << "List is empty!" << endl;
            return; 
        }

        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void deleteFromEnd() {
        if (!head) {
            cout << "List is empty!" << endl;
            return;
        }

        if (!head->next) {
            delete head;
            head = NULL;
            return;
        }

        Node* temp = head;
        while (temp->next->next) {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;
    }

    void deleteFromPos(int pos) {
        if (pos < 1) {
            cout << "Position should be >= 1!" << endl;
            return; 
        }

        if (pos == 1) {
            deleteFromBeg();
            return;
        }

        Node* temp = head;
        for (int i = 1; i < pos - 1 && temp; i++) {
            temp = temp->next;
        }

        if (!temp || temp->next) {
            cout << "Position out of range!" << endl;
            return;
        }

        Node* del = temp->next;
        temp->next = temp->next->next;
        delete del;
    }

    void display() {
        if (!head) {
            cout << "List is empty!" << endl;
            return;
        }

        Node* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }

        cout << "NULL" << endl;
    }
};

int main() {
    // Initialize a new linked list
    LinkedList list1;

    // Insert elements at the end
    list1.insertAtEnd(10);
    list1.insertAtEnd(20);

    // Insert element at the beginning
    list1.insertAtBeg(5);

    // Insert element at a specific position
    list1.insertAtPos(15, 3);

    cout << "Linked list after insertions: ";
    list1.display();

    // Delete element from the beginning
    list1.deleteFromBeg();
    cout << "Linked list after deleting from beginning: ";
    list1.display();

    // Delete element from the end
    list1.deleteFromEnd();
    cout << "Linked list after deleting from end: ";
    list1.display();

    // Delete element from a specific position
    list1.deleteFromPos(2);
    cout << "Linked list after deleting from position 2: ";
    list1.display();

    return 0;
}
