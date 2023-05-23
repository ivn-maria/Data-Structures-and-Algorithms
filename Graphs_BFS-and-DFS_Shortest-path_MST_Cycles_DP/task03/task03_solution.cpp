#include <iostream>
#include <vector>
#include <list>
#include <set>
using namespace std;

void BFS(vector<set<int>> &graph, int start, int end, int N, int predecessor[], int distance[]) {
    list<int> queue;
    bool visited[N];
    for (int i = 0; i < N + 1; i++) {
        visited[i] = false;
        distance[i] = 2147483647;
        predecessor[i] = -1;
    }

    visited[start] = true;
    distance[start] = 0;
    queue.push_back(start);
    while (!queue.empty()) {
        int current = queue.front();
        queue.pop_front();

        for (int i = 1; i < N + 1; ++i) {
            if (i != start && !graph[current].count(i)) {
                if (!visited[i]) {
                    visited[i] = true;
                    distance[i] = distance[current] + 1;
                    predecessor[i] = current;
                    queue.push_back(i);

                    if (i == end) return;
                }
            }
        }
    }
}

void printShortestDistance(vector<set<int>> &graph, int start, int end, int N) {
    int predecessor[N], distance[N];
    BFS(graph, start, end, N, predecessor, distance);

    vector<int> path;
    int copy = end;
    path.push_back(copy);

    while (predecessor[copy] != -1) {
        path.push_back(predecessor[copy]);
        copy = predecessor[copy];
    }

    cout << distance[end] << ' ';
}

int main() {
    int Q;
    cin >> Q;

    for (int i = 0; i < Q; ++i) {
        int N, M;
        cin >> N >> M;

        vector<set<int>> graph(N + 1);
        for (int j = 0; j < M; ++j) {
            int from, to;
            cin >> from >> to;

            graph[from].insert(to);
            graph[to].insert(from);
        }

        int K;
        cin >> K;
        for (int j = 1; j < N + 1; ++j)
            if (j != K) printShortestDistance(graph, K, j, N);
        cout << '\n';
    }

    return 0;
}