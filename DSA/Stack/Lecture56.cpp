#include <bits/stdc++.h>
using namespace std;

vector<int> nextSmaller(vector<int>& arr, int n) {
    stack<int> st;
    st.push(-1);
    vector<int> ans(n);

    for (int i = n - 1; i >= 0; i--) {
        while (st.top() >= arr[i])
            st.pop();

        ans[i] = st.top();
        st.push(arr[i]);
    }

    return ans;
}

vector<int> next(vector<int>& arr, int n) {
    stack<int> st;
    st.push(-1);
    vector<int> ans;

    for (int i = n - 1; i >= 0; i--) {
        while (st.top() != -1 && arr[st.top()] >= arr[i])
            st.pop();

        ans[i] = st.top();
        st.push(i);
    }

    return ans;
}

vector<int> prev(vector<int>& arr, int n) {
    stack<int> st;
    st.push(-1);
    vector<int> ans(n);

    for (int i = 0; i < n; i++) {
        while (st.top() != -1 && arr[st.top()] >= arr[i])
            st.pop();

        ans[i] = st.top();
        st.push(i);
    }

    return ans;
}

int largestRectangleArea(vector<int>& arr) {
    int n = arr.size();
    vector<int> nx = next(arr, n);
    vector<int> pr = prev(arr, n);

    int res = INT_MIN;

    for (int i = 0; i < n; i++) {
        if (nx[i] == -1) nx[i] = n;
        int b = nx[i] - pr[i] - 1;

        res = max(res, arr[i] * b);
    }
    return res;
}

int main() {
    // 1. Next Smaller Element
    // https://www.naukri.com/code360/problems/next-smaller-element_1112581

    // 2. Largest Rectangle in Histogram
    // https://leetcode.com/problems/largest-rectangle-in-histogram/description

    vector<int> arr = {2, 1, 5, 6, 2, 3};
    cout << largestRectangleArea(arr) << endl;
}
