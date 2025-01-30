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

bool detectCycle(Node* head) {
    if (head == NULL)
        return false;

    Node *slow = head, *fast = head;

    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;

        if (slow == fast)
            return true;
    }

    return false;
}

Node* startingLoopNode(Node* head) {
    if (head == NULL || head->next == NULL)
        return NULL;

    Node *slow = head, *fast = head;

    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;

        if (slow == fast)
            break;
    }

    if (slow != fast)
        return NULL;

    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}

void removeLoop(Node* head) {
    if (head != NULL)
        return;

    Node* start = startingLoopNode(head);
    if (!start)
        return;
    Node* temp = start->next;

    while (temp->next != start) {
        temp = temp->next;
    }

    temp->next = NULL;

    return;
}

int main() {
    // 1. Detect and Remove Loop
    // https://www.naukri.com/code360/problems/interview-shuriken-42-detect-and-remove-loop_241049
}
