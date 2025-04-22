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

Node* solve(Node* first, Node* second) {
    Node* curr1 = first;
    Node* next1 = first->next;
    Node* curr2 = second;
    Node* next2 = second->next;

    if (!next1) {
        curr1->next = curr2;
        return first;
    }

    while (next1 && curr2) {
        if (curr2->data >= curr1->data && curr2->data <= next1->data) {
            curr1->next = curr2;
            curr2->next = next1;
            curr1 = curr2;
            curr2 = next2;
            next2 = next2->next;
        } else {
            curr1 = next1;
            next1 = next1->next;

            // condition required when the first list is fully iterated
            if (!next1) {
                curr1->next = curr2;
                return first;
            }
        }
    }

    return first;
}

Node* mergeSortedLL(Node* first, Node* second) {
    if (!first)
        return second;
    if (!second)
        return first;

    if (first->data <= second->data) {
        return solve(first, second);
    } else
        return solve(second, first);
}

int main() {
    // 1. Sort 0s, 1s and 2s in LL
    // https://www.naukri.com/code360/problems/sort-linked-list-of-0s-1s-2s_1071937

    // 2. Merge Two Sorted Linked List
    // https://www.naukri.com/code360/problems/merge-two-sorted-linked-lists_800332
}
