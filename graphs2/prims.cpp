#include <bits/stdc++.h>

using namespace std;

int findMinVertex(int *weight, bool *visited, int nodes) {
    int minVertex = -1;
    for(int i = 0; i < nodes; i++) {
        if(!visited[i] && (minVertex == -1 || weight[i] < weight[minVertex])) {
            minVertex = i;
        }
    }
    return minVertex;
}

void prims(int **edges, int nodes) {
    int *parent = new int[nodes];
    int *weight = new int[nodes];
    bool *visited = new bool[nodes];

    for(int i = 0; i < nodes; i++) {
        visited[i] = false;
        weight[i] = INT_MAX;
    }
    
    parent[0] = -1;
    weight[0] = 0;

    for(int i = 0; i < nodes - 1; i++) {
        int minVertex = findMinVertex(weight, visited, nodes);
        visited[minVertex] = true;
        for(int j = 0; j < nodes; j++) {
            if(edges[minVertex][j] != 0 && !visited[j]) {
                if(edges[minVertex][j] < weight[j]) {
                    weight[j] = edges[minVertex][j];
                    parent[j] = minVertex;
                }
            }
        }
    }
    for(int i = 1; i < nodes; i++) {
        if(parent[i] < i) {
            cout << parent[i] << " " << i << " " << weight[i] << endl;
        } else {
            cout << i << " " << parent[i] << " " << weight[i] << endl;
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
        int p1, p2, w;
        cin >> p1 >> p2 >> w;

        edges[p1][p2] = w;
        edges[p2][p1] = w;
    }
    
    prims(edges, nodes);

    return 0;
}