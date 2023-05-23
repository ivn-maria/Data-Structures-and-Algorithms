#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
using namespace std;

struct Edge {
    int from;
    int to;
    long long effort;
    long long profit;
    int idx;
};

struct EdgeComparator {
    bool operator()(const Edge &first, const Edge &second) const {
        if (first.effort == second.effort) return first.profit < second.profit;
        return first.effort > second.effort;
    }
};

void prim(vector<vector<Edge>> &graph, int startNode, set<int> &spanningTreeNodes, vector<Edge> &mst) {
    spanningTreeNodes.insert(startNode);
    priority_queue<Edge, vector<Edge>, EdgeComparator> pq;

    for (auto const &edge : graph[startNode])
        pq.push(edge);

    while (!pq.empty()) {
        Edge currentEdge = pq.top();
        pq.pop();

        int otherNode = spanningTreeNodes.count(currentEdge.from) ? currentEdge.to : currentEdge.from;
        if (!spanningTreeNodes.count(otherNode)) {
            mst.push_back(currentEdge);
            spanningTreeNodes.insert(otherNode);

            for (auto const &edge : graph[otherNode])
                pq.push(edge);
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<Edge>> edges(N + 1);
    for (int i = 0; i < M; ++i) {
        int a, b;
        long long c1, c2;
        cin >> a >> b >> c1 >> c2;

        edges[a].push_back({a, b, c1, c2, i + 1});
        edges[b].push_back({a, b, c1, c2, i + 1});
    }

    vector<Edge> mstEdges;
    vector<vector<Edge>> msf;
    set<int> spanningTreeNodes;
    for (int i = 0; i < N; ++i) {
        if (!spanningTreeNodes.count(i)) {
            prim(edges, i, spanningTreeNodes, mstEdges);
            msf.emplace_back(mstEdges.begin(), mstEdges.end());
            mstEdges.clear();
        }
    }

    for (auto const &mst : msf)
        for (auto const &edge: mst)
            cout << edge.idx << '\n';

    return 0;
}