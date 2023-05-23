#include <iostream>
#include <map>
using namespace std;

map<int, bool> pos;

int countShips(int N, int A) {
    int count = 0, k = 0;

    for (int i = 0; i < N; ++i) {
        if (k == A) {
            count++;
            k = 0;
        } else if (pos[i]) k++;
        else if (!pos[i]) k = 0;
    }

    if (k == A) count++;

    return count;
}

int main() {
    int N, K, A, Q;
    cin >> N >> K >> A >> Q;
    for (int i = 0; i < N; ++i)
        pos.insert({i, true});

    int x[Q];
    for (int i = 0; i < Q; ++i)
        cin >> x[i];

    int ans = 0;
    for (int i = 0; i < Q; ++i) {
        pos[x[i] - 1] = false;

        if (countShips(N, A) < K) {
            ans = i + 1;
            break;
        }
    }

    if (ans == 0) cout << "-1";
    else cout << ans;

    return 0;
}
