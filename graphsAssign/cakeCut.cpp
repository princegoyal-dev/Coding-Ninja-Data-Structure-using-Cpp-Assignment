#include <bits/stdc++.h>

using namespace std;

bool outside(int i, int j, int n) {
    if(i < 0 || i >= n || j < 0 || j >= n) {
        return true;
    } else return false;
}

int countLargestHelper(int **cake, int n, int i, int j, bool **visited, int &count) {
    int x[] = {-1, 0, 0, 1};
    int y[] = {0, -1, 1, 0};

    visited[i][j] = true;
    int result = 0;
    for(int dir = 0; dir < 4; dir++) {
        if(!outside(i + x[dir], j + y[dir], n) && !visited[i + x[dir]][j + y[dir]]) {
            if(cake[i + x[dir]][j + y[dir]] == 1) {
                count++;
                result = 1 + countLargestHelper(cake, n, i + x[dir], j + y[dir], visited, count);
            }
        }
    }
    return result;
}

int countLargest(int **cake, int n) {
    
    int largest = 0;
    bool **visited = new bool*[n];
    for(int i = 0; i < n; i++) {
        visited[i] = new bool[n];
        for(int j = 0; j < n; j++) {
            visited[i][j] = false;
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(cake[i][j] == 1) {
                int count = 0;
                // cout << "i : " << i << " j : " << j << " : " << cake[i][j] << endl;
                countLargestHelper(cake, n, i, j, visited, count);
                if(count > largest) {
                    largest = count;
                }
                // cout << "largest : " << largest << endl;
                for(int m = 0; m < n; m++) {
                    for(int k = 0; k < n; k++) {
                        visited[m][k] = false;
                    }
                }
            }
        }
    }
    return largest + 1;
}

int main() {
    int n;
    cin >> n;

    int **cake = new int*[n];
    for(int i = 0; i < n; i++) {
        cake[i] = new int[n];
        for(int j = 0; j < n; j++) {
            int val;
            cin >> val;
            cake[i][j] = val;
        }
    }

    int result = countLargest(cake, n);

    cout << result;

    return 0;
}
/*
5
1 0 1 0 1
1 0 1 1 1
0 1 0 1 1
0 1 0 1 0
1 1 1 1 1
*/