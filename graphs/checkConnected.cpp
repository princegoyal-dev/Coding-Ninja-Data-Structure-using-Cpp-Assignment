#include <bits/stdc++.h>

using namespace std;

bool isConnected(int **edges, int nodes, int sv, bool *visited) {
    visited[sv] = true;
    for(int i = 0; i < nodes; i++) {
        if(sv == i) {
            continue;
        }
        if(edges[sv][i] == 1 && !visited[i]) {
            isConnected(edges, nodes, i, visited);
        }
    }
}

int main() {
    int nodes, edgeCount;
    cin >> nodes >> edgeCount;

    int **edges = new int*[nodes];
    for(int i = 0; i < nodes; i++) {
        edges[i] = new int[nodes];
        for(int j = 0; j < nodes; j++) {
            edges[i][j] = 0;
        }
    }

    for(int i = 0; i < edgeCount; i++) {
        int p1, p2;
        cin >> p1 >> p2;
        edges[p1][p2] = 1;
        edges[p2][p1] = 1;
    }

    bool *visited = new bool[nodes];
    for(int i = 0; i < nodes; i++) {
        visited[i] = false;
    }

    bool result = isConnected(edges, nodes, 0, visited);
    for(int i = 0; i < nodes; i++) {
        if(!visited[i]) {
            cout << "False";
            return 0;
        }
    }
    cout << "True";
    return 0;
}

// 8 6 0 4 0 1 1 3 4 3 3 2 5 7
// 11 11 0 1 1 4 4 5 5 0 4 2 4 3 3 6 5 6 7 8 8 9 7 10