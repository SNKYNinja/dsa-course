#include <bits/stdc++.h>
using namespace std;

class QueueArray {
    int* arr;
    int front, rear;
    int size = 100001;

  public:
    QueueArray() {
        arr = new int[size];
        front = 0; /// place where the pop element exists
        rear = 0;  // place where the push value will be appended
    }
    void push(int val) {
        if (rear == size) return;
        arr[rear++] = val;
    }
    void pop() {
        if (isEmpty()) return;
        arr[front] = -1;
        front++;

        if (front == rear) {
            front = 0;
            rear = 0;
        }
    }
    int qfront() {
        if (isEmpty()) return -1;
        return arr[front];
    }
    bool isEmpty() { return front == rear; }
};

class CircularQueue {
    int *arr, size, front, rear;

  public:
    CircularQueue(int size) {
        this->size = size;
        arr = new int[size];
        front = rear = -1;
    }

    bool isFull() { return ((rear + 1) % size) == front; }
    bool isEmpty() { return front == -1; }

    bool enqueue(int val) {
        if (isFull()) return false;

        if (isEmpty())
            front = rear = 0;
        else
            rear = (rear + 1) % size;

        arr[rear] = val;

        return true;
    }

    int dequeue() {
        if (isEmpty()) return -1;

        int val = arr[front];

        if (front == rear) // only one element in queue
            front = rear = -1;
        else
            front = (front + 1) % size;

        return val;
    }

    int qfront() {
        if (isEmpty()) return -1;
        return arr[front];
    }
};

class DEQueue {
    int *arr, front, rear, n;

    DEQueue(int size) {
        n = size;
        arr = new int[size];
        front = rear = -1;
    }

    bool isEmpty() { return front == -1; }
    bool isFull() { return ((rear + 1) % n) == front; }

    bool push_front(int val) {
        if (isFull()) return false;

        if (front == -1) {
            front = rear = 0;
        } else {
            front = (front - 1 + n) % n;
        }

        arr[front] = val;
        return true;
    }

    bool push_rear(int val) {
        if (isFull()) return false;

        if (front == -1) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % n;
        }

        arr[rear] = val;
        return true;
    }

    int pop_front() {
        if (isEmpty()) return -1;

        int val = arr[front];

        if (front == rear) { // single element case
            front = rear = -1;
        } else {
            front = (front + 1) % n;
        }

        return val;
    }

    int pop_rear() {
        if (isEmpty()) return -1;

        int val = arr[rear];

        if (front == rear) { // single element case
            front = rear = -1;
        } else {
            rear = (rear - 1 + n) % n;
        }

        return val;
    }
};

int main() {
    // 1. Queue Implementation
    // https://www.naukri.com/code360/problems/queue-using-array-or-singly-linked-list_2099908

    QueueArray que;

    que.push(55);
    que.push(43);
    que.push(100);

    cout << que.qfront() << endl;
    que.pop();
    cout << que.qfront() << endl;

    // 2. Circular Queue
    // https://www.naukri.com/code360/problems/circular-queue_1170058

    CircularQueue que2(10);

    que2.enqueue(40);
    que2.enqueue(200);

    cout << que2.qfront() << endl;
    que2.dequeue();
    cout << que2.qfront() << endl;
}
