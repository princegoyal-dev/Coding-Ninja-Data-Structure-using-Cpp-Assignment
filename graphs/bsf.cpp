#include <bits/stdc++.h>

using namespace std;

void printBSF(int **edges, int nodes, int sv, bool *visited) {
    queue<int> pendingVertex;
    pendingVertex.push(sv);
    visited[sv] = true;

    while(pendingVertex.size() != 0) {
        int currentVertex = pendingVertex.front();
        pendingVertex.pop();
        
        cout << currentVertex << endl;
        for(int i = 0; i < nodes; i++) {
            if(i == currentVertex) {
                continue;
            }
            if(edges[currentVertex][i] == 1 && !visited[i]) {
                pendingVertex.push(i);
                visited[i] = true;
            }
        }
    }
    delete [] visited;
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

    printBSF(edges, nodes, 0, visited); 

    return 0;
}