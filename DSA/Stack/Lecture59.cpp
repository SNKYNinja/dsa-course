#include <bits/stdc++.h>
using namespace std;

class MinStack {
    stack<int> st;
    int mini;

  public:
    void push(int val) {
        if (st.empty()) {
            st.push(val);
            mini = val;
            return;
        }

        if (val < mini) {
            st.push(2 * val - mini);
            mini = val;
        } else
            st.push(val);
    }

    void pop() {
        if (st.empty()) return;

        int val = st.top();
        if (val < mini) {
            mini = 2 * mini - val;
        }

        st.pop();
    }

    int top() {
        if (st.top() < mini)
            return mini;
        else
            return st.top();
    }

    int getMini() { return mini; }
};

int main() {
    // Design Special Stack
    // https://www.naukri.com/code360/problems/design-a-stack-that-supports-getmin-in-o-1-time-and-o-1-extra-space_842465
    //
    // push()
    // newMin = 2 * curr - prevMin;
    //
    // pop()
    // newMin = 2 * mini - curr;
    // here, curr = 2 * curr - prevMin;
    // Therefore
    // newMin = 2 * curr - 2 * curr + prev;

    MinStack st;

    st.push(-2);
    st.push(0);
    st.push(-3);

    cout << st.getMini() << endl;
    st.pop();
    cout << st.top() << endl;
    cout << st.getMini() << endl;
}
