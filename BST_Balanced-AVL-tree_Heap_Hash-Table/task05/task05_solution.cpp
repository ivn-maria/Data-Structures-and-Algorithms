#include <iostream>
#include <set>
using namespace std;

int main() {
    int Q;
    cin >> Q;

    for (int i = 0; i < Q; ++i) {
        int N;
        cin >> N;

        unsigned long ans = 0;
        int flag = 0;
        auto *arr = new int [N];
        set<int> box;

        for (int j = 0; j < N; ++j) {
            int x;
            cin >> x;

            if (box.count(x) != 0) {
                if (box.size() > ans) ans = box.size();
                for (int k = flag; k < j; ++k) {
                    box.erase(arr[k]);
                    if (arr[k] == x) {
                        flag = k + 1;
                        break;
                    }
                }
            }

            box.insert(x);
            arr[j] = x;
        }

        if (box.size() > ans) ans = box.size();
        cout << ans << '\n';

        box.clear();
        delete[] arr;
    }

    return 0;
}