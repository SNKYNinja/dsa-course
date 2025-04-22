#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node* next;
    Node* child;
    Node() : data(0), next(nullptr) {};
    Node(int x) : data(x), next(nullptr) {}
    Node(int x, Node* next) : data(x), next(next) {}
};

Node* findMid(Node* head) {
    Node *slow = head, *fast = head->next;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

Node* merge(Node* left, Node* right) {
    if (!left)
        return right;
    if (!right)
        return left;

    Node* head = new Node(-1);
    Node* temp = head;

    while (left && right) {
        if (left->data <= right->data) {
            temp->next = left;
            left = left->next;
        } else {
            temp->next = right;
            right = right->next;
        }

        temp = temp->next;
    }

    while (left) {
        temp->next = left;
        left = left->next;
        temp = temp->next;
    }

    while (right) {
        temp->next = right;
        right = right->next;
        temp = temp->next;
    }

    head = head->next;
    return head;
}

Node* mergeSort(Node* head) {
    // base case
    if (!head || !head->next)
        return head;

    Node* middle = findMid(head);
    Node *left = head, *right = middle->next;
    middle->next = NULL;

    left = mergeSort(left);
    right = mergeSort(right);

    Node* result = merge(left, right);

    return result;
}

Node* merge2(Node* head) {}

Node* flattenLinkedList(Node* head) {}

int main() {
    // 1. Merge Sort in a Linked List
    // https://www.naukri.com/code360/problems/mergesort-linked-list_630514
}
