#include <bits/stdc++.h>
using namespace std;

int celebrity(vector<vector<int>>& mat) {
    int n = mat.size();
    stack<int> st;

    for (int i = 0; i < n; i++)
        st.push(i);

    while (st.size() > 1) {
        int a = st.top();
        st.pop();
        int b = st.top();
        st.pop();

        if (mat[a][b])
            st.push(b);
        else
            st.push(a);
    }

    int num = st.top();
    bool isCeleb = true;

    for (int i = 0; i < n; i++) {
        if (i == num) continue;

        if (!mat[i][num] || mat[num][i]) isCeleb = false;
    }

    if (isCeleb)
        return num;
    else
        return -1;
}

int largestRectangleArea(vector<int>& arr) {
    stack<int> st1, st2;
    st1.push(-1);
    st2.push(-1);
    int n = arr.size();

    vector<int> nx(n), pr(n);

    for (int i = n - 1; i >= 0; i--) {
        while (st1.top() != -1 && arr[st1.top()] >= arr[i])
            st1.pop();

        nx[i] = st1.top();
        st1.push(i);
    }

    for (int i = 0; i < n; i++) {
        while (st2.top() != -1 && arr[st2.top()] >= arr[i])
            st2.pop();

        pr[i] = st2.top();
        st2.push(i);
    }

    int ans = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (nx[i] == -1) nx[i] = n;
        int b = nx[i] - pr[i] - 1;

        ans = max(ans, arr[i] * b);
    }

    return ans;
}

int maxArea(vector<vector<int>>& mat) {
    int area = largestRectangleArea(mat[0]);
    int n = mat.size(), m = mat[0].size();
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j]) mat[i][j] += mat[i - 1][j];
        }

        area = max(area, largestRectangleArea(mat[i]));
    }
    return area;
}

int main() {
    // 1. https://www.geeksforgeeks.org/problems/the-celebrity-problem/1

    // 2. https://www.geeksforgeeks.org/problems/max-rectangle/1
}
