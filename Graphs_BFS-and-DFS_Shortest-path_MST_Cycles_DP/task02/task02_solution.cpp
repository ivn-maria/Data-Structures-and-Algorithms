#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

string topologicalSort(unordered_map<char, vector<char>> graph, string words[]) {
    queue<char> q;
    unordered_map<char, int> inDegree;
    string ans;

    for (const auto& i: graph) {
        for (char x: graph[i.first]) {
            inDegree[x]++;
            inDegree[i.first] += 0;
        }
    }

    for (auto i: inDegree)
        if (i.second == 0) q.push(i.first);

    while (!q.empty()) {
        char n = q.front();
        q.pop();
        ans.push_back(n);

        for (int x: graph[n]) {
            inDegree[x]--;
            if (inDegree[x] == 0) q.push(x);
        }
    }

    if (ans.empty()) ans.push_back(words[0][0]);

    return ans;
}

int main() {
    int N;
    cin >> N;
    cin.ignore();
    string words[N];
    for (int i = 0; i < N; ++i)
        getline(cin, words[i]);

    unordered_map<char, vector<char>> graph;
    for (int i = 0; i < N - 1; i++) {
        int M = min(words[i].size(), words[i + 1].size());
        for (int j = 0; j < M; j++) {
            if (words[i][j] != words[i + 1][j]) {
                graph[words[i][j]].push_back(words[i + 1][j]);
                break;
            }
        }
    }
    string alphabet = topologicalSort(graph, words);

    for (int i = 0; alphabet[i] != '\0'; ++i)
        cout << alphabet[i] << ' ';

    return 0;
}