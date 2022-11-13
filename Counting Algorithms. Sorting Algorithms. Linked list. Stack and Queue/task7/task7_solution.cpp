#include <cmath>
#include <iostream>
using namespace std;

long long some_search(long long pos, long long size, long long depth) {
    if(size == 1)
        return depth;

    long long mid1 = size /3;
    long long mid2 = size *2 /3;

    if (pos > mid1 && pos <= mid2)
        return depth;
    else if (pos > mid2)
        return some_search(pos - mid2, size / 3, depth + 1);
    else if (pos <= mid1)
        return some_search(pos, size / 3, depth + 1);

    return 0;
}

int main() {
    long long p, n;
    cin >> p >> n;

    long long size = pow(3, p);
    long long invited;

    for (long long i = 0; i < n; i++) {
        cin >> invited;
        cout << some_search(invited, size, 1) << '\n';
    }

    return 0;
}
