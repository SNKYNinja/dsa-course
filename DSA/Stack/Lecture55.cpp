#include <bits/stdc++.h>
using namespace std;

string reverse(string str) {
    stack<char> st;

    for (char ch : str) {
        st.push(ch);
    }

    for (int i = 0; i < str.length(); i++) {
        str[i] = st.top();
        st.pop();
    }

    return str;
}

void removeMiddle(stack<int>& st, int cnt, int n) {
    if (cnt == n / 2) {
        st.pop();
        return;
    }

    int top = st.top();
    st.pop();
    removeMiddle(st, cnt + 1, n);
    st.push(top);
}

bool validParenthesis(string s) {
    stack<char> st;

    for (char ch : s) {
        if (ch == '(' || ch == '[' || ch == '{')
            st.push(ch);
        else {
            if (st.empty()) return false;

            if ((st.top() == '(' && ch == ')') || (st.top() == '[' && ch == ']') ||
                (st.top() == '{' && ch == '}'))
                st.pop();
            else
                return false;
        }
    }

    return st.empty();
}

void insertAtBottom(stack<int>& st, int x) {
    if (st.empty()) {
        st.push(x);
        return;
    }

    int top = st.top();
    st.pop();
    insertAtBottom(st, x);
    st.push(top);
}

void reverseStack(stack<int>& st) {
    if (st.empty()) return;

    int top = st.top();
    st.pop();
    reverseStack(st);
    insertAtBottom(st, top);
}

void insertForSort(stack<int>& st, int x) {
    if (st.empty() || st.top() < x) {
        st.push(x);
        return;
    }

    int top = st.top();
    st.pop();
    insertForSort(st, x);
    st.push(top);
}

void sortStack(stack<int>& st) {
    if (st.empty()) return;

    int top = st.top();
    st.pop();
    sortStack(st);
    insertForSort(st, top);
}

bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

bool redundantBracket(string s) {
    stack<char> st;

    for (char ch : s) {
        if (ch == '(' || isOperator(ch))
            st.push(ch);
        else if (ch == ')') {
            // iterate to find if the current bracket pair is redundanr or not
            bool isRedundant = true;

            while (st.top() != '(') {
                if (isOperator(st.top())) isRedundant = false;
                st.pop();
            }

            if (isRedundant) return true;
            st.pop(); // remove the '('
        }
    }

    return false;
}

int minimumCount(string s) {
    if (s.length() & 1) return -1;

    stack<char> st;

    for (char ch : s) {
        if (ch == '{')
            st.push(ch);
        else {
            if (!st.empty() && st.top() == '{')
                st.pop();
            else
                st.push(ch);
        }
    }

    int a = 0, b = 0;
    while (!st.empty()) {
        if (st.top() == '{')
            a++;
        else
            b++;

        st.pop();
    }

    return (a + 1) / 2 + (b + 1) / 2;
}

int main() {
    // 1. Reverse string using Stack
    /* string a = "love"; */
    /* cout << reverse(a) << endl; */

    // 2. Delete Middle Element in Stack
    // https://www.naukri.com/code360/problems/delete-middle-element-from-stack_985246

    // 3. Valid Parentheses
    // https://www.naukri.com/code360/problems/valid-parenthesis_795104

    // 4. Insert At Bottom
    // https://www.naukri.com/code360/problems/insert-an-element-at-its-bottom-in-a-given-stack_1171166

    // 5. Reverse Stack using Recursion
    // https://www.naukri.com/code360/problems/reverse-stack-using-recursion_631875

    // 6. Sort a Stack
    // https://www.naukri.com/code360/problems/sort-a-stack_985275

    // 7. Redundant Brackets
    // https://www.naukri.com/code360/problems/redundant-brackets_975473

    // 8. Minimum Cost to Make String Valid
    // https://www.naukri.com/code360/problems/minimum-cost-to-make-string-valid_1115770
}
