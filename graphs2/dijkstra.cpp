#include <bits/stdc++.h>

using namespace std;

int findMinVertex(int *distance, bool *visited, int nodes) {
    int minVertex = -1;
    for(int i = 0; i < nodes; i++) {
        if(!visited[i] && (minVertex == -1 || distance[i] < distance[minVertex])) {
            minVertex = i;
        }
    }
    return minVertex;
}

void dijkstra(int **edges, int nodes) {
    int *distance = new int[nodes];
    bool *visited = new bool[nodes];

    for(int i = 0; i < nodes; i++) {
        distance[i] = INT_MAX;
        visited[i] = false;
    }

    distance[0] = 0;
    for(int i = 0; i < nodes - 1; i++) {
        int minVertex = findMinVertex(distance, visited, nodes);
        visited[minVertex] = true;
        for(int j = 0; j < nodes; j++) {
            if(edges[minVertex][j] != 0 && !visited[j]) {
                int dist = distance[minVertex] + edges[minVertex][j];
                if(dist < distance[j]) {
                    distance[j] = dist;
                }
            }
        }
    }
    for(int i = 0; i < nodes; i++) {
        cout << i << " " << distance[i] << endl;
    }
    delete [] visited;
    delete [] distance;
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
    
    dijkstra(edges, nodes);
    
    return 0;
}

//7 8 0 1 2 1 4 8 0 5 3 5 4 4 4 2 6 4 3 3 6 3 7 6 5 1