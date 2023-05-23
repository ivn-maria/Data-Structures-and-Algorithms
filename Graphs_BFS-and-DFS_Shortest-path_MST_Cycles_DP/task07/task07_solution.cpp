#include <iostream>
#include <vector>
#include <set>
using namespace std;

void dfs(vector<set<int>> &graph, vector<bool> &visited, int *&connectedComponents, int node,
         int component) {
    visited[node] = true;
    connectedComponents[node] = component;

    for (auto child : graph[node]) {
        if (!visited[child]) {
            dfs(graph, visited, connectedComponents, child, component);
        }
    }
}

void findConnectedComponents(vector<set<int>> &graph, int *&connectedComponents) {
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

    vector<set<int>> graph(N + 1);

    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;

        graph[a].insert(b);
        graph[b].insert(a);
    }

    int *connectedComponents = new int[N + 1];
    findConnectedComponents(graph, connectedComponents);

    int Q;
    cin >> Q;

    for (int i = 0; i < Q; ++i) {
        int type, start, end;
        cin >> type >> start >> end;

        if (type == 1) {
            if (connectedComponents[start] == connectedComponents[end]) cout << true;
            else cout << false;
        } else {
            graph[start].insert(end);
            graph[end].insert(start);

            if (connectedComponents[start] != connectedComponents[end])findConnectedComponents(graph, connectedComponents);
        }
    }

    return 0;
}