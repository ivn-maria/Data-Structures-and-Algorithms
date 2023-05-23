#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<int>> &graph, vector<bool> &visited, int *&connectedComponents, int node,
         int component) {
    visited[node] = true;
    connectedComponents[node] = component;

    for (auto child : graph[node]) {
        if (!visited[child]) {
            dfs(graph, visited, connectedComponents, child, component);
        }
    }
}

void findConnectedComponents(vector<vector<int>> &graph, int *&connectedComponents) {
    vector<bool> visited(graph.size(), false);
    int component = 1;
    for (int i = 1; i < graph.size(); ++i) {
        if (!visited[i]) {
            connectedComponents[i] = int();
            dfs(graph, visited, connectedComponents, i, component);
            component++;
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> graph(N + 1);

    for (int i = 0; i < M; ++i) {
        int from, to;
        cin >> from >> to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }

    int *connectedComponents = new int[N];
    findConnectedComponents(graph, connectedComponents);

    int K;
    cin >> K;
    for (int i = 0; i < K; ++i) {
        int start, end;
        cin >> start >> end;

        if (connectedComponents[start] == connectedComponents[end]) cout << true << ' ';
        else cout << false << ' ';
    }

    return 0;
}