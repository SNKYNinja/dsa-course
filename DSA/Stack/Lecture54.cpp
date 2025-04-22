#include <bits/stdc++.h>
using namespace std;

// Stack implementation
class StackArray {
  private:
    int top;
    int size;
    int* data;

  public:
    StackArray(int size) {
        this->size = size;
        this->data = new int[size];
        this->top = -1;
    }

    void push(int data) {
        if (top + 1 == size) {
            cout << "Stack overflow!" << endl;
            return;
        }

        this->data[++top] = data;
    }

    void pop() {
        if (top == -1) {
            cout << "Stack underflow!" << endl;
            return;
        }

        top--;
    }

    bool isEmpty() { return top == -1; }

    int peek() {
        if (top < 0 || top >= size) {
            cout << "Stack is Empty!" << endl;
            return -1;
        }

        return this->data[top];
    }
};

class Node {
  public:
    int data;
    Node* next;
    Node() : data(0), next(nullptr) {};
    Node(int x) : data(x), next(nullptr) {}
    Node(int x, Node* next) : data(x), next(next) {}
};

class StackLL {
    Node* head;
    Node* top;
    int size;

  public:
    StackLL() {
        head = NULL;
        top = NULL;
        size = 0;
    }

    void push(int data) {
        Node* node = new Node(data);

        if (!head) {
            head = node;
            top = node;
        } else {
            top->next = node;
            top = node;
        }

        size++;
    }

    int pop() {
        if (isEmpty())
            return -1;

        Node* temp = top;
        top = top->next;
        int val = temp->data;
        delete temp;

        size--;

        return val;
    }

    bool isEmpty() { return size == 0 || !top; }

    int peek() {
        if (!top)
            return -1;
        return top->data;
    }
};

int main() {
    // stack
    stack<int> s;

    s.push(2);
    s.push(3);

    s.pop();

    cout << s.top() << endl;
}
