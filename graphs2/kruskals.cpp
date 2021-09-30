#include <bits/stdc++.h>

using namespace std;

//making edge class to store properties related to an edge
class Edge {
    public:
        int source;
        int dest;
        int weight;
};

//compare function for inbuilt sort function
bool compare(Edge e1, Edge e2) {
    return e1.weight < e2.weight;
}


int findParent(int e, int *parent) {
    if(parent[e] == e) {
        return e;
    }
    return findParent(parent[e], parent);
}

void kruskals(Edge *input, int nodes, int edgeCount) {
    sort(input, input + edgeCount, compare);

    Edge *output = new Edge[nodes - 1];
    int *parent = new int[nodes];
    for(int i = 0; i < nodes; i++) {
        parent[i] = i;
    }

    int count = 0;
    int i = 0;

    while(count != nodes - 1) {
        Edge currentEdge = input[i];

        int sourceParent = findParent(currentEdge.source, parent);
        int destParent = findParent(currentEdge.dest, parent);

        if(sourceParent != destParent) {
            output[count++] = currentEdge;
            parent[sourceParent] = destParent;
        }
        i++;
    }

    for(int i = 0; i < nodes - 1; i++) {
        if(output[i].source < output[i].dest) {
            cout << output[i].source << " " << output[i].dest << " " << output[i].weight << endl;
        } else {
            cout << output[i].dest << " " << output[i].source << " " << output[i].weight << endl;
        }
    }
}

int main() {
    int nodes, edgeCount;
    cin >> nodes >> edgeCount;

    Edge *input = new Edge[nodes];
    for(int i = 0; i < edgeCount; i++) {
        int source, dest, weight;
        cin >> source >> dest >> weight;

        input[i].source = source;
        input[i].dest = dest;
        input[i].weight = weight;
    }

    kruskals(input, nodes, edgeCount);

    return 0;
}

// 7 8 0 1 2 1 4 8 0 5 3 5 4 4 4 2 6 4 3 3 6 3 7 6 5 1