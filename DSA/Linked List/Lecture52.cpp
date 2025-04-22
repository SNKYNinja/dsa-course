#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

class Node {
  public:
    int data;
    Node* next;
    Node* random;
    Node() : data(0), next(nullptr) {};
    Node(int x) : data(x), next(nullptr) {}
    Node(int x, Node* next) : data(x), next(next) {}
};

void insertAtTail(Node*& head, Node*& tail, int data) {
    Node* node = new Node(data);

    if (!head) {
        head = node;
        tail = node;
    } else {
        tail->next = node;
        tail = node;
    }
}

Node* mapSolution(Node* head) {
    Node *cloneHead = NULL, *cloneTail = NULL;

    Node* temp = head;

    while (temp) {
        insertAtTail(cloneHead, cloneTail, temp->data);
        temp = temp->next;
    }

    unordered_map<Node*, Node*> mp;

    Node *original = head, *clone = cloneHead;
    while (original) {
        mp[original] = clone;
        original = original->next;
        clone = clone->next;
    }

    original = head, clone = cloneHead;

    while (original) {
        if (original->random) {
            clone->random = mp[original->random];
        } else
            clone->random = NULL;
        original = original->next;
        clone = clone->next;
    }

    return cloneHead;
}

Node* withoutMapSolution(Node* head) {
    Node *cloneHead = NULL, *cloneTail = NULL;

    Node* temp = head;

    // Creating the cloned list
    while (temp) {
        insertAtTail(cloneHead, cloneTail, temp->data);
        temp = temp->next;
    }

    Node *original = head, *clone = cloneHead;

    // Setting the next pointer of original list nodes to cloned list nodes
    while (original) {
        Node *next = original->next, *cloneNext = clone->next;

        original->next = clone;
        clone->next = next;

        original = next;
        clone = cloneNext;
    }

    // Setting the random pointer
    original = head;
    while (original) {
        if (original->random)
            original->next->random = original->random->next;
        else
            original->next->random = NULL;

        original = original->next->next;
    }

    // Reverting the lists to previous state
    original = head, clone = cloneHead;
    while (original) {
        Node *next = original->next, *cloneNext = clone->next;

        original->next = cloneNext;
        if (cloneNext)
            clone->next = cloneNext->next;

        original = original->next;
        clone = clone->next;
    }

    return cloneHead;
}

int main() {
    // 1. Clone Linked List with Random Pointers
    // https://www.geeksforgeeks.org/problems/clone-a-linked-list-with-next-and-random-pointer/1
}
