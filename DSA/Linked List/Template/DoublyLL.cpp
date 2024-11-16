#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

class LinkedList {
    Node* head;

    public:
    LinkedList(): head(NULL) {}

    void insertAtBeg(int value) {
        Node* node = new Node();
        node->data = value;

        if (!head) {
            head = node;
            return;
        }

        node->next = head;
        head->prev = node;
        head = node;
    }

    void insertAtEnd(int value) {
        Node* node = new Node();
        node->data = value;

        if (!head) {
            head = node;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = node;
        node->prev = temp;
    }

    void insertAtPos(int value, int pos) {
        if (pos < 1) {
            cout << "Position should be >= 1!" << endl;
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
            cout << "Position greater than the number of nodes!" << endl;
            return; 
        }

        node->next = temp->next;
        node->prev = temp;
        if (temp->next != NULL) {
            temp->next->prev = node;
        }
        temp->next = node;
    }

    void deleteAtBeg() {
        if (!head) {
            cout << "List is already empty!" << endl;
            return;
        }

        Node* temp = head;
        head = head->next;
        if (!head) {
            head->prev = NULL;
        }
        delete temp;
    }

    void deleteAtEnd() {
        if (!head) {
            cout << "List is already empty!" << endl;
            return;
        }

        Node* temp = head;
        if (!temp->next) {
            head = NULL;
            delete temp;
            return;
        }

        while (temp->next != NULL) {
             temp = temp->next;
        }

        temp->prev->next = NULL;
        delete temp;
    }

    void deleteAtPos(int pos) {
        if (!head) {
            cout << "List is already empty!" << endl;
            return;
        }

        if (pos == 1) {
            deleteAtBeg();
            return;
        }

        Node* temp = head;
        for (int i = 1; i < pos - 1 && temp; i++) {
            temp = temp->next;
        }

        if (!temp) {
            cout << "Position is greater than the number of elements!" << endl;
            return;
        }

        if (temp->next != NULL) {
            temp->next->prev = temp->prev;
        }

        if (temp->prev != NULL) {
            temp->prev->next = temp->next;
        }

        delete temp;
    }

    void printForward() {
        Node* temp = head;
        if (!temp) {
            cout << "The list is emtpy!" << endl;
            return;
        }

        cout << "Forward List: ";
        while (temp->next != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        } cout << endl;
    }

    void printReverse() {
        Node* temp = head;
        if (!temp) {
            cout << "The list is emtpy!" << endl;
            return;
        }

        while (temp->next != NULL) {
            temp = temp->next;
        }

        cout << "Reverse List: ";
        while (temp != NULL) {
            cout << temp->data << " <- ";
            temp = temp->prev;
        } cout << endl;
    }
};

int main() {
    LinkedList list1;

    // Demonstrating various operations on the doubly linked
    // list.
    // Insertion at End
    list1.insertAtEnd(10);
    list1.insertAtEnd(20);
    // Insertion at beginning
    list1.insertAtBeg(5);
    // Insertion at specific position
    list1.insertAtPos(15, 2);

    // print the list
    cout << "After Insertions:" << endl;
    list1.printForward();
    list1.printReverse();

    // deletion from beginning
    list1.deleteAtBeg();
    // deletion from end
    list1.deleteAtEnd();
    // deletion from specific position
    list1.deleteAtPos(2);

    cout << "After Deletions:" << endl;
    list1.printForward();

    return 0;
}