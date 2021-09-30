#include <bits/stdc++.h>

using namespace std;

void print(int **edges, int nodes, int sv, bool *visited) {
    cout << sv << endl;
    visited[sv] = true;
    for(int i = 0; i < nodes; i++) {
        if(i == sv) {
            continue;
        }
        if(edges[sv][i] == 1) {
            if(visited[i]) {
                continue;
            }
            print(edges, nodes, i, visited);
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

    print(edges, nodes, 0, visited);
    return 0;
}