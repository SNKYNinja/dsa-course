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

Node* getMid(Node* head) {
    Node *slow = head, *fast = head->next;

    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;
}

Node* reverse(Node* head) {
    Node *curr = head, *prev = NULL, *next = NULL;

    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

bool isPalindrone(Node* head) {
    if (!head || !head->next)
        return true;

    Node* middle = getMid(head);

    Node* temp = middle->next;
    middle->next = reverse(temp);

    Node *head1 = head, *head2 = middle->next;

    while (head2) {
        if (head1->data != head2->data)
            return false;
        head1 = head1->next;
        head2 = head2->next;
    }

    return true;
}

int main() {
    // 1. Check List for Palindrome
    // https://www.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1
}
