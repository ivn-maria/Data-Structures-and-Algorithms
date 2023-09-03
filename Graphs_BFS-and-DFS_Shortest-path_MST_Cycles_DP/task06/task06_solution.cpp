#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <limits.h>
using namespace std;

const int MOD = 1000000007;

struct Node {
    int to;
    int weight;

    int operator>(const Node &other) const {
        return this->weight > other.weight;
    }
};

unordered_map<int, vector<Node>> graph;

long long dijkstra(int start, int end, int N) {
    vector<long long> distances(N, LLONG_MAX);
    vector<long long> paths(N, 0);

    distances[start] = 0;
    paths[start] = 1;

    priority_queue<Node, vector<Node>, greater<Node>> pq;
    pq.push({start, 0});

    while (!pq.empty()) {
        int current = pq.top().to;
        long long distanceToCurrent = pq.top().weight;
        pq.pop();

        if (distanceToCurrent > distances[current]) {
            continue;
        }

        for (const auto &edge: graph[current]) {
            int next = edge.to;
            long long distanceToNext = edge.weight;
            int nextTime = distances[current] + distanceToNext;

            if (distances[next] > nextTime) {
                distances[next] = nextTime;
                pq.push({next, nextTime});
            }

            if (distances[next] > distances[current]) {
                paths[next] += paths[current];
                paths[next] %= MOD;
            }
        }
    }

    return paths[end];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int V, E, start, end;
    cin >> V >> E >> start >> end;

    for (int i = 0; i < E; ++i) {
        int from, to, weight;
        cin >> from >> to >> weight;
        
        graph[from].push_back({to, weight});
        graph[to].push_back({from, weight});
    }

    cout << dijkstra(end, start, V);

    return 0;
}
