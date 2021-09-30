#include <bits/stdc++.h>

using namespace std;

int countCycleHelper(int **edges, int i, int nodes, int count, int startIndex, bool *visited) {
    // cout << "currNodeHelper : " << i << endl;
    // cout << "count helper : " << count << endl;
    if(count == 3) {
        if(edges[i][startIndex]) {
            return 1;
        }
        else return 0;
    }
    visited[i] = true;
    int result = 0;
    for(int j = 0; j < nodes; j++) {
        if(i == j) {
            continue;
        }
        if(edges[i][j] == 1 && !visited[j]) {
            // cout << "node exites bw " << i << " " << j << endl;
            result += countCycleHelper(edges, j, nodes, count + 1, startIndex, visited);
            visited[j] = false;
        }
    }
    return result;
}

int countCycle(int **edges, int nodes) {
    int result = 0;
    
    bool *visited = new bool[nodes];
    for(int i = 0; i < nodes; i++) {
        visited[i] = false;
    }

    for(int i = 0; i < nodes; i++) {
        // cout << "currNode : " << i << endl;
        int count = 1;
        result += countCycleHelper(edges, i, nodes, count, i, visited);
        // cout << "count : " << count << endl;
        for(int j = 0; j < nodes; j++) {
            visited[j] = false;
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

    int cycle = countCycle(edges, nodes);
    cout << cycle / 6;

    return 0;
}

/*
7 12
0 1
1 2
1 3
0 3
2 3
1 6
2 6
3 4
2 4
2 5
4 5
5 6
*/