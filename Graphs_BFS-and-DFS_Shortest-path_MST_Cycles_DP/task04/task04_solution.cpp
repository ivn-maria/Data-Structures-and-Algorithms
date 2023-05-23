#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Edge {
    int from;
    int to;
    int weight;
};

void dijkstra(vector<vector<Edge>> &graph, vector<int> &distances, int startNode, vector<int> &times) {
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

            if (distanceToCurrent != 0) {
                int arrivalTime = 0;
                while (arrivalTime < distanceToCurrent) arrivalTime += times[edge.from];
                int addTime = arrivalTime - distanceToCurrent;
                newDistance += addTime;
            }

            if (newDistance < distances[edge.to]) {
                distances[edge.to] = newDistance;
                pq.push({newDistance, edge.to});
            }
        }
    }
}

int main() {
    int V, E, s, e;
    cin >> V >> E >> s >> e;

    vector<int> t(V);
    for (int i = 0; i < V; ++i) cin >> t[i];

    vector<vector<Edge>> graph(V);
    for (int i = 0; i < E; ++i) {
        int A, B, w;
        cin >> A >> B >> w;

        graph[A].push_back({A, B, w});
    }

    vector<int> distances;
    dijkstra(graph, distances, s, t);

    if (distances[e] == INT32_MAX) cout << -1;
    else cout << distances[e];

    return 0;
}