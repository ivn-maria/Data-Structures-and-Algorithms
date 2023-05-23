#include <iostream>
#include <iomanip>
#include <set>
using namespace std;

void findMedian(int arr[], int N) {
    multiset<int> g;
    multiset<int, greater<> > s;

    s.insert(arr[0]);
    int med = arr[0];
    double ans = arr[0];
    cout << fixed << showpoint;
    cout << setprecision(1);
    cout << ans << '\n';

    for (int i = 1; i < N; i++) {
        if (s.size() > g.size()) {
            if (arr[i] < med) {
                int temp = *s.begin();
                s.erase(s.begin());
                g.insert(temp);
                s.insert(arr[i]);
            } else g.insert(arr[i]);

            med = *s.begin() > *g.begin() ? *g.begin() : *s.begin();
            ans = (*g.begin() + *s.begin()) / 2.0;
        } else if (s.size() < g.size()) {
            if (arr[i] > med) {
                int temp = *g.begin();
                g.erase(g.begin());
                s.insert(temp);
                g.insert(arr[i]);
            } else s.insert(arr[i]);

            med = *s.begin() > *g.begin() ? *g.begin() : *s.begin();
            ans = (*g.begin() + *s.begin()) / 2.0;
        } else {
            if (arr[i] > med) {
                g.insert(arr[i]);
                med = *g.begin();
            } else {
                s.insert(arr[i]);
                med = *s.begin();
            }
            ans = med;
        }

        cout << fixed << showpoint;
        cout << setprecision(1);
        cout << ans << '\n';
    }
}

int main() {
    int N;
    cin >> N;

    int arr[N];
    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        arr[i] = a;
    }
    findMedian(arr, N);

    return 0;
}

