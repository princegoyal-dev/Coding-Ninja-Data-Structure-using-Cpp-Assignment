#include <bits/stdc++.h>

using namespace std;

string getPathBSF(int **edges, int nodes, int sv, bool *visited, int p2) {
    
    queue<int> pendingVertex;
    pendingVertex.push(sv);
    visited[sv] = true;

    unordered_map<int, int> myMap;

    string result = "";

    while(pendingVertex.size() != 0) {

        unordered_map<int, int>::iterator it;
        it = myMap.begin();
        // cout << "new iteration" << endl;
        while(it != myMap.end()) {
            // cout << "it.first : " << it -> first << " it.second : " << it -> second << endl;
            it++;
        }

        int frontVertex = pendingVertex.front();
        pendingVertex.pop();

        if(frontVertex == p2) {
            if(!myMap.empty()) {
                int vertex = myMap[p2];
                result += to_string(p2) + " ";
                while(vertex != sv) {
                    result += to_string(vertex) + " ";
                    vertex = myMap[vertex];
                }
            }
            result += to_string(sv);
            return result;
        }

        if(edges[frontVertex][p2] == 1) {
            if(!myMap.empty()) {
                myMap[p2] = frontVertex;
                int vertex = myMap[p2];
                result += to_string(p2) + " ";
                while(vertex != sv) {
                    result += to_string(vertex) + " ";
                    vertex = myMap[vertex];
                }
                result += to_string(sv);
                return result;
            }
            result += to_string(frontVertex) + " " + to_string(p2);
            return result;
        }

        for(int i = 0; i < nodes; i++) {
            if(frontVertex == i) {
                continue;
            }
            if(edges[frontVertex][i] == 1 && !visited[i]) {
                pendingVertex.push(i);
                visited[i] = true;
                myMap[i] = frontVertex;
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

    string resultPath = getPathBSF(edges, nodes, p1, visited, p2);

    cout << resultPath;

    return 0;
}


// 8 6 0 4 0 1 1 3 4 3 3 2 5 7
// 11 11 0 1 1 4 4 5 5 0 4 2 4 3 3 6 5 6 7 8 8 9 7 10