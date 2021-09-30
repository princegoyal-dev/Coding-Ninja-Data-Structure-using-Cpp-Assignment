#include <bits/stdc++.h>

using namespace std;

bool outside(int i, int j, int rows, int cols) {
    if(i < 0 || i >= rows || j < 0 || j >= cols) {
        return true;
    } else return false;
}

bool connectingDotsHelper(char **matrix, int rows, int cols, int i, int j, bool **visited, int initialIndexRow, int initialIndexCol, int currCount) {

    int x[] = {-1, 0, 0, 1};
    int y[] = {0, -1, 1, 0};
    cout << "helper fun : " << matrix[i][j] << endl;
    if(currCount >= 4) {
        cout << "count >= 4" << endl;
        for(int dir = 0; dir < 4; dir++) {
            if(initialIndexRow == i - x[dir] && initialIndexCol == j - y[dir]) {
                return true;
            }
        }
    }
    bool result = false;
    visited[i][j] = true;
    for(int dir = 0; dir < 4; dir++) {
        if(!outside(i + x[dir], j + y[dir], rows, cols) && !visited[i + x[dir]][j + y[dir]]) {
            if(matrix[i + x[dir]][j + y[dir]] == matrix[i][j]) {
                result = connectingDotsHelper(matrix, rows, cols, i + x[dir], j + y[dir], visited, initialIndexRow, initialIndexCol, currCount + 1);
            }
            if(result == true) {
                break;
            }
        }
    }
    return result;
}

bool connectingDots(char **matrix, int rows, int cols) {

    bool **visited = new bool*[rows];
    for(int i = 0; i < rows; i++) {
        visited[i] = new bool[cols];
        for(int j = 0; j < cols; j++) {
            visited[i][j] = false;
        }
    }

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            cout << "current char : " << matrix[i][j] << endl;
            if(connectingDotsHelper(matrix, rows, cols, i, j, visited, i, j, 1)) {
                return true;
            }
            for(int m = 0; m < rows; m++) {
                for(int n = 0; n < cols; n++) {
                    visited[m][n] = false;
                }
            }
        }
    }
    return false;
}

int main() {
    int rows, cols;
    cin >> rows >> cols;

    char **matrix = new char*[rows];
    for(int i = 0; i < rows; i++) {
        matrix[i] = new char[cols];
        for(int j = 0; j < cols; j++) {
            char ch;
            cin >> ch;
            matrix[i][j] = ch;
        }
    }

    bool result = connectingDots(matrix, rows, cols);
    cout << boolalpha << result;
    return 0;
}