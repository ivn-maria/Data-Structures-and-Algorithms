#include <iostream>
#include <climits>
#include <vector>
#include <queue>
using namespace std;

const int MOD = 1000000007;

struct Edge {
    int to;
    int weight;
};

void dijkstra(vector<vector<Edge>> &graph, vector<long long> &distances, int startNode) {
    distances = vector<long long>(graph.size(), LLONG_MAX);
    distances[startNode] = 0;

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
    pq.push({0, startNode});

    while (!pq.empty()) {
        int current = pq.top().second;
        long long distanceToCurrent = pq.top().first;
        pq.pop();

        for (auto const &edge : graph[current]) {
            long long newDistance = distanceToCurrent + edge.weight;
            if (newDistance < distances[edge.to]) {
                distances[edge.to] = newDistance;
                pq.push({newDistance, edge.to});
            }
        }
    }
}

void findAllPaths(vector<vector<Edge>> &graph, int start, int end, vector<bool> &visited, vector<long long> &dist,
            long long &counter,vector<long long> &path) {
    visited[start] = true;

    if (start == end) counter++;
    else {
        for (auto child : graph[start]) {
            if (!visited[child.to] && dist[start] > dist[child.to]) {
                path[child.to] = path[start];
                findAllPaths(graph, child.to, end, visited , dist, counter,path);
            }
        }
    }

    visited[start] = false;
}

int main() {
    int V, E, start, end;
    cin >> V >> E >> start >> end;

    vector<vector<Edge>> graph(V);

    for (int i = 0; i < E; i++) {
        int from, to, weight;
        cin >> from >> to >> weight;

        graph[from].push_back({to, weight});
        graph[to].push_back({from, weight});
    }

    vector<long long> distances;
    dijkstra(graph, distances, end);

    long long counter = 0;
    vector<bool> visited(graph.size(), false);
    vector<long long> path(graph.size());
    path[start] = 1;
    findAllPaths(graph, start, end, visited, distances, counter,path);

    cout << counter % MOD;

    return 0;
}