//starting from a vertex (given as a n*m matrix) check whether the word exits if we can go in any 
//direction

#include <bits/stdc++.h>

using namespace std;

bool outside(int i, int j, int rows, int cols) {
    if(i < 0 || i >= rows || j < 0 || j >= cols) {
        return true;
    } else return false;
}

bool findWordHelper(char **matrix, int i, int j, string str, int rows, int cols, bool **visited) {
    // cout << "in findWordHelper fun" << endl;
    if(str.size() == 1) {
        if(str[0] == matrix[i][j]) {
            return true;
        } else return false;
    }
    int x[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int y[] = {-1, 0, 1, -1, 1, -1, 0, 1};
    
    // cout << "findWordhelper : " << matrix[i][j] << endl;
    visited[i][j] = true;

    bool result = false;

    for(int dir = 0; dir < 8; dir++) {
        // cout << "dir : " << dir << endl;
        if(!outside(i + x[dir], j + y[dir], rows, cols) && !visited[i + x[dir]][j + y[dir]]) {
            if(matrix[i + x[dir]][j + y[dir]] == str[1]) {
                result = findWordHelper(matrix, i + x[dir], j + y[dir], str.substr(1), rows, cols, visited);
            }
            if(result == true) {
                break;
            }
        }
    }
    return result;
}

bool findWord(char **matrix, string str, int rows, int cols) {

    bool **visited = new bool*[rows];
    for(int i = 0; i < rows; i++) {
        visited[i] = new bool[cols];
        for(int j = 0; j < cols; j++) {
            visited[i][j] = false;
        }
    }

    // cout << "In findWord fun" << endl;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            // cout << "current char : " << matrix[i][j] << endl;
            if(matrix[i][j] == str[0]) {
                if(findWordHelper(matrix, i, j, str, rows, cols, visited)) {
                    return true;
                }
                for(int m = 0; m < rows; m++) {
                    for(int n = 0; n < cols; n++) {
                        visited[i][j] = false;
                    }
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

    string str;
    cin >> str;
    bool result = findWord(matrix, str, rows, cols);
    cout << boolalpha << result;
    return 0;
}

/*
5 6
a b c d e p
a l m n r o
b c y i n m
g b a l c l
d e a b m e
*/