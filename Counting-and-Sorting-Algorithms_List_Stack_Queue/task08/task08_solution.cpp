#include <iostream>
#include <algorithm>
using namespace std;

long long binary_search_min(long long* arr, long long x, long long start, long long end) {
    if (start > end)
        return start;

    long long middle = (end + start) / 2;

    if (arr[middle] == x && (middle == start || arr[middle - 1] < x))
        return middle;
    else if ((arr[middle] == x && arr[middle - 1] == x) || arr[middle] > x)
        return binary_search_min(arr, x, start, middle - 1);
    else if (arr[middle] < x)
        return binary_search_min(arr, x, middle + 1, end);

    return middle;
}

long long binary_search_max(long long* arr, long long x, long long start, long long end) {
    if (start > end)
        return end;

    long long middle = (end + start) / 2;

    if (arr[middle] == x && (middle == end || arr[middle + 1] > x))
        return middle;
    else if (arr[middle] > x)
        return binary_search_max(arr, x, start, middle - 1);
    else if ((arr[middle] == x && arr[middle + 1] == x) || arr[middle] < x)
        return binary_search_max(arr, x, middle + 1, end);

    return end;
}

int main() {
    long long n, q;
    cin >> n >> q;

    long long arr[n];
    for (long long i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr, arr + n);

    long long min, max, count = 0, minpos, maxpos;
    for (long long i = 0; i < q; i++) {
        cin >> min >> max;
        minpos = binary_search_min(arr, min, 0, n - 1);
        maxpos = binary_search_max(arr, max, 0, n - 1);

        for (long long j = minpos; j <= maxpos; j++)
            count++;

        cout << count << '\n';
        count = 0;
    }

    return 0;
}
