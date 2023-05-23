#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

struct Edge {
    int from;
    int to;
    int weight;

    bool operator<(const Edge &edge) const {
        return this->weight < edge.weight;
    }
};

int findRoot(int node, vector<int> &parents) {
    if (parents[node] == node)
        return node;

    parents[node] = findRoot(parents[node], parents);
    return parents[node];
}

void kruskal(vector<Edge> &edges, int nodesCount, vector<Edge> &mstEdges) {
    sort(edges.begin(), edges.end());

    vector<int> parents(nodesCount);
    for (int i = 0; i < parents.size(); ++i)
        parents[i] = i;

    for (auto const &edge : edges) {
        int fromRoot = findRoot(edge.from, parents);
        int toRoot = findRoot(edge.to, parents);
        if (fromRoot != toRoot) {
            mstEdges.push_back(edge);
            parents[fromRoot] = toRoot;
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<Edge> graph;

    for (int i = 0; i < M; i++) {
        int from, to, speed;
        cin >> from >> to >> speed;

        graph.push_back({from, to, speed});
    }

    int count = M;
    int minDiff = INT_MAX;
    int minAns, maxAns;
    while (count >= N - 1) {
        vector<Edge> mstEdges;
        kruskal(graph, M, mstEdges);

        int min = INT_MAX, max = INT_MIN;
        for (auto const &edge : mstEdges) {
            if (edge.weight < min) min = edge.weight;
            if (edge.weight > max) max = edge.weight;
        }

        int diff = max - min;
        if (diff < minDiff) {
            minDiff = diff;
            minAns = min;
            maxAns = max;
        }

        graph.begin()->weight = INT_MAX;

        count--;
    }

    cout << minAns << ' ' << maxAns;

    return 0;
}