#include <bits/stdc++.h>
using namespace std;

// Using recursion (can be solved using stack too)
void solve(queue<int>& q) {
    if (q.empty()) return;

    int val = q.front();
    q.pop();

    solve(q);

    q.push(val);
}

queue<int> queueReversal(queue<int>& q) {
    solve(q);
    return q;
}

vector<int> firstNegInt(vector<int>& arr, int k) {
    int n = arr.size();
    deque<int> dq;
    vector<int> ans;

    // first k set
    for (int i = 0; i < k; i++) {
        if (arr[i] < 0) dq.push_back(i);
    }

    if (!dq.empty())
        ans.push_back(arr[dq.front()]);
    else
        ans.push_back(0);

    for (int i = k; i < n; i++) {
        if (!dq.empty() && i - dq.front() >= k) dq.pop_front();

        if (arr[i] < 0) dq.push_back(i);

        if (!dq.empty())
            ans.push_back(arr[dq.front()]);
        else
            ans.push_back(0);
    }

    return ans;
}

string firstNoneRepeatingChar(string& s) {
    vector<int> freq(26, 0);
    queue<char> q;
    string res;

    for (int i = 0; i < s.size(); i++) {
        freq[s[i] - 'a']++;
        q.push(s[i]);

        while (!q.empty()) {
            if (freq[q.front() - 'a'] > 1) // repeating char
                q.pop();
            else { // non repeating char
                res += q.front();
                break;
            }
        }

        if (q.empty()) res += '#';
    }

    return res;
}

int startStation(vector<int>& gas, vector<int>& cost) {
    int n = gas.size();
    int balance = 0, front = 0, deficit = 0;

    for (int i = 0; i < n; i++) {
        balance += gas[i] - cost[i];

        if (balance < 0) {
            deficit += balance;
            front = i + 1;
            balance = 0;
        }
    }

    if (deficit + balance >= 0)
        return front;
    else
        return -1;
}

queue<int> rearrangeQueue(queue<int> q) {
    stack<int> st;
    int n = q.size();

    // 11 12 13 14 | 15 16 17 18

    for (int i = 0; i < n / 2; i++) {
        st.push(q.front());
        q.pop();
    }

    // 15 16 17 18
    // stack(top) -> 14 13 12 11

    while (!st.empty()) {
        q.push(st.top());
        st.pop();
    }

    // 15 16 17 18 | 14 13 12 11

    // put elements to back
    for (int i = 0; i < n / 2; i++) {
        int val = q.front();
        q.pop();
        q.push(val);
    }

    // 14 13 12 11 | 15 16 17 18

    for (int i = 0; i < n / 2; i++) {
        st.push(q.front());
        q.pop();
    }

    // 15 16 17 18
    // stack(top) -> 11 12 13 14

    while (!st.empty()) {
        q.push(st.top());
        st.pop();
        int val = q.front();
        q.pop();
        q.push(val);
    }

    // 1st Iteration
    // 15 16 17 18 | 11
    // 16 17 18 | 11
    // 16 17 18 | 11 15

    return q; // 11 15 12 16 13 17 14 18
}

class KQueue {
    int *arr, *front, *rear, *next;
    int n, k, freespot;

  public:
    KQueue(int N, int K) {
        n = N;
        k = K;
        arr = new int[n];
        front = new int[k];
        rear = new int[k];
        next = new int[n];

        for (int i = 0; i < k; i++) {
            front[i] = -1;
            rear[i] = -1;
        }

        for (int i = 0; i < n - 1; i++)
            next[i] = i + 1;
        next[n - 1] = -1;

        freespot = 0;
    }

    bool push(int x, int m) {
        if (freespot == -1) return false;

        int index = freespot;
        freespot = next[index];
        arr[index] = x;

        if (front[m - 1] == -1)
            front[m - 1] = index;
        else
            next[rear[m - 1]] = index;

        next[index] = -1;
        rear[m - 1] = index;

        return true;
    }

    int pop(int m) {
        if (front[m - 1] == -1) return -1;

        int index = front[m - 1];
        front[m - 1] = next[index];
        next[index] = freespot; // NOTE: Go back
        freespot = index;       // NOTE: Go back

        return arr[index];
    }
};

int sumOfMaxAndMin(vector<int>& arr, int n, int k) {
    deque<int> maxi(k), mini(k); // 1 2 3 4 5

    // Addition for first set of K length
    for (int i = 0; i < k; i++) { // Tracks all maximum and minimum of "i"th index
        while (!maxi.empty() && arr[maxi.back()] <= arr[i])
            maxi.pop_back();
        while (!mini.empty() && arr[mini.back()] >= arr[i])
            mini.pop_back();

        maxi.push_back(i);
        mini.push_back(i);
    }

    int ans = arr[maxi.front()] + arr[mini.front()];

    for (int i = k; i < n; i++) { // Checks each number for addition/subtraction
        // Removes max & min if they have gone out of set
        while (!maxi.empty() && i - maxi.front() >= k)
            maxi.pop_front();
        while (!mini.empty() && i - mini.front() >= k)
            mini.pop_front();

        // Addition for the "i"th element
        while (!maxi.empty() && arr[maxi.back()] <= arr[i])
            maxi.pop_back();
        while (!mini.empty() && arr[mini.back()] <= arr[i])
            mini.pop_back();

        maxi.push_back(i);
        mini.push_back(i);

        ans += arr[maxi.front()] + arr[mini.front()];
    }

    return ans;
}

int main() {
    // 1. Queue Reversal
    // https://www.geeksforgeeks.org/problems/queue-reversal/1

    // 2. First negative in every K size window
    // https://www.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1

    // 3. Reverse first k element of queue
    // https://www.geeksforgeeks.org/problems/reverse-first-k-elements-of-queue/1

    // 4. First non repeating char in a string
    // https://www.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1
    string str = "aabc";
    cout << firstNoneRepeatingChar(str) << endl;

    // 5. Circular Tour
    // https://www.geeksforgeeks.org/problems/circular-tour-1587115620/1

    // 6. Interleaf First & Second Half of Queue
    // https://www.geeksforgeeks.org/problems/interleave-the-first-half-of-the-queue-with-second-half/1

    // 7. K Queues in an Array
    // https://www.naukri.com/code360/problems/n-queue-using-array_1170053

    // 8. Sum of Max & Min of Subarray of length K
    // https://www.naukri.com/code360/problems/sum-of-minimum-and-maximum-elements-of-all-subarrays-of-size-k_1171047
}
