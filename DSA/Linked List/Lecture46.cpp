#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node* next;
    Node() : data(0), next(nullptr) {};
    Node(int x) : data(x), next(nullptr) {}
    Node(int x, Node* next) : data(x), next(next) {}
};

int getSize(Node* head) {
    int count = 0;

    while (head != NULL) {
        count++;
        head = head->next;
    }

    return count;
}

Node* kReverse(Node* head, int k) {
    if (head == NULL || getSize(head) < k)
        return head;

    Node *curr = head, *prev = NULL, *next = NULL;
    int count = 0;

    while (curr != NULL && count < k) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    if (curr != NULL) {
        head->next = kReverse(curr, k);
    }

    return prev;
}

bool isCircular(Node* head) {
    Node* temp = head->next;

    while (temp != NULL && temp != head) {
        temp = temp->next;
    }

    return temp == head;
}

int main() {
    // Questions on Linked List

    // 1. Reverse List in K Groups
    // https://www.naukri.com/code360/problems/reverse-list-in-k-groups_983644

    // 2. Circular Linked List or not
    // https://www.naukri.com/code360/problems/circularly-linked_1070232
}
