#include <bits/stdc++.h>

using namespace std;

string getPath(int **edges, int nodes, int sv, bool *visited, int p2) {
    if(sv == p2) {
        return to_string(sv);
    }
    if(edges[sv][p2] == 1) {
        return to_string(sv) + " " + to_string(p2);
    }
    visited[sv] = true;
    string result = "";
    for(int i = 0; i < nodes; i++) {
        if(sv == i) {
            continue;
        }
        if(edges[sv][i] == 1 && !visited[i]) {
            result = getPath(edges, nodes, i, visited, p2);
            if(result != "") {
                break;
            }
        }
    }
    if(result == "") {
        return "";
    }
    return to_string(sv) + " " + result;
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

    string resultPath = getPath(edges, nodes, p1, visited, p2);

    cout << resultPath;
    return 0;
}

//// 8 6 0 4 0 1 1 3 4 3 3 2 5 7
// 5 3 0 1 3 4 2 4