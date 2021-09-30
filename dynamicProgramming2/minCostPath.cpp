#include <bits/stdc++.h>

using namespace std;

//recursive approach TC : 3^n
int minCostPath(int **arr, int n, int m, int i, int j) {

    //if current cell is the last cell in the matrix
    //so to go from the last cell to the last cell will cost the cell value
    //in the original array itself
    if(i == n - 1 && j == m - 1) {
        return arr[i][j];
    }

    //if current cell is out of the matrix
    if(i >= n || j >= m) {
        return INT_MAX;
    }

    //Calculation for all three ways
    int option1 = minCostPath(arr, n, m, i + 1, j);
    int option2 = minCostPath(arr, n, m, i, j + 1);
    int option3 = minCostPath(arr, n, m, i + 1, j + 1);

    //returning the minimum cost of all three + the initial array starting value
    return min(option1, min(option2, option3)) + arr[i][j];
}

//Memoisation
int minCostPathMemo(int **arr, int n, int m, int i, int j, int **output) {
    //same as above
    if(i == n - 1 && j == m - 1) {
        return arr[i][j];
    }
    if(i >= n || j >= m) {
        return INT_MAX;
    }
    //memoisation check : whether the value is already present or not(ie. already calculated or not)
    if(output[i][j] != INT_MAX) {
        return output[i][j];
    }
    //same as above
    int option1 = minCostPath(arr, n, m, i + 1, j);
    int option2 = minCostPath(arr, n, m, i, j + 1);
    int option3 = minCostPath(arr, n, m, i + 1, j + 1);

    //storing result for memoisation
    output[i][j] = min(option1, min(option2, option3)) + arr[i][j];
    return output[i][j];
}

//DP solution
int minCostPathDP(int **arr, int n, int m) {
    //creating n*m size matrix for dp calculations
    int **output = new int*[n];
    for(int i = 0; i < n; i++) {
        output[i] = new int[m];
    }

    //Cost for the last cell is the original array cell value
    output[n - 1][m - 1] = arr[n - 1][m - 1];

    //Calculating for the last column (bottom to top)
    //last column value will be the original array value and the value below to take it to end cell
    for(int i = n - 2; i >= 0; i--) {
        output[i][m - 1] = output[i + 1][m - 1] + arr[i][m -1]; 
    }

    //Calculating for the last row(right to left)
    //last row value will the original array cell value + the value just after that cell
    for(int i = m - 2; i >= 0; i--) {
        output[n - 1][i] = output[n - 1][i + 1] + arr[n - 1][i];
    }

    //filling rest of the cells
    //taking minimum path from the adjacent cells and adding it to the original array cell value
    //can be done in any direction ie. right to left or bottom to top order
    for(int i = n - 2; i >= 0; i--){
        for(int j = m - 2; j >= 0; j--) {
            output[i][j] = arr[i][j] + min(output[i + 1][j], min(output[i + 1][j + 1], output[i][j + 1]));
        }
    }
    return output[0][0];
}

int main() {
    //taking dimensions
    int n, m;
    cin >> n >> m;
    
    //initilizing the array with given values
    int **arr = new int*[n];
    for(int i = 0; i < n; i++) {
        arr[i] = new int[m];
        for(int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    //creating another 2D array of same dimensions as original for use in memoisation
    int **output = new int*[n];
    for(int i = 0; i < n; i++)  {
        output[i] = new int[m];
        for(int j = 0; j < m; j++) {
            output[i][j] = INT_MAX;
        }
    }
    //printing results
    int result = minCostPath(arr, n, m, 0, 0);
    cout << "recursive : " << result << endl;

    cout << "memoisation : " << minCostPathMemo(arr, n, m, 0, 0, output) << endl;

    cout << "DP : " << minCostPathDP(arr, n, m);
    return 0;
}