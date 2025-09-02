#include <bits/stdc++.h>
#include <cinttypes>
using namespace std;

class Node {
  public:
    int data;
    Node *left, *right;

    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* buildTree(Node* root) {
    cout << "Enter data: ";
    int data;
    cin >> data;

    if (data == -1) return NULL;

    root = new Node(data);

    cout << "Enter data for inserting to left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter data for inserting to right of " << data << endl;
    root->right = buildTree(root->right);

    return root;
}

void levelOrderTraversal(Node* root) {
    queue<Node*> q;

    q.push(root);
    q.push(NULL);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (temp == NULL) {
            cout << endl;
            if (!q.empty()) q.push(NULL);
        } else {
            cout << temp->data << " ";
            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }
    }
}

void reverseLevelOrderTraversal(Node* root) {
    queue<Node*> q;
    stack<int> st;
    q.push(root);
    q.push(NULL);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (temp == NULL) {
            st.push(-1);
            if (!q.empty()) q.push(NULL);
        } else {
            st.push(temp->data);
            if (temp->right) q.push(temp->right);
            if (temp->left) q.push(temp->left);
        }
    }

    while (!st.empty()) {
        if (st.top() == -1)
            cout << endl;
        else
            cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

int main() {
    Node* root = NULL;

    root = buildTree(root);

    cout << "Level Order Traversal" << endl;
    levelOrderTraversal(root);

    cout << "Reverse Level Order Traversal" << endl;
    reverseLevelOrderTraversal(root);
}
