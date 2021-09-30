#include <bits/stdc++.h>

using namespace std;

void printBSF(int **edges, int nodes, int sv, bool *visited) {
    queue<int> pendingVertex;
    pendingVertex.push(sv);
    visited[sv] = true;
    while(pendingVertex.size() != 0) {
        int frontVertex = pendingVertex.front();
        pendingVertex.pop();

        cout << frontVertex << endl;
        for(int i = 0; i < nodes; i++) {
            if(frontVertex == i) {
                continue;
            }
            if(edges[frontVertex][i] == 1 && !visited[i]) {
                pendingVertex.push(i);
                visited[i] = true;
            }
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

    for(int i = 0; i < nodes; i++) {
        if(!visited[i]) {
            printBSF(edges, nodes, i, visited);
            cout << endl;
        }
    }
    return 0;
}
//
// 8 6 0 4 0 1 1 3 4 3 3 2 5 7