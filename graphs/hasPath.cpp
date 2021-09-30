#include <bits/stdc++.h>

using namespace std;

bool hasPath(int **edges, int nodes, int sv, bool *visited, int p1, int p2) {
    if(p1 == p2) {
        return true;
    }
    if(edges[p1][p2] == 1) {
        return true;
    }
    bool result =  false;
    for(int i = 0; i < nodes; i++) {
        if(i == sv) {
            continue;
        }
        if(edges[sv][i] == 1 && !visited[i]) {
            visited[i] = true;
            result = hasPath(edges, nodes, i, visited, p1, p2);
        }
    }
    return result;
}

int main() {
    int nodes, edgeCount;
    cin >> nodes >> edgeCount;

    int **edges = new int*[nodes];
    for(int i = 0; i < nodes; i++) {
        edges[i] = new int[nodes];
        for(int j = 0; j < nodes; j ++) {
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

    int p1, p2;
    cin >> p1 >> p2;

    bool result = hasPath(edges, nodes, 0, visited, p1, p2);
    cout << boolalpha << result << endl;

    return 0;
}

// 8 6 0 4 0 1 1 3 4 3 3 2 5 7
// 5 3 0 1 3 4 2 4