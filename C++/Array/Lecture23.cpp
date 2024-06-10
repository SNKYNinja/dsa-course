#include <iostream>
#include <vector>
using namespace std;

bool linearSearch(int arr[][4], int target, int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (arr[i][j] == target)
            {
                return 1;
            }
        }
    }

    return 0;
}

void printMatrix(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {

            cout << matrix[i][j] << " ";
        }

        cout << endl;
    }
}

void printRowSum(int arr[][4], int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        int sum = 0;
        for (int j = 0; j < c; j++)
        {
            sum += arr[i][j];
        }
        cout << i + 1 << " Row Sum: " << sum << endl;
    }
}

vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    vector<int> ans;
    int row = matrix.size();
    int col = matrix[0].size();

    // This count will be used to run the loop until all numbers are accounted for
    int count = 0;
    int total = row * col;

    int startRow = 0;
    int endRow = row - 1;
    int startCol = 0;
    int endCol = col - 1;

    while (count < total)
    {
        // Starting row
        for (int i = startCol; i < endCol; i++)
        {
            ans.push_back(matrix[startRow][i]);
            count++;
        }
        startRow++;

        // Ending column
        for (int i = startRow; i < endRow; i++)
        {
            ans.push_back(matrix[i][endCol]);
            count++;
        }
        endCol--;

        // Ending row
        for (int i = endCol; i >= startCol; i--)
        {
            ans.push_back(matrix[endRow][i]);
            count++;
        }
        endRow--;

        // Starting column
        for (int i = endRow; i >= startRow; i--)
        {
            ans.push_back(matrix[i][startCol]);
            count++;
        }
        startCol++;
    }

    return ans;
}

void rotateMatrix(vector<vector<int>> &matrix)
{
    int n = matrix.size(); // n x n matrix

    // Take transpose of the matrix (Row <--> Column)
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // Reverse each row
    for (int i = 0; i < n; i++)
    {
        int s = 0;
        int e = n - 1;
        while (s < e)
        {
            swap(matrix[i][s++], matrix[i][e--]);
        }
    }
}

bool binarySearch(vector<vector<int>> &matrix, int target)
{
    // For a linearly ordered matrix

    // 2D Matrix
    // 1 3 5 7
    // 10 11 16 20
    // 23 30 34 60

    // In memory
    // 1 3 5 7 10 11 16 20 23 30 34 60

    // row = 3; col = 4

    int row = matrix.size();
    int col = matrix[0].size();

    int s = 0;
    int e = row * col - 1;

    // We need to find the corresponding indexes to access the element in matrix
    int mid = s + (e - s) / 2;

    // row -> mid / col
    // col -> mid % col

    while (s <= e)
    {
        int element = matrix[mid / col][mid % col];
        if (element == target)
            return 1;
        else if (element > target)
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }
}

bool binarySearch2(vector<vector<int>> &matrix, int target)
{
    int row = matrix.size();
    int col = matrix[0].size();

    int rowIndex = 0;
    int colIndex = col - 1;

    while (rowIndex < row && colIndex >= 0)
    {
        int element = matrix[rowIndex][colIndex];
        if (element == target)
            return 1;
        else if (element < target)
        {
            rowIndex++;
        }
        else
        {
            colIndex--;
        }
    }

    return 0;
}

int main()
{
    // 2D Array -> 3x3 (Matrix)
    // First [3] -> Row
    // Second [3] -> Column
    // int arr[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int arr[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};

    // for (int i = 0; i < 3; i++)
    // {
    //     for (int j = 0; j < 4; j++)
    //     {
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // int r = 4;
    // int c = 5;

    // Number of elements in row = Number of columns
    // Number of elements in column = Number of rows

    // This creates a 1D vector with all elements being 0
    // vector<int> row(c, 0); // 0 0 0 0 0

    // This creates "r" number of "row" that we created above to fill the matrix
    // vector<vector<int>> matrix(r, row);
    // 0 0 0 0 0
    // 0 0 0 0 0
    // 0 0 0 0 0
    // 0 0 0 0 0

    // Linear Search
    // cout << "Enter number to search: " << endl;
    // int target;
    // cin >> target;

    // if (linearSearch(arr, target, 3, 4))
    // {
    //     cout << "Element found in array!" << endl;
    // }
    // else
    // {
    //     cout << "Element not found in array!" << endl;
    // }

    // Binary Search
    cout << "Enter number to search in the matrix: " << endl;
    int target;
    cin >> target;

    // Questions

    // 1. Wave Print
    // https://www.naukri.com/code360/problems/print-like-a-wave_893268

    // 2. Spiral Print
    // https://leetcode.com/problems/spiral-matrix/

    // 3. Rotate Image
    // https://leetcode.com/problems/rotate-image/description/
    // Solution: rotateMatrix() -> Line 104

    // 4. Search a 2D Matrix - I
    // https://leetcode.com/problems/search-a-2d-matrix/description/
    // Solution: binarySearch() -> Line 129

    // 5. Search a 2D Matrix - II
    // https://leetcode.com/problems/search-a-2d-matrix-ii/
    // Solution: binarySearch2() -> Line 172

    return 0;
}