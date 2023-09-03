#include <iostream>
#include <climits>
#include <unordered_map>
#include <queue>
#include <set>
using namespace std;

unordered_map<int, set<int>> graph;

void BFS(int start, int N, int *dist) {
    queue<int> q;
    bool visited[N + 1];
    
    for (int i = 0; i <= N; ++i) {
        visited[i] = false;
        dist[i] = INT_MAX;
    }

    visited[start] = true;
    dist[start] = 0;
    q.push(start);
    
    int visitedCont = 1;

    while (!q.empty()) {
        if (visitedCont == N) break;

        int top = q.front();
        q.pop();
        
        for (int i = 1; i <= N; ++i) {
            if (!visited[i] && graph[top].find(i) == graph[top].end()) {
                visited[i] = true;
                dist[i] = min(dist[i], dist[top] + 1);
                q.push(i);
                visitedCont++;
            }
        }
    }
}

int main() {
    int Q;
    cin >> Q;

    for (int i = 0; i < Q; ++i) {
        int N, M;
        cin >> N >> M;

        for (int j = 0; j < M; ++j) {
            int from, to;
            cin >> from >> to;

            graph[from].insert(to);
            graph[to].insert(from);
        }

        int K;
        cin >> K;
        int dist[N + 1];
        BFS(K, N, dist);
        
        for (int j = 1; j < N + 1; ++j)
            if (j != K) cout << (dist[j] != INT_MAX ? dist[j] : -1) << " ";
        cout << '\n';
        
        graph.clear();
    }

    return 0;
}
