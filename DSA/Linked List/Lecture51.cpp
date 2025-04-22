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

void insertAtTail(Node*& head, Node*& tail, int data) {
    Node* temp = new Node(data);

    if (!head) {
        head = temp;
        tail = temp;
    } else {
        tail->next = temp;
        tail = temp;
    }
}

Node* solve(Node* first, Node* second) {
    int sum = 0, carry = 0;

    Node *head = NULL, *tail = NULL;

    while (first || second || carry) {
        int num1 = first ? first->data : 0;
        int num2 = second ? second->data : 0;

        sum = num1 + num2 + carry;
        int digit = sum % 10;
        carry = sum / 10;

        insertAtTail(head, tail, digit);

        if (first)
            first = first->next;
        if (second)
            second = second->next;
    }

    return head;
}

Node* addTwoLists(Node* first, Node* second) {
    first = reverse(first);
    second = reverse(second);

    Node* ans = solve(first, second);
    ans = reverse(ans);

    // Remove leading 0s
    while (ans && ans->data == 0) {
        Node* temp = ans;
        ans = ans->next;
        delete (temp);
    }

    return ans;
}

int main() {
    // Add 2 Numbers
    // https://www.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1
}
