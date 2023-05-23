#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <unordered_map>
using namespace std;

struct Edge {
    int to;
    int weight;
};

void dijkstra(vector<vector<Edge>> &graph, vector<int> &distances, int startNode) {
    distances = vector<int>(graph.size(), INT32_MAX);
    distances[startNode] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, startNode});

    while (!pq.empty()) {
        int current = pq.top().second;
        int distanceToCurrent = pq.top().first;
        pq.pop();

        for (auto const &edge : graph[current]) {
            int newDistance = distanceToCurrent + edge.weight;
            if (newDistance < distances[edge.to]) {
                distances[edge.to] = newDistance;
                pq.push({newDistance, edge.to});
            }
        }
    }
}

int main() {
    int V, E, Q;
    cin >> V >> E >> Q;

    vector<vector<Edge>> graph(V);
    for (int i = 0; i < E; ++i) {
        int A, B, w;
        cin >> A >> B >> w;

        graph[A].push_back({B, w});
    }

    unordered_map<int, bool> flags(false);
    unordered_map<int, vector<int>> distances(V);
    for (int i = 0; i < Q; ++i) {
        int A, B;
        cin >> A >> B;

        if (!flags[A]) {
            dijkstra(graph, distances[A], A);
            flags[A] = true;
        }

        if (distances[A][B] == INT32_MAX) cout << -1 << '\n';
        else cout << distances[A][B] << '\n';
    }

    return 0;
}