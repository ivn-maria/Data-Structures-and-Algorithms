#include <iostream>
#include <set>
using namespace std;

int main() {
    int n, k, a, q;
    cin >> n >> k >> a >> q;
    
    set<int> shots;
    shots.insert(0);
    shots.insert(n + 1);

    int ans = -1;
    int maxShips = (n + 1) / (a + 1);

    for (int i = 1; i <= q; i++) {
        int idx;
        cin >> idx;

        auto firstLower = shots.lower_bound(idx);
        firstLower--;
        auto firstHigher = shots.upper_bound(idx);
        
        shots.insert(idx);

        int countShips = maxShips;

        countShips -= ((*firstHigher - *firstLower) / (a + 1));
        countShips += ((idx - *firstLower) / (a + 1));
        countShips += ((*firstHigher - idx) / (a + 1));

        maxShips = countShips;

        if (countShips < k) {
            ans = i;
            break;
        }

    }

    cout << ans;

    return 0;
}
