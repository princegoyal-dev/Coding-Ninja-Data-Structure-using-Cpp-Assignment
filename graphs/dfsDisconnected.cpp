#include <bits/stdc++.h>

using namespace std;

void printDFS(int **edges, int nodes, int sv, bool *visited) {
    cout << sv << endl;
    visited[sv] = true;
    for(int i = 0 ; i < nodes; i++) {
        if(edges[sv][i] == 1 && !visited[i] && !(i == sv)) {
            printDFS(edges, nodes, i, visited);
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

    int component = 1;
    for(int i = 0; i < nodes; i++) {
        if(!visited[i]) {
            cout << component++ << " : " << endl;
            printDFS(edges, nodes, i, visited);
        }
    }

    return 0;

}

//disconnected input
// 8 6 0 4 0 1 1 3 4 3 3 2 5 7