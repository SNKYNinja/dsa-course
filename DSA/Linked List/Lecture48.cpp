#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

class Node {
  public:
    int data;
    Node* next;
    Node() : data(0), next(nullptr) {};
    Node(int x) : data(x), next(nullptr) {}
    Node(int x, Node* next) : data(x), next(next) {}
};

void duplicateSorted(Node* head) {
    if (head == NULL)
        return;

    Node* curr = head;

    while (curr != NULL) {
        if (curr->next != NULL && curr->data == curr->next->data) {
            Node* temp = curr->next;
            curr->next = curr->next->next;
            delete (temp);
        } else {
            curr = curr->next;
        }
    }
}

void duplicateUnsorted(Node* head) {
    if (head == NULL)
        return;

    unordered_map<int, int> mp;

    Node *curr = head, *prev = head;

    while (curr != NULL) {
        if (mp[curr->data]) {
            prev->next = curr->next;
            curr = curr->next;
        } else {
            mp[curr->data] = 1;
            prev = curr;
            curr = curr->next;
        }
    }
    return;
}

void splitCircularLLInHalf(Node* head) {}

int main() {
    // 1. Remove Duplicates from Sorted LL
    // https://www.naukri.com/code360/problems/unique-sorted-list_2420283

    // 2. Remove Duplicates from Unsorted LL
    // https://www.naukri.com/code360/problems/remove-duplicates-from-unsorted-linked-list_1069331

    // Homework

    // Split Circular Linked List in Half
    // https://www.naukri.com/code360/problems/split-a-circular-linked-list_1071003
}
