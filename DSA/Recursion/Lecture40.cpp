#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isSafe(vector<vector<int>>& m, int n, int x, int y, vector<vector<int>>& visited) {
    if (x < 0 || y < 0 || x >= n || y >= n || visited[x][y] == 1 || m[x][y] == 0) {
        return false;
    } else return true;
}

void solve(vector<vector<int>> &m, int n, vector<string>& ans, int x, int y, vector<vector<int>>& visited, string path) {
    // Base Case
    if (x == n - 1 && y == n - 1) {
        ans.push_back(path);
        return;
    }

    // Since we reached (x, y), we have to mark it as visited
    visited[x][y] = 1;
    
    // Down movement
    int newX = x + 1;
    int newY = y;

    if (isSafe(m, n, newX, newY, visited)) {
        path.push_back('D');
        solve(m, n, ans, newX, newY, visited, path);
        path.pop_back();
    }

    // Up movement
    newX = x - 1;
    newY = y;

    if (isSafe(m, n, newX, newY, visited)) {
        path.push_back('U');
        solve(m, n, ans, newX, newY, visited, path);
        path.pop_back();
    }

    // Left movement
    newX = x;
    newY = y - 1;

    if (isSafe(m, n, newX, newY, visited)) {
        path.push_back('L');
        solve(m, n, ans, newX, newY, visited, path);
        path.pop_back();
    }

    // Right movement
    newX = x;
    newY = y + 1;

    if (isSafe(m, n, newX, newY, visited)) {
        path.push_back('R');
        solve(m, n, ans, newX, newY, visited, path);
        path.pop_back();
    }

    // We will reach here when the recursive calls have ended
    // This needs to be set back to 0 as the function will try a different path
    visited[x][y] = 0;
}

vector<string> findPath(vector<vector<int>> &m, int n) {
    vector<string> ans;

    // If source is marked as 0, return []
    if (m[0][0] == 0) return ans;

    // Source coordinates
    int srcx = 0;
    int srcy = 0;
    
    // Visited n x n matrix (initialized with 0)
    vector<vector<int>> visited(n, vector<int>(n, 0));

    string path = "";
    solve(m, n, ans, srcx, srcy, visited, path);
    
    // Sort it lexicographically (dictonary alphabetical order)
    sort(ans.begin(), ans.end());
    
    return ans;
}

int main() {
    // Rat In A Maze
    // https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

    vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };

    int n = maze.size();

    vector<string> ans = findPath(maze, n);

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << endl;
    }
}