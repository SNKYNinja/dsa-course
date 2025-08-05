#include <bits/stdc++.h>
using namespace std;

class NStack {
    int *arr, *top, *next;
    int n, s, freespot;

  public:
    NStack(int N, int S) {
        n = N;
        s = S;
        arr = new int[S];
        top = new int[N];
        next = new int[S];

        for (int i = 0; i < N; i++)
            top[i] = -1;

        for (int i = 0; i < S - 1; i++)
            next[i] = i + 1;
        next[S - 1] = -1;

        freespot = 0;
    }
    bool push(int x, int m) {
        if (freespot == -1) return false;

        int index = freespot;
        freespot = next[index];
        arr[index] = x;
        next[index] = top[m - 1];
        top[m - 1] = index;

        return true;
    }

    int pop(int m) {
        if (top[m - 1] == -1) return -1;

        int index = top[m - 1];
        top[m - 1] = next[index];
        next[index] = freespot;
        freespot = index;

        return arr[index];
    }

    void print() {
        for (int i = 0; i < s; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    // N Stacks in Array
    // https://www.naukri.com/code360/problems/n-stacks-in-an-array_1164271
    NStack st(3, 6);

    st.push(10, 1);
    st.push(20, 1);

    st.push(4, 2);
    st.push(3, 3);
    st.push(2, 2);

    cout << st.pop(1) << endl;
    st.push(5, 2);
    st.push(6, 2);

    st.print();
}
