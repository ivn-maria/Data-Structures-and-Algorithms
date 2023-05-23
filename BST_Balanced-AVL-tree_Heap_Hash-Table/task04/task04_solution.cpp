#include <iostream>
#include <set>
using namespace std;

int main() {
    int n;
    cin >> n;

    set<long long> masks;
    for (int i = 0; i < n; i++) {
        long long a;
        cin >> a;

        for (long long s = a; s > 0; s = (s - 1) & a)
            if (!masks.count(s)) masks.insert(s);
    }

    cout << masks.size() + 1;

    return 0;
}
